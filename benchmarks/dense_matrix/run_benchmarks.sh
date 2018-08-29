#!/bin/bash

# run the script in each subfolder

script_name="001_compile_gnu.sh";
exe_name="x_gnu";
clean_exe_name="0xx_clean.sh";
out_empty="out_must_be_empty";
out_tmp="out_tmp"
out_results="out_results_all"

for subdir in */; do
    cd "$subdir"
    ./${script_name};
    ./${exe_name} >> ../${out_tmp};
    ./${clean_exe_name} > /dev/null 2>&1 ;
    cd ..
done

cp ${out_tmp} ${out_results};
grep 'false' ${out_tmp} > ${out_empty}
rm ${out_tmp}

