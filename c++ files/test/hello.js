console.log("Js working");

let array = [1, 2, 3, 4, 5];

array.reduce((accumulator, currentValue) => {
    console.log(`Accumulator: ${accumulator}, Current Value: ${currentValue}`);
    return accumulator + currentValue;
}, 0);
console.log("Reduction complete");