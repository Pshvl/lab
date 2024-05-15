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
  const type:string= "people";
  let age:number=13;
  const student:boolean=true;


  console.log(concat(data.id, 5)); // "15"   


  const jsonData:string= JSON.stringify(data);
  console.log(jsonData); 



  //max in array
  function max(array: number[]): number {

    if (array.length === 0)
     {
      throw new Error("Массив пуст");
    }

    let maxNum = array[0];

    for (let i = 1; i < array.length; i++) 
    {
      if (array[i] > maxNum) {
        maxNum = array[i];
      }
    }
  
    return maxNum;
  }
  const array: number[] = [4, 6, 7, 3, 10];
  const maxNum = max(array);
  console.log(maxNum); // Выводит: 10




//negative in matrix
  function negative(matrix: number[][]): boolean 
  {
    for (let i = 0; i < matrix.length; i++) {
      for (let j = 0; j < matrix[i].length; j++) {
        if (matrix[i][j] < 0) {
          return true;
        }
      }
    }
    return false;
  }
  

  const matrix: number[][] = [
    [1, 2, 3],
    [-4, 5, 6],
    [7, -8, 9]
  ];
  
  console.log(negative(matrix)); // Выводит: true


//кортеж
  type Tuple = [string, number, number, number];

  function sumThreeValues(tuple: Tuple): number {
    const [str, value1, value2, value3] = tuple;
    return  value1 + value2 + value3;
  }
  
  
  const myTuple: Tuple = ["num", 1, 2, 3];
  console.log(sumThreeValues(myTuple)); // Выводит: 6


//перечисление
  enum BallType 
  {
    Football="футбольный",
    Basketball="баскетбольный",
    Tennis="теннисный",
    Volleyball="волейбольный"
  }
  
  const ball: BallType = BallType.Football;
  const ball2: BallType = BallType.Tennis;
  console.log(ball); // футбольный
  console.log(ball2); // теннисный

  
  type Ball = {
    type: BallType;
    color: string;
    weight: number;
  };

  const football: Ball = {
    type: BallType.Tennis,
    color: "ярко-зеленый",
    weight: 56,
  };
  
  const jsonData2:string= JSON.stringify(football);
  console.log(jsonData2); 


  //4
  class Pet {
    name: string = 'Some pet'
    age: number = -1
    speak() {
    return "No speak. I am fish!";
    }
   }
   class Dog extends Pet {
    label = "AngryHunter";
    age = 8;
    speak() {
    return "Yaw-Gaw!";
    }
   }
   class Cat extends Pet {
    name = 'Barsik';
    age = 2;
    speak() {
    return "Miyau!";
   }}

   
function Info<T extends Pet>(pet: T) {
  console.log(`Name: ${pet.name}`);
  console.log(`Age: ${pet.age}`);
  console.log(`Speak: ${pet.speak()}`);
}


const dog = new Dog();
Info(dog);

const cat = new Cat();
Info(cat);