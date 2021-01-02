#!/bin/bash

gcc main.c -o jdate

if [ $? -eq 0 ]; then
	strip ./jdate
	#help2man ./jdate > jdate.man
fi

