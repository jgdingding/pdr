#!/bin/bash

#Justin Gou
#jyg2qhc
#3/2/2020
#averagetime.sh

total=0
for i in {1..5};
do runningTime=`./a.out $1 $2`; total=$(($total + $runningTime));
done;

echo $(($total/5))
