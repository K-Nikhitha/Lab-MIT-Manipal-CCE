#!/bin/sh
echo $"Enter File"
read f
sed -i'2~2d' $f
