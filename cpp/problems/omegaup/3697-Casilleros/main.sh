#!/bin/bash
#Programa para probar los casos de prueba
red=$'\e[1;31m'
grn=$'\e[1;32m'
yel=$'\e[1;33m'
blu=$'\e[1;34m'
mag=$'\e[1;35m'
cyn=$'\e[1;36m'
end=$'\e[0m'
clear
for program in ./programas/*.cpp; do
  programName=$(basename $program);
  #if [[ ${programName:0:1} != "_" ]]; then
    printf "${cyn}$programName${end}\n"
    clang++-7 -pthread -std=c++17 -o main $program
    if [ -e "main" ]; then
      for filepath in ./casos/*.txt; do
        filename=$(basename $filepath .txt)
        if [[ ${filename:0:1} != "_" ]] ; then
          printf "${yel}► $filename${end}\n";  
          ./main < $filepath
          printf "\n" ;
        fi
      done
      rm ./main;
    fi
    echo;
  #fi
done