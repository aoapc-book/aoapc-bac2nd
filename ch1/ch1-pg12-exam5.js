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
        console.log("the input sequence is:", `${a}\t${b}\t${c}`);
        if (a < b && b < c) {
            console.log("The sorted sequence is:", `${a}\t${b}\t${c}`);
        }
        if (a < c && c < b) {
            console.log("The sorted sequence is:", `${a}\t${c}\t${b}`);
        }
        if (b < c && c < a) {
            console.log("The sorted sequence is:", `${b}\t${c}\t${a}`);
        }
        if (b < a && a < c) {
            console.log("The sorted sequence is :", `${b}\t${a}\t${c}`);
        }
        if (c < a && a < b) {
            console.log("The sorted sequence is:", `${c}\t${a}\t${b}`);
        }
        if (c < b && b < a) {
            console.log("The sorted sequence is:", `${c}\t${b}\t${a}`);
        }
        consolLnrd.close();
    }
    counter++;

});
