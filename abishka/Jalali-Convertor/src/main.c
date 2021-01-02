#include <stdio.h>
#include "jalali.h"

int main()
{
	int type;
	struct Date Gdate;
	struct Date Jdate;

	printf("please select converter type ( 1 or 2 ) \n");
	printf("1- Gregorian_to_Jalali Enter 1 \n");
	printf("2- Jalali_to_Gregorian Enter 2 \n");
	printf("\n type is : ");
	scanf("%d", &type);

	if (type == 1)
	{
		printf("\n  ");
		printf(" you select Gregorian to Jalali");
	}
	else if (type == 2)
	{
		printf("\n  ");
		printf(" you select Jalali_to_Gregorian");
	}
	else
	{
		printf("\n  ");
		printf(" not valid ");
		return 0;
	}

	if (type == 1)
	{

		printf("\nplease input year :");

		scanf("%d", &Gdate.Year);
		printf("\nplease input Month :");

		scanf("%d", &Gdate.Month);
		printf("\nplease input Day :");

		scanf("%d", &Gdate.Day);

		Gregorian_to_Jalali(Gdate, &Jdate);

		printf("Jdate.Year= %d\n", Jdate.Year);
		printf("Jdate.Month= %d\n", Jdate.Month);
		printf("Jdate.Day= %d\n", Jdate.Day);
	}
	else if (type == 2)
	{
		printf("\nplease input year :");

		scanf("%d", &Jdate.Year);
		printf("\nplease input Month :");

		scanf("%d", &Jdate.Month);
		printf("\nplease input Day :");

		scanf("%d", &Jdate.Day);

		Jalali_to_Gregorian(Jdate, &Gdate);

		printf("Gdate.Year= %d\n", Gdate.Year);
		printf("Gdate.Month= %d\n", Gdate.Month);
		printf("Gdate.Day= %d\n", Gdate.Day);
	}

	return 0;
}
