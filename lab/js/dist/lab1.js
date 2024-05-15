var __extends = (this && this.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (Object.prototype.hasOwnProperty.call(b, p)) d[p] = b[p]; };
        return extendStatics(d, b);
    };
    return function (d, b) {
        if (typeof b !== "function" && b !== null)
            throw new TypeError("Class extends value " + String(b) + " is not a constructor or null");
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
var data = {
    id: 1,
    name: "Василий",
    surname: "Пупкин",
};
var concat = function (num1, num2) {
    return num1.toString() + num2.toString();
};
var type = "people";
var age = 13;
var student = true;
console.log(concat(data.id, 5)); // "15"   
var jsonData = JSON.stringify(data);
console.log(jsonData);
//max in array
function max(array) {
    if (array.length === 0) {
        throw new Error("Массив пуст");
    }
    var maxNum = array[0];
    for (var i = 1; i < array.length; i++) {
        if (array[i] > maxNum) {
            maxNum = array[i];
        }
    }
    return maxNum;
}
var array = [4, 6, 7, 3, 10];
var maxNum = max(array);
console.log(maxNum); // Выводит: 10
//negative in matrix
function negative(matrix) {
    for (var i = 0; i < matrix.length; i++) {
        for (var j = 0; j < matrix[i].length; j++) {
            if (matrix[i][j] < 0) {
                return true;
            }
        }
    }
    return false;
}
var matrix = [
    [1, 2, 3],
    [-4, 5, 6],
    [7, -8, 9]
];
console.log(negative(matrix)); // Выводит: true
function sumThreeValues(tuple) {
    var str = tuple[0], value1 = tuple[1], value2 = tuple[2], value3 = tuple[3];
    return value1 + value2 + value3;
}
var myTuple = ["num", 1, 2, 3];
console.log(sumThreeValues(myTuple)); // Выводит: 6
//перечисление
var BallType;
(function (BallType) {
    BallType["Football"] = "\u0444\u0443\u0442\u0431\u043E\u043B\u044C\u043D\u044B\u0439";
    BallType["Basketball"] = "\u0431\u0430\u0441\u043A\u0435\u0442\u0431\u043E\u043B\u044C\u043D\u044B\u0439";
    BallType["Tennis"] = "\u0442\u0435\u043D\u043D\u0438\u0441\u043D\u044B\u0439";
    BallType["Volleyball"] = "\u0432\u043E\u043B\u0435\u0439\u0431\u043E\u043B\u044C\u043D\u044B\u0439";
})(BallType || (BallType = {}));
var ball = BallType.Football;
var ball2 = BallType.Tennis;
console.log(ball); // футбольный
console.log(ball2); // теннисный
var football = {
    type: BallType.Tennis,
    color: "ярко-зеленый",
    weight: 56,
};
var jsonData2 = JSON.stringify(football);
console.log(jsonData2);
//4
var Pet = /** @class */ (function () {
    function Pet() {
        this.name = 'Some pet';
        this.age = -1;
    }
    Pet.prototype.speak = function () {
        return "No speak. I am fish!";
    };
    return Pet;
}());
var Dog = /** @class */ (function (_super) {
    __extends(Dog, _super);
    function Dog() {
        var _this = _super !== null && _super.apply(this, arguments) || this;
        _this.label = "AngryHunter";
        _this.age = 8;
        return _this;
    }
    Dog.prototype.speak = function () {
        return "Yaw-Gaw!";
    };
    return Dog;
}(Pet));
var Cat = /** @class */ (function (_super) {
    __extends(Cat, _super);
    function Cat() {
        var _this = _super !== null && _super.apply(this, arguments) || this;
        _this.name = 'Barsik';
        _this.age = 2;
        return _this;
    }
    Cat.prototype.speak = function () {
        return "Miyau!";
    };
    return Cat;
}(Pet));
function Info(pet) {
    console.log("Name: ".concat(pet.name));
    console.log("Age: ".concat(pet.age));
    console.log("Speak: ".concat(pet.speak()));
}
var dog = new Dog();
Info(dog);
var cat = new Cat();
Info(cat);
