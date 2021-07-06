#!/bin/bash
#Programa para probar los casos de prueba

showCases=true # Muestra detalles los casos de prueba
showResults=true # Muestra la salida de los programas
showExpected=true # Muestra la salida esperada si se obtuvo respuesta incorrecta
showTime=true # Muestra el tiempo tltal
timePrecision=5  # Número de decimales [0, 9]

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

runNodePath='./helpers/run.js'

arrayGet() { 
  local array=$1 index=$2
  local i="${array}_$index"
  printf '%s' "${!i}"
}

# args: program, extension
preRun(){
  local program=$1
  local extension=$2
  
  case $extension in
    "cpp") 
      clang++-7 -pthread -std=c++17 -o main $program
      if [ -e "main" ]; then echo "true"
        else echo "false"
      fi
    ;;
    *) 
      echo "true"
    ;;
  esac
}

# args: program, extension
posRun(){
  local program=$1
  local extension=$2
  
  if [[ $extension == "cpp" ]]; then
    rm ./main
  fi
}

# args: program, testFile
execute(){
  local program=$1
  local extension=$2
  local testFile=$3
  case $extension in
    "cpp") ./main < $testFile ;;
    "py") python $program < $testFile ;;
    "js") node $runNodePath $program $testFile ;;
  esac
}

printCase(){
  if [ $showCases == true ] ; then 
    printf $1; 
  fi
}

# args: program
run(){
  local program=$1; 
  local extension=${program##*.}

  printf "${cyn}$programName${end} $(arrayGet programLabel $extension)\n"

  ready=$(preRun $program $extension)
  if [[ $ready == "true" ]]; then
    totalTime=0
    totalTests=0
    ac=0

    for testFile in ./casos/*.in; do
      testFilename=$(basename $testFile .in)
      if [[ ${testFilename:0:1} != "_" ]] ; then
        $($showCases == true) && printf "${yel}► ${testFilename}${end} "

        STARTTIME=$(date '+%s%N')

        out=$(execute $program $extension $testFile)

        ENDTIME=$(date '+%s%N')
        testDuration=$((ENDTIME-STARTTIME))
        totalTime=$(($totalTime+$testDuration))

        if [ $showResults == true ] ; then  
          printf " $out\t\t"; 
        fi

        # compare with expected output (.out files)
        if [ -e "./casos/$testFilename.out" ]; then
          outputFilename="./casos/$testFilename.out"
          expected=$(cat $outputFilename)
          processedOutput="${out##*$'\n'}" # get last line
          if [[ $processedOutput == $expected ]]; then
            printCase "(${grn}AC${end})"
            ac=$(($ac+1))
          else
            printCase "(${red}WA${end})"
            if [ $showExpected == true ] ; then  
              printf " $expected ($(cat $testFile))"
            fi
          fi
          totalTests=$(($totalTests+1))
        fi

        printCase "\n"

      fi
    done
    
    if [ $showCases == false ] ; then
      if [ $ac -eq $totalTests ] ; then
        printf "${grn}AC${end} ";
      elif [ $ac == 0 ]; then
        printf "${red}WA${end} ";
      else
        printf "${lred}PA${end} ";
      fi
    fi

    if [ $showTime == true ] ; then
      precision="%0."$timePrecision"f"
      command=$"echo print((tonumber(string.format('$precision', $totalTime/1000000000)))..'s')"
      $command | lua
    fi
    posRun $program $extension
    printf "\n"

  fi
}

for program in ./programas/*; do
  programName=$(basename $program)
  #ignore files if name begins with "_"
  if [[ ${programName:0:1} != "_" ]]; then
    run $program
  fi
done