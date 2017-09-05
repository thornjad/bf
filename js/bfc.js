#!/usr/bin/env node

const program = require('commander');
const packageInfo = require('./package.json');

program
  .version(packageInfo.version)
  .arguments()
  .action();

program
  // .option('-w, --wasm', 'Compile to WebAssembly')
  // .option('-a, --asmjs', 'Compile to asm.js compatible code');
