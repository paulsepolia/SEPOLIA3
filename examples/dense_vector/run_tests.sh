#!/bin/bash

# run the script in each subfolder

script_name="001_compile_gnu.sh";
exe_name="x_gnu";
out_name="out_all";

for subdir in */; do
    cd "$subdir"
    ./$script_name;
    ./$exe_name >> ../out_tmp;
    rm $exe_name
    cd ..
    sort out_tmp | uniq > $out_name
    rm out_tmp
done

