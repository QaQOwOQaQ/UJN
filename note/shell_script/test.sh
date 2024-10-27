#! /bin/bash
# condition test

# 1. test string
string1="xjy"
string2="ujn"
string3="xjy"
string4=''

if [ $string1 = $string2 ]
then
	echo "$string1 == $string2"
else
	echo "$string1 != $string2"
fi

if [ $string1 = $string3 ]
then 
	echo "$string1 == $string3"
else
	echo "$string1 != $string3"
fi

if [ -z $string4 ]
then 
	echo "$string4 == NULL"
else
	echo "$string4 != NULL"
fi


if [ -n $string4 ]
then 
	echo "$string4 != NULL"
else
	echo "$string4 == NULL"
fi


if [ -z $string3 ]
then 
	echo "$string3 == NULL"
else
	echo "$string3 != NULL"
fi


if [ -n $string3 ]
then 
	echo "$string3 != NULL"
else
	echo "$string3 == NULL"
fi


