#!/bin/bash

folder=$1
dest=$2

[[ -z $folder ]] && folder="/sdcard/"
[[ ${folder: -1} != "/" ]] && folder="$folder/"

[[ ! -z $dest ]] && [[ ! -d $dest ]] && mkdir $dest

list=($(adb shell ls -la $folder  \
 | tail -n +2 \
 | awk '!/\.$/' \
 | awk '{ print $1 ":" $8 }' \
 | sort \
 ))

options=""
for x in "${list[@]}"; do
  _type=$( [[ ${x:0:1} == "-" ]] && echo "f" || echo ${x:0:1} )
  _perm=$( echo ${x:1} | cut -d':' -f 1 )
  _name=$( echo $x | cut -d':' -f 2 )

  [[ "$_type" == "l" ]] && continue

  options="$options $_type:$_name off "
done

cmd=(dialog --clear --stdout --no-items \
        --separate-output \
        --ok-label "Move" \
        --checklist "Select options:" 22 50 16)

choices=$("${cmd[@]}" $options)

clear

for x in $choices; do
  _name=$( echo $x | cut -d':' -f 2 )
  # echo -e "\Copy $x"
  adb pull $folder$_name $dest
done
