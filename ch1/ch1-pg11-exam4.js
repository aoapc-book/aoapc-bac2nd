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
        if (numOfHeads % 2 != 0) {
            console.log("The number of heads should be divided by 2");
            counter--;
        }
    }
    if (counter == 2) {
        numOfLegs = input;
        if (numOfLegs % 2 != 0) {
            console.log("The number of legs should be divided by 2");
            counter--;
        } else {
            console.log("The number of heads is:", `${numOfHeads}`);
            console.log("The number of legs is:", `${numOfLegs}`);
            numOfRabits = numOfLegs / 2 - numOfHeads;
            numOfChicken = numOfHeads - numOfRabits;

            if (numOfRabits < 0 || numOfChicken < 0) {
                console.log("There is no answer according to the input number of heads and legs");
                consolLnrd.close();
            }

            console.log("The number of chicken is:", `${numOfChicken}`);
            console.log("The number of rabits is:", `${numOfRabits}`);
            consolLnrd.close();
        }
    }
    counter++;
});
