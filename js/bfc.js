const packageInfo = require('./package.json');
const fs = require('fs');

function main() {
  if (process.argv[2] === undefined) {
    printVersion();
    printHelp();
  } else {
    const path = process.argv[2];
    if (isFileBF(path)) {

    } else {
      console.error('File must be either .b or .bf');
      process.exit(1);
    }
  }
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
