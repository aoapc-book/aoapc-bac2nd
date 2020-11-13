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
    if (input === 'Q') {
        cmdReadLn.close();
    }
    if (counter === 1) {
        a = parseInt(input);
    }
    if (counter === 2) {
        b = parseInt(input);
    }
    if (counter === 3) {
        c = parseInt(input);
        console.log(`The input 3 digits are: ${a}\t${b}\t${c}`);
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
        if (a + b <= c) {
            console.log("This is not a triangle");
        }else if (Math.pow(a, 2) + Math.pow(b, 2) != Math.pow(c, 2)) {
            console.log("This is a none right angled triangle");
        } else {
            console.log("This is a right angled triangle");
        }
        counter = 0;
    }
    counter++;
});