#!/bin/bash
#Programa para generar casos de prueba

#./generar.sh bruto

# - Jorge Arreola

clear
bla=$'\e[1;30m'; gray=$'\e[1;90m'
red=$'\e[1;31m'; lred=$'\e[1;91m'
grn=$'\e[1;32m'; lgrn=$'\e[1;92m'
yel=$'\e[1;33m'; lyel=$'\e[1;93m'
blu=$'\e[1;34m'; lblu=$'\e[1;94m'
mag=$'\e[1;35m'; lmag=$'\e[1;95m'
cyn=$'\e[1;36m'; lcyn=$'\e[1;96m'
end=$'\e[0m'   ; whit=$'\e[1;97m'

programLabel_cpp="${blu}(c++)${end}"
programLabel_py="${yel}(python)${end}"
programLabel_js="${lyel}(javascript)${end}"

echo "Program $1 $2";

programPath=$1

for testFile in ./casos/*.in; do
  testFilename=$(basename $testFile .in)
  if [[ ${testFilename:0:1} != "_" ]] ; then
    if [ ! -e "./casos/$testFilename.out" ]; then
      outputFilename="./casos/$testFilename.out"
      expectedOutput=$(./$programPath < $testFile)
      printf $expectedOutput > $outputFilename
    fi
  fi
done
