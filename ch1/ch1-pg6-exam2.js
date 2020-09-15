const lineReader = require("readline");
const consLineRd = lineReader.createInterface({
    input:process.stdin
});
consLineRd.on("close", () => {
    process.exit();
});

let num;

consLineRd.on("line", input => {
    num = parseInt(input);
    console.log(`${num % 10}${Math.floor(num / 10) % 10}${Math.floor(num / 100)}`);
    consLineRd.close();
});
