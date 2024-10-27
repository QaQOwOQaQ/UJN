read -p "pls input a number:(less than 10) :" num
until [ $num -lt 0 ]
do 
	echo "num = $num"
	#let num=num-1
	num=$[num - 1]
done

