const lnrd = require("readline");
const cslLnrd = lnrd.createInterface({
    input:process.stdin
});
cslLnrd.on("close", () => {
    process.exit();
});

let num;
let firstD;
let secondD;
let thirdD;

cslLnrd.on("line", input => {
    num = parseInt(input);
    firstD = Math.floor(num / 100);
    secondD = Math.floor(num % 100 / 10);
    thirdD = num % 10;

    console.log("The reverse vertion of 3digit number input is: ", thirdD * 100 + secondD * 10 + firstD);
    cslLnrd.close();
});
