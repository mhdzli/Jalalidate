/*
	helper.h


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


#ifndef _HELPER_H
#define _HELPER_H

#define boolean unsigned short int
#define true    1
#define false   0

int _div (int a, int b)
{
	return ((int)(a / b));
}


char *_inttostr (int a) {
	char *str = malloc(sizeof(char)*20);
	sprintf(str, "%d", a);
	
	return str;
}


char *_strconcat (char *s1, const char *s2)
{
	char *result = malloc(sizeof(s1) + sizeof(s2) + 1);
	
	strcpy(result, s1);
	strcat(s1, s2);
	
	return s1;
}


char *_append (const char *s, char c) {
    int len = strlen(s);
    char buf[len+2];
    
    strcpy(buf, s);
    buf[len] = c;
    buf[len + 1] = 0;
    
    return strdup(buf);
}


char *_substring (char s[], int p, int l)
{
   int c = 0;
   char *sub =  malloc(strlen(s) + 1);
 
   while (c < l) {
      sub[c++] = s[p + c - 1];
   }
   
   sub[c] = '\0';
   
   return sub;
}


int file_exist (const char *filename) {
    struct stat st;
    int result = stat(filename, &st);
    return result == 0;
}


#endif //_HELPER_H

