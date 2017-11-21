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

class AMachine {
  constructor(size) {
    this.mem = new Array(36000);
    this.ptr = this.mem.length / 2;
  }

  inc() {
    if (++this.ptr > this.mem.length) {
      this.extendMemory(1);
    }
  }

  dec() {
    if (--this.ptr < 0) {
      this.extendMemory(0);
    }
  }

  setSym(sym) {
    this.mem[this.ptr] = sym;
  }

  getSym() {
    return this.mem[this.ptr];
  }

  extendMemory(dir) {
    if (dir === 0) {
      // extend down
      this.ptr = this.ptr + this.mem.length;
      this.mem = new Array(this.mem.length + 1).concat(this.mem);
    } else if (dir === 1) {
      // extend up
      this.mem = this.mem.concat(new Array(this.mem.length + 1));
      // ptr remains where it is
    }
  }
}

class BFInterpreter {
  constructor() {

  }
}
