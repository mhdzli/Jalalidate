/*
	funcs.h


	This file is part of JDate project.
	JDate is a persian jalali calendar date tool for GNU command line. 

	JDate is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	JDate is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef _FUNCS_H
#define _FUNCS_H


void print_error (char *error_msg, int error_code)
{
	fprintf(stderr, "Error %02d: %s\n", error_code, error_msg);
	exit(EXIT_FAILURE);
}


jDate get_cur_gdate (void)
{
	jDate gd;
	gd.day   = malloc(sizeof(char*));
	gd.month = malloc(sizeof(char*));
	gd.year  = malloc(sizeof(char*));	

	time_t rawtime = time(NULL);
	
	strftime(gd.day,   sizeof(gd.day),   "%d", localtime(&rawtime));
	strftime(gd.month, sizeof(gd.month), "%m", localtime(&rawtime));
	strftime(gd.year,  sizeof(gd.year),  "%Y", localtime(&rawtime));
	
	return gd;
}


jDate get_cur_jdate (void)
{
	jDate jd;
	jd.day   = malloc(sizeof(char*));
	jd.month = malloc(sizeof(char*));
	jd.year  = malloc(sizeof(char*));
	
	jd = get_cur_gdate();
	
	return gregorian_to_jalali(atoi(jd.year), atoi(jd.month), atoi(jd.day));
}


void print_jdate (jDate jd, char *fmt)
{
	int l = 0, i = 0, day_of_year = 0, weekday = 0, week_number = 0;
	char *buf = malloc(sizeof(char) * 4096);
	
	buf[0] = '\0';
	
	
	
	day_of_year = 0;
	for (i = 0; i < atoi(jd.month) - 1; i++) {
		day_of_year += j_days_in_month[i];
	}
	
	day_of_year += atoi(jd.day);
	weekday      = (day_of_year % 7) + 1;
	week_number  = _div(day_of_year, 7) + 1;

	while (l < strlen(fmt)) {
	
		if (fmt[l] == '%') {
			switch (fmt[l+1]) {
				case 'a':
					buf = _strconcat(buf, persian_weekday_abbreviation_name(weekday));
					break;
				
				case 'A':
					buf = _strconcat(buf, persian_weekday_name(weekday));
					break;
				
				case 'B':
					buf = _strconcat(buf, persian_month_name(atoi(jd.month)));
					break;
				
				case 'd':
					buf = _strconcat(buf, jd.day);
					break;
				
				case 'D':
					if (atoi(jd.day) < 10) {
						buf = _append(buf, '0');
					}
				
					buf = _strconcat(buf, jd.day);
					break;
				
				case 'm':
					buf = _strconcat(buf, jd.month);
					break;
				
				case 'M':
					if (atoi(jd.month) < 10) {
						buf = _append(buf, '0');
					}
				
					buf = _strconcat(buf, jd.month);
					break;
				
				case 'y':
					if (atoi(jd.year) < 10) {
						buf = _append(buf, '0');
					}
	
					buf = _strconcat(buf, _substring(jd.year, 2, 2));
					break;
				
				case 'Y':
					buf = _strconcat(buf, jd.year);
					break;
				
				case 'j':
					buf = _strconcat(buf, _inttostr(day_of_year));
					break;
				
				case 'u':
					buf = _strconcat(buf, _inttostr(weekday));
					break;
				
				case 'U':
					buf = _strconcat(buf, _inttostr(week_number));
					break;
				
				default:
					buf = _append(buf, fmt[l]);
					break;
			}
			l++;
			
		} else {
			buf = _append(buf, fmt[l]);
		}
		
		l++;
	}
	
	puts(buf);
}


jDate compare_jdate (char *str)
{
	jDate j;
	
	int tmp_year1, tmp_year2,
	tmp_month1, tmp_month2,
	tmp_day1, tmp_day2;
	
	boolean compare_condition = false;
	
	tmp_year1  = atoi(_substring(str,  0, 4));
	tmp_month1 = atoi(_substring(str,  5, 2));
	tmp_day1   = atoi(_substring(str,  8, 2));
	
	tmp_year2  = atoi(_substring(str, 11, 4));
	tmp_month2 = atoi(_substring(str, 16, 2));
	tmp_day2   = atoi(_substring(str, 19, 2));

	if (tmp_year1 == tmp_year2) {
		if (tmp_month1 == tmp_month2) {
			if (tmp_day1 == tmp_day2) {
				compare_condition = true;
			} else if (tmp_day1 > tmp_day2) {
				compare_condition = true;
			} else if (tmp_day1 < tmp_day2) {
				compare_condition = false;
			}
		} else if (tmp_month1 > tmp_month2) {
			compare_condition = true;
		} else if (tmp_month1 < tmp_month2) {
			compare_condition = false;
		}
	} else if (tmp_year1 > tmp_year2) {
		compare_condition = true;
	} else if (tmp_year1 < tmp_year2) {
		compare_condition = false;
	}
	
	if (compare_condition) {
		j.year  = _inttostr(tmp_year1);
		j.month = _inttostr(tmp_month1);
		j.day   = _inttostr(tmp_day1);
	} else {
		j.year  = _inttostr(tmp_year2);
		j.month = _inttostr(tmp_month2);
		j.day   = _inttostr(tmp_day2);
	}
	
	return j;
}


int jdate_difference (char *str)
{
	jDate jd;
	
	int tmp_year1,  tmp_year2,
	    tmp_month1, tmp_month2,
	    tmp_day1,   tmp_day2;
	
	tmp_year1  = atoi(_substring(str,  0, 4));
	tmp_month1 = atoi(_substring(str,  5, 2));
	tmp_day1   = atoi(_substring(str,  8, 2));
	
	tmp_year2  = atoi(_substring(str, 11, 4));
	tmp_month2 = atoi(_substring(str, 16, 2));
	tmp_day2   = atoi(_substring(str, 19, 2));
	
	jd.year  = _inttostr(tmp_year1);
	jd.month = _inttostr(tmp_month1);
	jd.day   = _inttostr(tmp_day1);
	
	//TODO
	
	return 0;
}


jDate file_modification_date (char *filename)
{
	jDate jd;
	jd.day   = malloc(sizeof(char*));
	jd.month = malloc(sizeof(char*));
	jd.year  = malloc(sizeof(char*));
	
	struct tm *foo;
	struct stat attrib;

	stat(filename, &attrib);
	
	strftime(jd.day,   sizeof(jd.day),   "%d", localtime(&(attrib.st_ctime)));
	strftime(jd.month, sizeof(jd.month), "%m", localtime(&(attrib.st_ctime)));
	strftime(jd.year,  sizeof(jd.year),  "%Y", localtime(&(attrib.st_ctime)));	
	
	return gregorian_to_jalali(atoi(jd.year), atoi(jd.month), atoi(jd.day));
}


#endif //_FUNCS_H

