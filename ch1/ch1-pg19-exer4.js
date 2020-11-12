console.log("calculate the sin and cos value according to the input n degrees");
const lineRdr = require("readline");
const cmdLineRdr = lineRdr.createInterface({
    input: process.stdin
});
cmdLineRdr.on('close', () => {
    process.exit();
});

let n = 0;

cmdLineRdr.on('line', (input) => {
    n = parseInt(input);
    console.log(`The input degree is: ${n}`);
    // console.log(`The calculated value of sin(${n}) is: ${sin(n)}`);
    console.log(`The calculated value of sin(${n}) is:`);
    cmdLineRdr.close();
})