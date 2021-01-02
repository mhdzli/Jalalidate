#!/bin/bash

if [ $? -eq 0 ]; then
	cp ./jdate /usr/local/bin
	
	mkdir -vp /usr/local/man/man1/
	
	rm -f /usr/local/man/man1/jdate.1
	rm -f /usr/local/man/man1/jdate.1.gz
	
	cp ./jdate.man /usr/local/man/man1/jdate.1
	gzip /usr/local/man/man1/jdate.1
fi

