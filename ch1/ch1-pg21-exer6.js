console.log("Judging the right angled triangle");
const readLn = require("readline");
const cmdReadLn = readLn.createInterface({
    input: process.stdin
});
cmdReadLn.on('close', () => {
    process.exit()
});

let a;
let b;
let c;

counter = 1;

cmdReadLn.on('line', (input) => {
    if (counter === 1) {
        a = parseInt(input);
    }
    if (counter === 2) {
        b = parseInt(input);
    }
    if (counter === 3) {
        c = parseInt(input);
    }
})