read -p "pls input a string and the process will run next if your input is not \"I am dog\" :" string
while [ "$string" != "I am dog" ]
do
	read -p "pls input again: " string
	echo "Your inout $string!"
done
