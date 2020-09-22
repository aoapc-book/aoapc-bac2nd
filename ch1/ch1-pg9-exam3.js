const lnrd = require("readline");
const cslLnrd = lnrd.createInterface({
    input: process.stdin
});
cslLnrd.on("close", () => {
    process.exit();
});

let cnt = 1;
let a = 0;
let b = 0;

cslLnrd.on("line", input => {
    if (cnt == 1) {
        a = parseInt(input);
    }
    if (cnt == 2) {
        b = parseInt(input);
        b = a + b;
        a = b - a;
        b = b - a;
        console.log("Reverse a and b method 2:",`${a}\t${b}`);
        cslLnrd.close();
    }
    cnt++;
});
