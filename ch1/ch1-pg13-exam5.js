console.log("Hello ch1-pg13-exam5.js");
const lineReader = require("readline");
const consoleLR = lineReader.createInterface({
    input: process.stdin
});
consoleLR.on('close', () => {
    process.exit();
});

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

        if (a <= b && b <= c) {
            console.log("The sorted sequence is:", `${a}\t${b}\t${c}`);
            consoleLR.close();
        }
        if (a <=c && c <= b) {
            console.log("The sorted sequence is:", `${a}\t${c}\t${b}`);
            consoleLR.close();
        }
        if (b <= a && a <= c) {
            console.log("The sorted sequence is:", `${b}\t${a}\t${c}`);
            consoleLR.close();
        }
        if (b <= c && c <= a) {
            console.log("The sorted sequence is:", `${b}\t${c}\t${a}`);
            consoleLR.close();
        }
        if (c <= a && a <= b) {
            console.log("The sorted sequence is:", `${c}\t${a}\t${b}`);
            consoleLR.close();
        }
        if (c <= b && b <= a) {
            console.log("The sorted sequence is :", `${c}\t${b}\t${a}`);
            consoleLR.close();
        }
    }
    counter++;
});