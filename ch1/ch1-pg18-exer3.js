console.log('Accumlation from 1 to n');
const lnreader = require("readline");
const cmdLnreader = lnreader.createInterface({
    input: process.stdin
});
cmdLnreader.on('close', () => {
    process.exit()
});

let n;
let sum = 0;

cmdLnreader.on('line', (input) => {
    n = parseInt(input);
    sum = n;
    console.log('The input number is:', `\n${n}`);
    console.log('');
    console.log(`The accumlation from 1 to ${n} is:`);
    while (n--) {
        sum += n;
    }
    console.log(`${sum}`);
    cmdLnreader.close();
});