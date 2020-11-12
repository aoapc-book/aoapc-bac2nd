console.log("calculate the discount price");
const readLn = require("readline");
const cmdReadLn = readLn.createInterface({
    input: process.stdin
});
cmdReadLn.on('close', () => {
    process.exit();
})

const SP = 95;
const DP = 300;
const DISCOUNT = 0.85;

let n;

cmdReadLn.on('line', (input) => {
    if (input == 'Q') {
        cmdReadLn.close();
    }
    n = parseInt(input);
    console.log(`The input amount is: ${n}`);
    if (SP * n > DP) {
        console.log(`The price with discount is: ${(SP * n * DISCOUNT).toFixed(3)}`);
    } else {
        console.log(`The price without discount is: ${(SP * n).toFixed(3)}`);
    }
});