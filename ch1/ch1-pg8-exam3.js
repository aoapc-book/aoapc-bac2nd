const lnrd = require("readline");
const cslLnrd = lnrd.createInterface({
    input: process.stdin
});
cslLnrd.on("close", () => {
    process.exit();
});

let cnt = 1;

let a;
let b;
let temp;

cslLnrd.on("line", input => {
    if (cnt > 2) {
        cslLnrd.close();
    }
    if (cnt == 1) {
        a = input;
    }
    if (cnt == 2) {
        b = input;
        temp = a;
        a = b;
        b = temp;
        console.log("The first method of exchange 2 input numbers: ", `${a}\t${b}`);
        cslLnrd.close();
    }
    cnt++;
});
