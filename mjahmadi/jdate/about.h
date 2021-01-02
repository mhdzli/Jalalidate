/*
	about.h


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


#ifndef _ABOUT_H
#define _ABOUT_H


void print_version (void)
{
	printf ("%s %s\n"
			"Copyright (C) 2016.\n"
			"This is free software; see the source for copying conditions."
			"There is \nNO warranty; not even for MERCHANTABILITY or FITNESS"
			"FOR A PARTICULAR PURPOSE.\n", PROGRAM_NAME, VERSION);
			
	printf ("Written by Mohammad Javad Ahmadi.\n");
	
	exit(EXIT_SUCCESS);
}


void print_usage(FILE* stream, int exit_code)
{
	if (exit_code == EXIT_SUCCESS) {
		fprintf (stream, "Display persian date in jalali calendar command line tool.\n");
		fprintf (stream, "Usage: %s [OPTION]... [+FORMAT]\n", PROGRAM_NAME);
	} else {
		fprintf (stream, "Try '%s --help' for more information.\n", PROGRAM_NAME);
	}
	
	if (exit_code == EXIT_SUCCESS) {
		fprintf (stream,
				"  -f   --format           Formats output with the given pattern.\n"
				"  -j   --to-jalali        Converts given gregorian date to persian jalali date.\n"
				"                          The format must be like this: 'YYYY-MM-DD'\n"
				"  -g   --to-gregorian     Converts given persian jalali date to gregorian date.\n"
				"                          The format must be like this: 'YYYY-MM-DD'\n"
				"  -c   --compare          Will compare two different persian jalali date.\n"
				"                          this option returns the bigger date.\n"
				"                          The format must be like this: 'YYYY-MM-DD:YYYY-MM-DD'\n"
				"  -r   --reference        Display the last modification time of FILE in jalali date.\n"
				/*TODO
				"  -d   --difference       Returns the number of days between two persian jalali date.\n"
				"                          The format must be like this: 'YYYY-MM-DD:YYYY-MM-DD'\n"
				*/
				"       --help             Display this usage information and exit.\n"
				"       --version          Output version information and exit.\n\n"
				
				"FORMAT controls the output. Interpreted sequences are:\n"
				"  '%%a'   locale's abbreviated weekday name.\n"
				"  '%%A'   locale's full weekday name.\n"
				"  '%%B'   locale's full month name.\n"
				"  '%%d'   day of month (e.g., 14).\n"
				"  '%%D'   day of month with leading zero (e.g., 05).\n"
				"  '%%m'   month (1..12).\n"
				"  '%%M'   month with leading zero (01..12).\n"
				"  '%%y'   Two digit year with leading zero.\n"
				"  '%%Y'   Four digit year.\n"
				"  '%%j'   day of year (1..366).\n"
				"  '%%u'   day of week (1..7).\n"
				"  '%%U'   week number of year.\n\n"
				
				"Examples:\n"
				"   To get current persian jalali date issue the following:\n\n"
				"   $ %s \n\n"
				
				"   To convert persian jalali date to gregorian date issue the following:\n\n"
				"   $ %s -g '1395-09-20'\n\n"
				
				"   To convert gregorian date to persian jalali date issue the following:\n\n"
				"   $ %s -j '2016-12-20'\n\n"
				
				"   To change the format of the output issue the following:\n\n"
				"   $ %s -f '%%y-%%m-%%d' \n\n"
			 
				"   To get last modification date in persian jalali calendar issue the following:\n\n"
				"   $ ./jdate -r '~/PATH/TO/FILE'\n\n", PROGRAM_NAME, PROGRAM_NAME, PROGRAM_NAME, PROGRAM_NAME);
				
		fprintf (stream, "Report bugs to mohammad.j.ahmadi@gmail.com\n"
						 "Project home page: <https://github.com/MJAhmadi/jdate>\n\n");
	}
	
	exit(exit_code);
}

#endif //_ABOUT_H

