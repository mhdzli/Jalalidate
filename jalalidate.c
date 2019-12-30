//Source: Forum.Ustmb.Ir
//MainSource: http://www.farsiweb.info/jalali/jalali.c
 
void gregorian_to_jalali(/* output */ int *j_y, int *j_m, int *j_d, /*  input */ int  g_y, int  g_m, int  g_d);
void jalali_to_gregorian(/* output */ int *g_y, int *g_m, int *g_d,/*  input */ int  j_y, int  j_m, int  j_d);
 
//For TC++ use commented liberaries
#include <stdio.h>
#include <iostream>//<iostream.h>
#include <cstdlib>//<stdlib.h>
#include <ctime>//<time.h>

int g_days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int j_days_in_month[12] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};
const char *j_month_name[13] = {"",
                                "Farvardin", "Ordibehesht", "Khordad",
                                "Tir", "Mordad", "Shahrivar",
                                "Mehr", "Aban", "Azar",
                                "Dey", "Bahman", "Esfand"};

//Gregorian to jalali function:
void gregorian_to_jalali(int *j_y, int *j_m, int *j_d,
                         int  g_y, int  g_m, int  g_d)
{
   int gy, gm, gd;
   int jy, jm, jd;
   long g_day_no, j_day_no;
   int j_np;
  
   int i;
 
   gy = g_y-1600;
   gm = g_m-1;
   gd = g_d-1;
  
   g_day_no = 365*gy+(gy+3)/4-(gy+99)/100+(gy+399)/400;
   for (i=0;i<gm;++i)
      g_day_no += g_days_in_month[i];
   if (gm>1 && ((gy%4==0 && gy%100!=0) || (gy%400==0)))
      /* leap and after Feb */
      ++g_day_no;
   g_day_no += gd;
  
   j_day_no = g_day_no-79;
  
   j_np = j_day_no / 12053;
   j_day_no %= 12053;
  
   jy = 979+33*j_np+4*(j_day_no/1461);
   j_day_no %= 1461;
  
   if (j_day_no >= 366) {
      jy += (j_day_no-1)/365;
      j_day_no = (j_day_no-1)%365;
   }
  
   for (i = 0; i < 11 && j_day_no >= j_days_in_month[i]; ++i) {
      j_day_no -= j_days_in_month[i];
   }
   jm = i+1;
   jd = j_day_no+1;
   *j_y = jy;
   *j_m = jm;
   *j_d = jd;
}
//Jalali to gregorian function
void jalali_to_gregorian(int *g_y, int *g_m, int *g_d,
                         int  j_y, int  j_m, int  j_d)
{
   int gy, gm, gd;
   int jy, jm, jd;
   long g_day_no, j_day_no;
   int leap;
 
   int i;
 
   jy = j_y-979;
   jm = j_m-1;
   jd = j_d-1;
 
   j_day_no = 365*jy + (jy/33)*8 + (jy%33+3)/4;
   for (i=0; i < jm; ++i)
      j_day_no += j_days_in_month[i];
 
   j_day_no += jd;
 
   g_day_no = j_day_no+79;
 
   gy = 1600 + 400*(g_day_no/146097); /* 146097 = 365*400 + 400/4 - 400/100 + 400/400 */
   g_day_no = g_day_no % 146097;
 
   leap = 1;
   if (g_day_no >= 36525) /* 36525 = 365*100 + 100/4 */
   {
      g_day_no--;
      gy += 100*(g_day_no/36524); /* 36524 = 365*100 + 100/4 - 100/100 */
      g_day_no = g_day_no % 36524;
       
      if (g_day_no >= 365)
         g_day_no++;
      else
         leap = 0;
   }
 
   gy += 4*(g_day_no/1461); /* 1461 = 365*4 + 4/4 */
   g_day_no %= 1461;
 
   if (g_day_no >= 366) {
      leap = 0;
 
      g_day_no--;
      gy += g_day_no/365;
      g_day_no = g_day_no % 365;
   }
 
   for (i = 0; g_day_no >= g_days_in_month[i] + (i == 1 && leap); i++)
      g_day_no -= g_days_in_month[i] + (i == 1 && leap);
   gm = i+1;
   gd = g_day_no+1;
 
   *g_y = gy;
   *g_m = gm;
   *g_d = gd;
}
 
int main(void)
{
   int y, m, d;
   time_t bin_time;
   struct tm *br_time;
 
   time(&bin_time);
   br_time = localtime(&bin_time); 
 
   gregorian_to_jalali(&y, &m, &d,1900+br_time->tm_year, 1+br_time->tm_mon, br_time->tm_mday);
 
   printf("%d %s %d\n", d, j_month_name[m], y); //For C uncomment this line.
 
   //For TC++ uncomment this line:
   //std::cout<<"Tarikhe Emrooz: "<< d<<" "<<  j_month_name[m] <<" "<<y<<std::endl;
   //getchar();
   return 0;
}
