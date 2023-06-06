#!/bin/sh
echo "Enter Basics:"
read basics 
echo "Enter TA"
read ta
gs=`bc -l <<<$basics+$ta+$basics/10`
echo "the gross is $gs"
