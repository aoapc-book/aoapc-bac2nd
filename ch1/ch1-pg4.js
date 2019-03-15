const lineReader = require("readline");
const consoleLineReader = lineReader.createInterface({
    input: process.stdin,
    output: process.stdout
});

let a;
let b;
let counter = 1;

consoleLineReader.on("line", input => {
    if (counter === 1) {
        a = input;
        counter++;
        return undefined;
    }
    if (counter === 2) {
        b = input;
	console.log(parseInt(a) + parseInt(b));
    consoleLineReader.close();
    }
});

consoleLineReader.on("close", () => {
    console.log("on close is read");
    process.exit();
});
