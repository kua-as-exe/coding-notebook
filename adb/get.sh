

adb push ./bin/aapt-arm-pie /data/local/tmp                                                                                    
adb shell chmod 0755 /data/local/tmp/aapt-arm-pie

getName(){
  name=$1
  out=$( adb shell pm list package -f $name )
  out=$( echo $out | cut -d':' -f 2 )
  path="${out%=*}"
  dump=$(adb shell "/data/local/tmp/aapt-arm-pie dump badging $path")
  echo $( echo -e "$dump" | grep "application-label")
}

getName com.google.android.keep
