#!/bin/sh
echo "Enter Folder Name:"
read foldername
echo "Enter extension:"
read extension
mkdir $foldername
txtfiles=` find . -maxdepth 1 -name '.$extension'`
for f in $txtfiles
do cp $f $foldername
done
