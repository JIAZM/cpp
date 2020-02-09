#!/bin/bash

name=`echo $1 | awk -F "." '{print $1}'`
attr=`echo $1 | awk -F "." '{print $2}'`

#echo name = $name
#echo attr = $attr

if [ $attr = "cpp" ] ; then
	echo attr is .cpp
	echo Choose compiler g++
	CC=g++
elif [ $attr = "c" ] ; then
	echo attr is .c
	echo Choose compiler gcc
	CC=gcc
fi

$CC $name.$attr -o released/$name

if [ $? -eq 0 ] ; then
	echo Compile success;
	echo Compiled file moved to floder \[released/$name\]
else
	echo Compile fault;
fi
