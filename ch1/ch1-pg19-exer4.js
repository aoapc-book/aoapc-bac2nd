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
    console.log(`The calculated value of sin(${n}) is: ${Math.sin(n * Math.PI / 180).toFixed(3)}`);
    console.log(`The calculated value of sin(${n}) is: ${Math.cos(n * Math.PI / 180).toFixed(3)}`);
    cmdLineRdr.close();
})