"use strict";
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
Object.defineProperty(exports, "__esModule", { value: true });
exports.Transport = void 0;
var Transport;
(function (Transport) {
    var Document_Type;
    (function (Document_Type) {
        Document_Type["Passport"] = "\u041F\u0430\u0441\u043F\u043E\u0440\u0442";
        Document_Type["IDCard"] = "\u0423\u0434\u043E\u0441\u0442\u043E\u0432\u0435\u0440\u0435\u043D\u0438\u0435 \u043B\u0438\u0447\u043D\u043E\u0441\u0442\u0438";
    })(Document_Type = Transport.Document_Type || (Transport.Document_Type = {}));
    var Owner = /** @class */ (function () {
        function Owner(surname, name, patronymic, dateOfBirth, documentType, documentSeries, documentNumber) {
            this._surname = surname;
            this._name = name;
            this._patronymic = patronymic;
            this._dateOfBirth = dateOfBirth;
            this._documentType = documentType;
            this._documentSeries = documentSeries;
            this._documentNumber = documentNumber;
        }
        Object.defineProperty(Owner.prototype, "surname", {
            get: function () {
                return this._surname;
            },
            set: function (value) {
                this._surname = value;
            },
            enumerable: false,
            configurable: true
        });
        Object.defineProperty(Owner.prototype, "name", {
            get: function () {
                return this._name;
            },
            set: function (value) {
                this._name = value;
            },
            enumerable: false,
            configurable: true
        });
        Object.defineProperty(Owner.prototype, "patronymic", {
            get: function () {
                return this._patronymic;
            },
            set: function (value) {
                this._patronymic = value;
            },
            enumerable: false,
            configurable: true
        });
        Object.defineProperty(Owner.prototype, "dateOfBirth", {
            get: function () {
                return this._dateOfBirth;
            },
            set: function (value) {
                this._dateOfBirth = value;
            },
            enumerable: false,
            configurable: true
        });
        Object.defineProperty(Owner.prototype, "documentType", {
            get: function () {
                return this._documentType;
            },
            set: function (value) {
                this._documentType = value;
            },
            enumerable: false,
            configurable: true
        });
        Object.defineProperty(Owner.prototype, "documentSeries", {
            get: function () {
                return this._documentSeries;
            },
            set: function (value) {
                this._documentSeries = value;
            },
            enumerable: false,
            configurable: true
        });
        Object.defineProperty(Owner.prototype, "documentNumber", {
            get: function () {
                return this._documentNumber;
            },
            set: function (value) {
                this._documentNumber = value;
            },
            enumerable: false,
            configurable: true
        });
        Owner.prototype.printOwnerInfo = function () {
            console.log("\u0424\u0430\u043C\u0438\u043B\u0438\u044F: ".concat(this.surname, "\n") +
                "\u0418\u043C\u044F: ".concat(this.name, "\n") +
                "\u041E\u0442\u0447\u0435\u0441\u0442\u0432\u043E: ".concat(this.patronymic, "\n") +
                "\u0414\u0430\u0442\u0430 \u0440\u043E\u0436\u0434\u0435\u043D\u0438\u044F: ".concat(this.dateOfBirth.toString(), "\n") +
                "\u0422\u0438\u043F \u0434\u043E\u043A\u0443\u043C\u0435\u043D\u0442\u0430: ".concat(this.documentType, "\n") +
                "\u0421\u0435\u0440\u0438\u044F \u0434\u043E\u043A\u0443\u043C\u0435\u043D\u0442\u0430: ".concat(this.documentSeries, "\n") +
                "\u041D\u043E\u043C\u0435\u0440 \u0434\u043E\u043A\u0443\u043C\u0435\u043D\u0442\u0430: ".concat(this.documentNumber, "\n"));
        };
        return Owner;
    }());
    Transport.Owner = Owner;
    var Vehicle = /** @class */ (function () {
        function Vehicle(brand, model, year, vin, registrationNumber, ownerInfo) {
            this._brand = brand;
            this._model = model;
            this._year = year;
            this._vin = vin;
            this._registrationNumber = registrationNumber;
            this._ownerInfo = ownerInfo;
        }
        Object.defineProperty(Vehicle.prototype, "brand", {
            get: function () {
                return this._brand;
            },
            enumerable: false,
            configurable: true
        });
        Object.defineProperty(Vehicle.prototype, "model", {
            get: function () {
                return this._model;
            },
            enumerable: false,
            configurable: true
        });
        Object.defineProperty(Vehicle.prototype, "year", {
            get: function () {
                return this._year;
            },
            enumerable: false,
            configurable: true
        });
        Object.defineProperty(Vehicle.prototype, "vin", {
            get: function () {
                return this._vin;
            },
            enumerable: false,
            configurable: true
        });
        Object.defineProperty(Vehicle.prototype, "registrationNumber", {
            get: function () {
                return this._registrationNumber;
            },
            enumerable: false,
            configurable: true
        });
        Object.defineProperty(Vehicle.prototype, "ownerInfo", {
            get: function () {
                return this._ownerInfo;
            },
            enumerable: false,
            configurable: true
        });
        Vehicle.prototype.printVehicleInfo = function () {
            console.log("\u041C\u0430\u0440\u043A\u0430: ".concat(this.brand));
            console.log("\u041C\u043E\u0434\u0435\u043B\u044C: ".concat(this.model));
            console.log("\u0413\u043E\u0434 \u0432\u044B\u043F\u0443\u0441\u043A\u0430: ".concat(this.year));
            console.log("VIN-\u043D\u043E\u043C\u0435\u0440: ".concat(this.vin));
            console.log("\u0420\u0435\u0433\u0438\u0441\u0442\u0440\u0430\u0446\u0438\u043E\u043D\u043D\u044B\u0439 \u043D\u043E\u043C\u0435\u0440: ".concat(this.registrationNumber));
        };
        return Vehicle;
    }());
    Transport.Vehicle = Vehicle;
    // // Пример использования
    // const vehicle = new Vehicle("Audi", "A4", 2022, "1234567890", "AB123CD", "Иванов Иван Иванович");
    // vehicle.printVehicleInfo();
    // тип кузовa
    var BodyType;
    (function (BodyType) {
        BodyType["Sedan"] = "Sedan";
        BodyType["SUV"] = "SUV";
        BodyType["Hatchback"] = "Hatchback";
    })(BodyType = Transport.BodyType || (Transport.BodyType = {}));
    // класс авто
    var CarClass;
    (function (CarClass) {
        CarClass["Economy"] = "Economy";
        CarClass["Midsize"] = "Midsize";
        CarClass["Luxury"] = "Luxury";
    })(CarClass = Transport.CarClass || (Transport.CarClass = {}));
    var Car = /** @class */ (function () {
        function Car(brand, model, year, vin, registrationNumber, ownerInfo, bodyType, carClass) {
            this.brand = brand;
            this.model = model;
            this.year = year;
            this.vin = vin;
            this.registrationNumber = registrationNumber;
            this.ownerInfo = ownerInfo;
            this.bodyType = bodyType;
            this.carClass = carClass;
        }
        Car.prototype.printVehicleInfo = function () {
            console.log("Car Information - Brand: ".concat(this.brand, ", Model: ").concat(this.model, ", Type: ").concat(this.bodyType, ", Class: ").concat(this.carClass));
            console.log("Year: ".concat(this.year, ", VIN: ").concat(this.vin, ", Registration Number: ").concat(this.registrationNumber));
            console.log("Owner Info: ".concat(this.ownerInfo));
        };
        return Car;
    }());
    Transport.Car = Car;
    var Motorbike = /** @class */ (function () {
        function Motorbike(brand, model, year, vin, registrationNumber, ownerInfo, frameType, forSport) {
            this.brand = brand;
            this.model = model;
            this.year = year;
            this.vin = vin;
            this.registrationNumber = registrationNumber;
            this.ownerInfo = ownerInfo;
            this.frameType = frameType;
            this.forSport = forSport;
        }
        Motorbike.prototype.printVehicleInfo = function () {
            console.log("Motorbike Information - Brand: ".concat(this.brand, ", Model: ").concat(this.model, ", Frame Type: ").concat(this.frameType, ", For Sport: ").concat(this.forSport));
            console.log("Year: ".concat(this.year, ", VIN: ").concat(this.vin, ", Registration Number: ").concat(this.registrationNumber));
            console.log("Owner Info: ".concat(this.ownerInfo));
        };
        return Motorbike;
    }());
    Transport.Motorbike = Motorbike;
    var VehicleStorage = /** @class */ (function () {
        function VehicleStorage(creationDate, vehicles) {
            this.creationDate = creationDate;
            this.vehicles = vehicles;
        }
        VehicleStorage.prototype.getAllVehicles = function () {
            return this.vehicles;
        };
        return VehicleStorage;
    }());
    Transport.VehicleStorage = VehicleStorage;
    // const vehicles: IVehicle[] = [
    //   car, motorbike
    // ];
    // const storage = new VehicleStorage<IVehicle>(new Date(), vehicles);
    // console.log(storage.getAllVehicles());
    function sealPrototype(constructor) {
        Object.seal(constructor.prototype);
        return /** @class */ (function (_super) {
            __extends(class_1, _super);
            function class_1() {
                var args = [];
                for (var _i = 0; _i < arguments.length; _i++) {
                    args[_i] = arguments[_i];
                }
                var _this = _super.apply(this, args) || this;
                Object.seal(_this);
                return _this;
            }
            return class_1;
        }(constructor));
    }
})(Transport || (exports.Transport = Transport = {}));
// // // Интерфейс для Транспортного средства
// // interface Transport {
// //   // Метод для вывода информации
// //   printInfo(): void;
// // }
// // Интерфейс для Автомобиля
// interface ICar extends IVehicle {
//   bodyType: 'Sedan' | 'SUV' | 'Hatchback'; // Тип кузова
//   carClass: 'Economy' | 'Midsize' | 'Luxury'; // Класс автомобиля
// }
// // Класс для реализации интерфейса Автомобиля
// class Car implements ICar {
//   constructor(public bodyType: 'Sedan' | 'SUV' | 'Hatchback', public carClass: 'Economy' | 'Midsize' | 'Luxury') {}
//   _brand: string;
//   _model: string;
//   _year: number;
//   _vin: string;
//   _registrationNumber: string;
//   ownerInfo: string;
//   printVehicleInfo(): void {
//     throw new Error("Method not implemented.");
//   }
//   printInfo() {
//       console.log(`Car Information - Body Type: ${this.bodyType}, Class: ${this.carClass}`);
//   }
// }
// // Интерфейс для Мотоцикла
// interface IMotorbike extends IVehicle {
//   frameType: string; // Тип рамы
//   isSport: boolean; // Для спорта
// }
// // Класс для реализации интерфейса Мотоцикла
// class Motorbike implements IMotorbike {
//   constructor(public frameType: string, public isSport: boolean) {}
//   printInfo() {
//       console.log(`Motorbike Information - Frame Type: ${this.frameType}, Is Sport: ${this.isSport}`);
//   }
// }
// // Пример использования класса для создания и вывода информации об автомобиле
// const car = new Car('SUV', 'Luxury');
// car.printInfo();
// // Пример использования класса для создания и вывода информации о мотоцикле
// const motorbike = new Motorbike('Steel', true);
// motorbike.printInfo();
