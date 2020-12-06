#!/usr/bin/zsh

for file in `ls ./files/` ;
do

    for buffer_size in 64 128 256 512 1024 2048 ;
    do
        
        echo "./files/${file} ./files/copy_${buffer_size}_${file} ${buffer_size}"
        output=`./a.out ./files/${file} ./files/copy_${buffer_size}_${file} ${buffer_size}`
        echo "${output}"
        echo "${file},${buffer_size},${output}" >> res.csv

    done

done