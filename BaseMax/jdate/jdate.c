/**
*
* @Name : jdate.c
* @Version : 1.0
* @Programmer : Max
* @Date : 2020-04-04
* @Released under : https://github.com/BaseMax/jdate/blob/master/LICENSE
* @Repository : https://github.com/BaseMax/jdate
* @Related: https://github.com/BaseMax/ConvertCalendar
* 			https://github.com/BaseMax/JavaJalaliCalendar
*
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	// We can use the uint8_t type.
	int year;
	int month;
	int day;

	char *monthName;
	int dayIndex;
	char *dayName;
} date;

#ifndef bool
typedef enum {
	false,
	true,
} bool;
#endif

bool isLeapYear(int year){
	return year%4==3 ? true : false;
}

int daysOfMonth(int year, int month) {
	if(month > 12 || month < 1) {
		return 0;
	}
	// 1-6 : max is 31           / Total ==> 6*31=186
	// 7-11: max is 30           / Total ==> 5*30=150
	// 12: leap:30 else 29       / Total ==> 30 or 29
	// A year is 365 or 366 day
	if(month >=1 && month<=6) {
		return 31;
	}
	else if(month >=7 && month <=11) {
		return 30;
	}
	else if(month == 12) {
		if(isLeapYear(year) == true) {
			return 30;
		}
		return 29;
	}
	return 0;
}

int daysOfYear(int year) {
	// A year is 365 or 366 day
	if(isLeapYear(year)) {
		return 366;
	}
	return 365;
//        int sum=0;
//        for(int i=1;i<=12;i++) {
//            sum+=daysOfMonth(year, i);
//        }
//        return sum;
}

int daysOfYearUntilMonth(int year, int maxMonth) {
	if(maxMonth >= 1 && maxMonth <=12) {
		int sum=0;
		for(int i=1;i<=maxMonth;i++) {
			sum+=daysOfMonth(year, i);
		}
		return sum;
	}
	return 0;
}

int daysOfYearUntilDay(int year, int maxDay) {
	if(maxDay >= 1 &&
			(
					(isLeapYear(year) && maxDay <=366) || !isLeapYear(year) && maxDay <= 365
			)
	) {
		int sum = 0;
		for (int i = 1; i <= 12; i++) {
			int temp = daysOfMonth(year, i);
			if(sum + temp <= maxDay) {
				sum += temp;
			}
			else {
				break;
			}
		}
		return sum;
	}
	return 0;
}

date gregorian2jalali(date input) {
	date result;
	int array[]={0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	if(input.year<=1600) {
		input.year-=621;
		result.year=0;
	}
	else {
		input.year-=1600;
		result.year=979;
	}
	int temp=(input.year>2)?(input.year+1):input.year;
	int days=((int)((temp+3)/4)) + (365*input.year) - ((int)((temp+99)/100)) - 80 + array[input.month-1] + ((int)((temp+399)/400)) + input.day;
	result.year+=33*((int)(days/12053)); 
	days%=12053;
	result.year+=4*((int)(days/1461));
	days%=1461;
	if(days > 365){
		result.year+=(int)((days-1)/365);
		days=(days-1)%365;
	}
	result.month=(days < 186)?1+(int)(days/31):7+(int)((days-186)/30);
	result.day=1+((days < 186)?(days%31):((days-186)%30));
	return result;
}

date jalali2gregorian(date input) {
	date result; //g*
	if(input.year<=979) {
		result.year=621;
	}
	else {
		input.year-=979;
		result.year=1600;
	}
	int temp=(((int)(input.year/33))*8) + ((int)(((input.year%33)+3)/4)) + (365*input.year) + 78 + input.day + ((input.month<7)?(input.month-1) * 31 : ((input.month - 7) * 30) + 186);
	result.year+=400*((int)(temp/146097));
	temp%=146097;
	if(temp > 36524) {
		result.year+=100*((int)(--temp/36524));
		temp%=36524;
		if(temp >= 365)
			temp++;
	}
	result.year+=4*((int)(temp/1461));
	temp%=1461;
	if(temp > 365) {
		result.year+=(int)((temp-1)/365);
		temp=(temp-1)%365;
	}
	result.day=temp + 1;
	int array[]={0, 31, ((result.year%4==0 && result.year%100!=0) || (result.year%400==0))?29:28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int length=sizeof(array)/sizeof(array[0]);
	for(int index=0;index<length;index++) {
		result.month=index;
		if(result.day<=array[index])
			break;
		result.day-=array[index];
	}
	return result;
}

void diaply(date input) {
	printf("%d/%d/%d - %s - %s\n\n",
		input.year,
		input.month,
		input.day,
		input.monthName != NULL ? input.monthName : "",
		input.dayName != NULL ? input.dayName : ""
	);
}

bool biggerThen(date a, date b) {
	// a is bigger then b?
	if(a.year > b.year) {
		return true;
	}
	else if(a.year == b.year && a.month > b.month) {
		return true;
	}
	else if(a.year == b.year && a.month == b.month && a.day == b.day) {
		return true;
	}
	else {
		return false;
	}
	// return false;
}

int diffDate(date a, date b) {
	// a <= b
	// else swipe
	if(biggerThen(a, b)) {
		date t=a;
		a=b;
		b=t;
	}
	int days=0;
	if(a.year != b.year) {
		// printf(" - year not same!\n");
		for(int i=a.month;i<=12;i++) {
			int r=daysOfMonth(a.year, i);
			// printf("day(%d,%d) = %d\n", a.year, i , r);
			days+=r;
		}
		// printf("day: %d\n", days);
		days-=a.day;
		// printf("day: %d\n", days);
		a.month=1;
	}
	if(a.month != b.month) {
		// printf(" - month not same!\n");
		for(int i=a.month;i<b.month;i++) {
			days+=daysOfMonth(a.year, i);
		}
	}
	days+=b.day;
	return days;
}

date prepareDate(date input) {
	date res=input;
	switch(input.month) {
		case 1:
			res.monthName = "فروردين";
			break;
		case 2:
			res.monthName = "ارديبهشت";
			break;
		case 3:
			res.monthName = "خرداد";
			break;
		case 4:
			res.monthName = "تير";
			break;
		case 5:
			res.monthName = "مرداد";
			break;
		case 6:
			res.monthName = "شهريور";
			break;
		case 7:
			res.monthName = "مهر";
			break;
		case 8:
			res.monthName = "آبان";
			break;
		case 9:
			res.monthName = "آذر";
			break;
		case 10:
			res.monthName = "دي";
			break;
		case 11:
			res.monthName = "بهمن";
			break;
		case 12:
			res.monthName = "اسفند";
			break;
	}
	// date target={1399, 01, 01, "فروردین", 7};
	date target={1398, 12, 15, "پنج شنبه", 6};
	int days=diffDate(target, res);
	// int days=diffDate(res, target);
	// printf("Diff: %d\n", days);
	res.dayIndex=target.dayIndex + days;
	res.dayIndex=res.dayIndex % 7;
	if(res.dayIndex == 0) {
		res.dayIndex=7;
	}
	switch(res.dayIndex) {
		case 1:
			res.dayName = "شنبه";
			break;
		case 2:
			res.dayName = "يکشنبه";
			break;
		case 3:
			res.dayName = "دوشنبه";
			break;
		case 4:
			res.dayName = "سه شنبه";
			break;
		case 5:
			res.dayName = "چهارشنبه";
			break;
		case 6:
			res.dayName = "پنج شنبه";
			break;
		case 7:
			res.dayName = "جمعه";
			break;
	}
	return res;
}

char *execute(char *command) {
	FILE *fd;
	fd = popen(command, "r");
	if(!fd)
		return "";
	char buffer[256];
	size_t chread;
	size_t comalloc = 256;
	size_t comlen   = 0;
	char  *comout   = malloc(comalloc);
	while ((chread = fread(buffer, 1, sizeof(buffer), fd)) != 0) {
		if(comlen + chread >= comalloc) {
			comalloc *= 2;
			comout = realloc(comout, comalloc);
		}
		memmove(comout + comlen, buffer, chread);
		comlen += chread;
	}
	return comout;
	fwrite(comout, 1, comlen, stdout);
	free(comout);
}

void check(int year, int month, int day) {
	if(year == 0 || month == 0 || day == 0) {
		printf("Error!\n");
		return;
	}
	date input;
	input.year=year;
	input.month=month;
	input.day=day;
	// printf("Hello!\n");
	// printf("%d/%d/%d\n", input.year, input.month, input.day);
	input=gregorian2jalali(input);
	input=prepareDate(input);
	printf("%d/%d/%d - %s - %s\n", input.year, input.month, input.day, input.monthName, input.dayName);
}

int main(int argc, char** argv) {
	if(argc > 3) {
		check(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	}
	else if(argc == 2 && strcmp(argv[1], "--auto") == 0) {
		check(atoi(execute("date '+\%Y'")), atoi(execute("date '+\%m'")), atoi(execute("date '+\%d'")));
	}
	return 0;
}
