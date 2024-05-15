interface Entity {
    id: number;
}
interface ToJsonStringify extends Entity {
    name: string;
    surname?: string;
}
declare const data: ToJsonStringify;
declare const concat: (num1: number, num2: number) => string;
declare const jsonData: string;
