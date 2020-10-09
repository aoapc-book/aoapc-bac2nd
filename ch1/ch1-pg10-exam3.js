const lineReader = require("readline");
const consolLineReader = lineReader.createInterface({
    input: process.stdin
})
consolLineReader.on("close", () => {
    process.exit();
});

let a;
let b;
let counter = 1;

consolLineReader.on("line", input => {
    if (counter == 1) {
        a = input;
    }
    if (counter == 2) {
        b = input;
        console.log("The reverse result of input value is:", `${b}\t${a}`);
        consolLineReader.close();
    }
    counter++;
});

