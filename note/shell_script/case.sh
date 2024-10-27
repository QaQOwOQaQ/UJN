#! /bin/bash
# test number

read -p "pls input a number: "  x

case $x in 
	1)
		echo "one"
		;;
	2 | 3 | 4)
		echo "two or three or four"
		;;
	5)
		echo "five and go on-->"
		;;
	*)
		echo "other"
		;;
esac

# esac就是case的倒序
# shell中的case不允许除了最后一个*)之外的case不以;;结尾

