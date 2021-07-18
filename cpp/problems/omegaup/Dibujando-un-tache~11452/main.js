const print = (text) => process.stdout.write(text);

function main(input){
  let n = input[0];
  for(var i = 0; i < n; i++){
    for(var j = 0; j < n; j++){
      var c = ' ';
      if(i == j || i == n-j-1) c = '@';
      print(c)
    }
    print("\n");
  }
  return;
}

module.exports={main}