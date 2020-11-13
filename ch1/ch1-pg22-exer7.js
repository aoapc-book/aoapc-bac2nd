console.log("Judging the leap year");
const lineRdr = require("readline");
const cmdLineRdr = lineRdr.createInterface({
    input:process.stdin
});
cmdLineRdr.on('close', () => {
    process.exit();
});

let year;

cmdLineRdr.on('line', (input) => {
    if (input === 'Q') {
        cmdLineRdr.close();
    }
    year = parseInt(input);
    if (year % 4 === 0) {
        if (year % 100 === 0 && year % 400 != 0) {
            console.log("This is not a leap year!");
        } else {
            console.log("This is a leap year");
        }
    } else {
        console.log("This is not a leap year!");
    }
})