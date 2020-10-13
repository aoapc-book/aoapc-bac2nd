const lnrd = require("readline");
const consolLnrd = lnrd.createInterface({
    input: process.stdin
});
consolLnrd.on("close", () => {
    process.exit()
});

let numOfHeads = 0;
let numOfLegs = 0;
let numOfChicken = -1;
let numOfRabits = -1;

let counter = 1;

consolLnrd.on("line", input => {
    if (counter == 1) {
        numOfHeads = input;
    }
    if (counter == 2) {
        numOfLegs = input;
        console.log("The number of heads is:", `${numOfHeads}`);
        console.log("The number of legs is:", `${numOfLegs}`);
        console.log("The number of chicken is:", `${numOfChicken}`);
        console.log("The number of rabits is:", `${numOfRabits}`);
        consolLnrd.close();
    }
    counter++;
});
