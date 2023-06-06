#!/bin/sh
txtfiles=` find . -depth -name '*.txt'`
for f in $txtfiles
do mv $f ${f%.txt}.text;
done
