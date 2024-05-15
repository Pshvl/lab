const data = {
    id: 1,
    name: "Василий",
    surname: "Пупкин",
};
const concat = (num1, num2) => {
    return num1.toString() + num2.toString();
};
console.log(concat(data.id, 5)); // "15"   
const jsonData = JSON.stringify(data);
console.log(jsonData);
//   const concatenateNumbers = (num1: number, num2: number): string => `${num1}${num2}`;
// const result: string = concatenateNumbers(data.id, 5);
// console.log("Result:", result);
