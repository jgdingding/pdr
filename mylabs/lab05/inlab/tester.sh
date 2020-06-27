#!/bin/bash

time for i in {1..1000}; do cat testfile1.txt | ./a.out > /dev/null; cat testfile2.txt | ./a.out > /dev/null; cat testfile3.txt | ./a.out > /dev/null; done
