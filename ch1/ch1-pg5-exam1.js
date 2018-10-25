const lineReader = require("readline");
const consoleLineReader = lineReader.createInterface({
    input:process.stdin
});
const PI = Math.PI;

let h;
let r;
let s1;
let s2;
let area;
let counter = 1;

consoleLineReader.on("line", input => {
    if (counter === 1) {
        r = parseFloat(input);
        s2 = PI * Math.pow(r, 2);
        ++counter;
        return undefined;
    }
    if (counter === 2) {
        h = parseFloat(input);
        s1 = 2 * PI * r * h;
        area = s1 + 2 * s2;
        console.log(`Area = ${area.toFixed(3)}`);
        consoleLineReader.close();
    }
});

consoleLineReader.on("close", () => {
    process.exit();
});
