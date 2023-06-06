#!/bin/bash

function_sort() {
    n=$#
    s=($*)

    echo "Original array is: ${s[*]}";

    for (( i = 0; i < $n-1; i++ ))
    do
        for ((j = 0; j < $n-1-$i; j++ ))
        do
            if [[ ${s[$j]} > ${s[$j+1]} ]]
            then
                temp=${s[$j]};
                s[$j]=${s[$j+1]};
                s[$j+1]=$temp;
            fi
        done
    done

    echo "Array after sorting: " ${s[*]}
}

function_sort $*
