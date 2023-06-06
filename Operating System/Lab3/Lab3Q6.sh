#!/bin/sh
for f in `ls` ; do
  sed -i 's/^ex:/Example:/' "$f"
  sed -i 's/\.ex:/\.Example:/' "$f"
done
