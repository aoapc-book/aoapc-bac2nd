console.log("The three digits division process!");
const lnrd = require("readline");
const cmdLnrd = lnrd.createInterface({
    input: process.stdin
});
cmdLnrd.on('close', () => {
    process.exit();
})

let a;
let b;
let c;

let counter = 1;

cmdLnrd.on('line', (input) => {
    if (counter === 1) {
        a = parseInt(input);
    }
    if (counter === 2) {
        b === parseInt(input);
    }
    if (counter === 3) {
        c === parseInt(input);
        console.log("The input sequence is:", `${a}\t${b}\t${c}`);
        cmdLnrd.close();
    }
    counter++;
})