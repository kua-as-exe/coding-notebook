#!/bin/bash

adb push ./bin/aapt-arm-pie /data/local/tmp                                                                                    
adb shell chmod 0755 /data/local/tmp/aapt-arm-pie


packages=( $(adb shell pm list package -f) )
getName(){
  name=$1
  out=$( echo $packages | grep $name )
  out=$( echo $out | cut -d':' -f 2 )
  path="${out%=*}"
  dump=$(adb shell "/data/local/tmp/aapt-arm-pie dump badging $path")
  echo $( echo -e "$dump" | grep "application-label:")
}

list=($( echo $packages \
  | cut -f 2 -d ":" \
  | grep -o "=[.a-z]*$" \
  | cut -f 2 -d'=' \
  | awk '!/android/' \
  | sort \
 ))

options=()
for x in "${packages[@]}"; do
  raw=$( echo $x | cut -f 2 -d ":" )
  path="${raw%=*}"  
  pkg_name=$( echo $raw | grep -o "=[.a-z0-9]*$" | cut -f 2 -d'=' )

  [[ "$pkg_name" == "com.android"* ]] && continue

  dump=$( adb shell "/data/local/tmp/aapt-arm-pie dump badging $path" )
  name=$( echo -e "$dump" | grep "application-label:" | grep -o "'[ .A-Za-z0-9]*'" )
  name=${name:1: -1}
  # echo $name $pkg_name

  options+=( "$name ($pkg_name)" "off")
done

echo -e $options

choices=($(dialog --clear --stdout --no-items \
        --separate-output \
        --trim \
        --ok-label "Delete" \
        --checklist "Select options:" 22 120 16 "${options[@]}"))

for x in ${choices[@]}; do
  [[ "$x" != "("* ]] && continue
  echo -e "\nUninstalling $x"
  pkg_name=$( echo $x | grep -o "\([.a-z0-9]*\)" )
  pkg_name=${pkg_name}
  echo $pkg_name
  adb shell pm uninstall --user 0 $pkg_name
done
