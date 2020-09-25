const lineReader = inport('read-line');
const consolLineReader = lineReader.open({
    intput: stdin
)}
consolLineReader.('close')( () => {
    process.exit();
});

let a;
let b;


