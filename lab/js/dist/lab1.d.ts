interface Entity {
    id: number;
}
interface ToJsonStringify extends Entity {
    name: string;
    surname?: string;
}
declare const data: ToJsonStringify;
declare const concat: (num1: number, num2: number) => string;
declare const type: string;
declare let age: number;
declare const student: boolean;
declare const jsonData: string;
declare function max(array: number[]): number;
declare const array: number[];
declare const maxNum: number;
declare function negative(matrix: number[][]): boolean;
declare const matrix: number[][];
type Tuple = [string, number, number, number];
declare function sumThreeValues(tuple: Tuple): number;
declare const myTuple: Tuple;
declare enum BallType {
    Football = "\u0444\u0443\u0442\u0431\u043E\u043B\u044C\u043D\u044B\u0439",
    Basketball = "\u0431\u0430\u0441\u043A\u0435\u0442\u0431\u043E\u043B\u044C\u043D\u044B\u0439",
    Tennis = "\u0442\u0435\u043D\u043D\u0438\u0441\u043D\u044B\u0439",
    Volleyball = "\u0432\u043E\u043B\u0435\u0439\u0431\u043E\u043B\u044C\u043D\u044B\u0439"
}
declare const ball: BallType;
declare const ball2: BallType;
type Ball = {
    type: BallType;
    color: string;
    weight: number;
};
declare const football: Ball;
declare const jsonData2: string;
declare class Pet {
    name: string;
    age: number;
    speak(): string;
}
declare class Dog extends Pet {
    label: string;
    age: number;
    speak(): string;
}
declare class Cat extends Pet {
    name: string;
    age: number;
    speak(): string;
}
declare function Info<T extends Pet>(pet: T): void;
declare const dog: Dog;
declare const cat: Cat;
