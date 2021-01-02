#ifndef _jalali_INCLUDED_
#define _jalali_INCLUDED_

struct Date
{
    unsigned int Year;
    unsigned char Month;
    unsigned char Day;
};

void Jalali_to_Gregorian(struct Date JAdate, struct Date *GRdate);
void Gregorian_to_Jalali(struct Date GRdate, struct Date *JAdate);

#endif