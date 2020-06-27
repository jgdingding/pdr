#!/bin/bash

#Justin Gou
#jyg2qhc
#3/24/2020
#averagetime.sh

read -e -p "enter the exponent for counter.cpp: " n

if [[ $n == "quit" ]]; then
	exit
fi

sum=0;

for i in {1..5};do 
	echo "Running iteration $i..."
	runningTime=`./a.out $n`;
	echo "time taken: $runningTime ms"
	sum=$(($sum + $runningTime));
done;

echo "5 iterations took $sum ms"
echo "Average time was $(($sum/5)) ms"
