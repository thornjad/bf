const packageInfo = require('./package.json');
const fs = require('fs');

function main() {
  if (process.argv[2] === undefined) {
    printVersion();
    printHelp();
  } else {
    const path = process.argv[2];
    if (isFileBF(path)) {
      console.log('hey!');
    } else {
      console.error('File must be either .b or .bf');
      process.exit(1);
    }
  }
}

function printVersion() {
  console.log(packageInfo.version);
}

function printHelp() {
  const str = `
Transpiler for language brainfuck

Enter a bf file as the first argument to this script
  `;
  console.log(str);
}

function isFileBF(path) {
  console.log(path);
  return true;
}

function inArray(arr, val) {
  return arr.indexOf(val) > -1;
}

// begin!
main();
