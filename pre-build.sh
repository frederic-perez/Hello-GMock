#!/bin/bash

# Clone or update googletest from repo
if [ -d googletest ]
then
	cd googletest
	git pull
else
	git clone https://github.com/google/googletest.git
fi
