const readline = require('readline');

const input = (text) => new Promise( (resolve, reject) => {
  const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
  rl.question(text || "", (result) =>{
    resolve(result);
    rl.close();
  })
});

module.exports={input, print}