console.log("ch1-pg14-exam5.js: The simple way of sort three numbers");
const lineReader = require("readline");
const consolLineReader = lineReader.createInterface({
    input: process.stdin
});
consolLineReader.on('close', () => {
    process.exit();
});

let a;
let b;
let c;

let counter = 1;

consolLineReader.on('line', (input) => {
    if (counter === 1) {
        a = parseInt(input);
    }
    if (counter === 2) {
        b = parseInt(input);
    }
    if (counter === 3) {
        c = parseInt(input);
        console.log("The input sequence is:", `${a}\t${b}\t${c}`);
        if (a > b) {
            a = a + b;
            b = a - b;
            a = a - b;
        }
        if (a > c) {
            a = a + c;
            c = a - c;
            a = a - c;
        }
        if (b > c) {
            b = b + c;
            c = b - c;
            b = b - c;
        }
        console.log("The sorted sequence is:", `${a}\t${b}\t${c}`);
        consolLineReader.close();
    }
    counter++;
});