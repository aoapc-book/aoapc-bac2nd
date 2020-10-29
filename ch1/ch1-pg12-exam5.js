const lnrd = require("readline");
const consolLnrd = lnrd.createInterface({
    input: process.stdin
});
consolLnrd.on("close", () => {
    process.exit();
});

let a = 0;
let b = 0;
let c = 0;

let counter = 1;

consolLnrd.on("line", (input) => {
    if (counter == 1) {
        a = input;
    }
    if (counter == 2) {
        b = input;
    }
    if (counter == 3) {
        c = input;
    }
    counter++;
    console.log("the input sequence is:", `${a}\t${b}\t${c}`);
    if (a < b && b < c) {
        console.log("the sorted sequence is:", `${a}\t${b}\t${c}`);
    }
});
