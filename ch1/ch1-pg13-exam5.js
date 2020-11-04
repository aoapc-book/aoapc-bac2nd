const lineReader = require("readline");
const consoleLR = lineReader.createInterface({
    input: process.stdin
});
consoleLR.on('close', () => {
    process.exit();
});
console.log("Hello ch1-pg13-exam5.js");

let a;
let b;
let c;

let counter = 1;

consoleLR.on('line', (input) => {
    if (counter === 1) {
        a = input;
    }
    if (counter === 2) {
        b = input;
    }
    if (counter === 3) {
        c = input;
        console.log("The input sequence is:", `${a}\t${b}\t${c}`);
        consoleLR.close();
    }
    counter++;
});