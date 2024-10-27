#!/bin/bash

read name
echo "name = $name!"

read age height
echo "wow, you age is $age but you heigh is $height!"

read -p "pls input you length: " length
echo "wow, you length is $length?!!"

read -p "pls input you hobby(max 5 char): " -n 5 hobby
echo "wow, you like $hobby!"

read -p "pls input you poisition(max at 5s): "-t 5 pos
echo "wow, you live in a gorgrous place at $pos!"

read -p "pls input you password: " -s password
echo "you passward is $password! omg, I reveal it!"

