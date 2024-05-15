interface Entity {
    id: number;
   }  
   interface ToJsonStringify extends Entity {
    name: string;
    surname?: string;
   }
   const data: ToJsonStringify = {
    id: 1,
    name: "Василий",
    surname:"Пупкин",
   }

   const concat = (num1: number, num2: number): string => 
   {
    return num1.toString() + num2.toString();
  }
  
  console.log(concat(data.id, 5)); // "15"   


  const jsonData:string= JSON.stringify(data);
  console.log(jsonData); 

















//   const concatenateNumbers = (num1: number, num2: number): string => `${num1}${num2}`;

// const result: string = concatenateNumbers(data.id, 5);

// console.log("Result:", result);