#include "jalali.h"
#include <stdio.h>

void Jalali_to_Gregorian(struct Date JAdate, struct Date *GRdate)
{
    /*
	Gregorian_mounth_no[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	Jalali_Month_no[13]={0, 31, 31, 31, 33, 31, 30, 30, 30, 30, 30, 30, 29};
*/
    unsigned long int tmp_year;
    unsigned char sal_a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    JAdate.Year += 1595;
    long days = -355668 + (365 * JAdate.Year) + (((JAdate.Year / 33)) * 8) +
                ((((JAdate.Year % 33) + 3) / 4)) + JAdate.Day + ((JAdate.Month < 7) ? (JAdate.Month - 1) * 31 : ((JAdate.Month - 7) * 30) + 186);

    tmp_year = 400 * ((int)(days / 146097));
    days %= 146097;
    if (days > 36524)
    {
        tmp_year += 100 * ((int)(--days / 36524));
        days %= 36524;
        if (days >= 365)
            days++;
    }
    tmp_year += 4 * ((int)(days / 1461));
    days %= 1461;
    if (days > 365)
    {
        tmp_year += (int)((days - 1) / 365);
        days = (days - 1) % 365;
    }
    if ((tmp_year % 4 == 0 && tmp_year % 100 != 0) || (tmp_year % 400 == 0))
        sal_a[2] = 29;
    GRdate->Year = tmp_year;
    tmp_year = days + 1;

    for (GRdate->Month = 0; GRdate->Month < 13 && tmp_year > sal_a[GRdate->Month]; GRdate->Month++)
        tmp_year -= sal_a[GRdate->Month];
    GRdate->Day = tmp_year;
}
void Gregorian_to_Jalali(struct Date GRdate, struct Date *JAdate)
{
    unsigned int cnt_deys[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    unsigned long int tmp_year = GRdate.Year;
    if (GRdate.Month > 2)
    {
        tmp_year = GRdate.Year + 1;
    }
    unsigned long days = 355666 + (365 * GRdate.Year) + ((tmp_year + 3) / 4) - ((tmp_year + 99) / 100) + ((tmp_year + 399) / 400) + cnt_deys[GRdate.Month - 1] + GRdate.Day;

    tmp_year = -1595 + (33 * (days / 12053));
    days %= 12053;
    tmp_year += 4 * (days / 1461);
    days %= 1461;

    if (days > 365)
    {
        tmp_year += ((days - 1) / 365);
        days = (days - 1) % 365;
    }

    JAdate->Year = tmp_year;

    if (days < 186)
    {
        JAdate->Month /*jm*/ = 1 + (int)(days / 31);
        JAdate->Day = 1 + (days % 31);
    }
    else
    {
        JAdate->Month = 7 + ((days - 186) / 30);
        JAdate->Day = 1 + ((days - 186) % 30);
    }
}
