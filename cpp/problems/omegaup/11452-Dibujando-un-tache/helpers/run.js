const { readFileSync, existsSync } = require('fs');
const { resolve: r } = require('path');
const args = process.argv.slice(2);

let [ programPath, casePath ] = args;
if(!programPath || !casePath) return;

const { main } = require(r(programPath));
if(!main) return;

casePath = r(casePath);
if(!existsSync(casePath)) return;
let data = readFileSync(casePath).toString();
main(data.split("\n"));