console.log("Change the temperature from fahrenheit to celsius.");
const lnrd = require("readline");
const cmdLnrd = lnrd.createInterface({
    input: process.stdin
});
cmdLnrd.on('close', () => {
    process.exit()
});

let fahrenheit;

cmdLnrd.on('line', (input) => {
    fahrenheit = input;
    console.log("The input temperature in fahrenheit is:", `${fahrenheit}`);
    console.log("The output temperature in celsius is", `${(5 * (fahrenheit - 32) / 9).toFixed(3)}`);
    cmdLnrd.close();
})