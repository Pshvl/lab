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
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var Document_Type;
(function (Document_Type) {
    Document_Type["Passport"] = "\u041F\u0430\u0441\u043F\u043E\u0440\u0442";
    Document_Type["IDCard"] = "\u0423\u0434\u043E\u0441\u0442\u043E\u0432\u0435\u0440\u0435\u043D\u0438\u0435 \u043B\u0438\u0447\u043D\u043E\u0441\u0442\u0438";
})(Document_Type || (Document_Type = {}));
var Owner = /** @class */ (function () {
    function Owner(surname, name, secondName, dateOfBirth, documentType, documentSeries, documentNumber) {
        this._surname = surname;
        this._name = name;
        this._secondName = secondName;
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
            return this._secondName;
        },
        set: function (value) {
            this._secondName = value;
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
            "\u041E\u0442\u0447\u0435\u0441\u0442\u0432\u043E: ".concat(this.secondName, "\n") +
            "\u0414\u0430\u0442\u0430 \u0440\u043E\u0436\u0434\u0435\u043D\u0438\u044F: ".concat(this.dateOfBirth.toString(), "\n") +
            "\u0422\u0438\u043F \u0434\u043E\u043A\u0443\u043C\u0435\u043D\u0442\u0430: ".concat(this.documentType, "\n") +
            "\u0421\u0435\u0440\u0438\u044F \u0434\u043E\u043A\u0443\u043C\u0435\u043D\u0442\u0430: ".concat(this.documentSeries, "\n") +
            "\u041D\u043E\u043C\u0435\u0440 \u0434\u043E\u043A\u0443\u043C\u0435\u043D\u0442\u0430: ".concat(this.documentNumber, "\n"));
    };
    return Owner;
}());
// // Создаем объект и выводим информацию в консоль
var owner = new Owner("Иванов", "Иван", "Иванович", new Date(), Document_Type.Passport, "1234", "567890");
owner.printOwnerInfo();
var Vehicle = /** @class */ (function () {
    function Vehicle(brand, model, year, vin, registrationNumber, ownerInfo) {
        this._brand = brand;
        this._model = model;
        this._year = year;
        this._vin = vin;
        this._registrationNumber = registrationNumber;
        this._ownerInfo = ownerInfo;
        this._owner = owner;
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
    Object.defineProperty(Vehicle.prototype, "owner", {
        get: function () {
            return this._owner;
        },
        set: function (value) {
            this._owner = value;
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
    Vehicle.prototype.getVehicle = function () {
        return "VIN: ".concat(this.vin, ", \u0424\u0418\u041E \u0432\u043B\u0430\u0434\u0435\u043B\u044C\u0446\u0430: ").concat(this.ownerInfo, ", \u0420\u0435\u0433\u0438\u0441\u0442\u0440\u0430\u0446\u0438\u043E\u043D\u043D\u044B\u0439 \u043D\u043E\u043C\u0435\u0440: ").concat(this.registrationNumber);
    };
    return Vehicle;
}());
// // Пример использования
var vehicle = new Vehicle("Audi", "A4", 2022, "1234567890", "AB123CD", "Иванов Иван Иванович");
console.log(vehicle.getVehicle());
// тип кузовa
var BodyType;
(function (BodyType) {
    BodyType["Sedan"] = "Sedan";
    BodyType["SUV"] = "SUV";
    BodyType["Hatchback"] = "Hatchback";
})(BodyType || (BodyType = {}));
// класс авто
var CarClass;
(function (CarClass) {
    CarClass["Economy"] = "Economy";
    CarClass["Midsize"] = "Midsize";
    CarClass["Luxury"] = "Luxury";
})(CarClass || (CarClass = {}));
function sealed(constructor) {
    console.log("sealed decorator");
    Object.seal(constructor);
    Object.seal(constructor.prototype);
}
function upperCase(target, propertyKey, descriptor) {
    var originalMethod = descriptor.value;
    descriptor.value = function () {
        var result = originalMethod.apply(this);
        if (typeof result === 'string') {
            return result.toUpperCase();
        }
        return result;
    };
    return descriptor;
}
var Car = /** @class */ (function (_super) {
    __extends(Car, _super);
    function Car(brand, model, year, vin, registrationNumber, ownerInfo, carclass, bodytype) {
        var _this = _super.call(this, brand, model, year, vin, registrationNumber, ownerInfo) || this;
        _this._carClass = carclass;
        _this._typeOfBody = bodytype;
        return _this;
    }
    Object.defineProperty(Car.prototype, "typeOfBody", {
        get: function () {
            return this._typeOfBody;
        },
        set: function (value) {
            this._typeOfBody = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Car.prototype, "carClass", {
        get: function () {
            return this._carClass;
        },
        set: function (value) {
            this._carClass = value;
        },
        enumerable: false,
        configurable: true
    });
    // printVehicleInfo() {
    //   console.log(`Car Information - Brand: ${this.brand}, Model: ${this.model}, Type: ${this.bodyType}, Class: ${this.carClass}`);
    //   console.log(`Year: ${this.year}, VIN: ${this.vin}, Registration Number: ${this.registrationNumber}`);
    //   console.log(`Owner Info: ${this.ownerInfo}`);
    // }
    Car.prototype.getOwnerInfo = function () {
        var owner = this.owner;
        return owner.name + " " + owner.surname + " " + owner.secondName + " " + owner.dateOfBirth;
    };
    __decorate([
        upperCase
    ], Car.prototype, "getOwnerInfo", null);
    Car = __decorate([
        sealed
    ], Car);
    return Car;
}(Vehicle));
var myCar = new Car('Toyota', 'Camry', 2021, '123456789', 'AB123CD', 'John Doe', CarClass.Midsize, BodyType.Sedan);
var info = myCar.getOwnerInfo();
console.log(info);
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
var VehicleStorage = /** @class */ (function () {
    function VehicleStorage(creationDate, vehicles) {
        this.creationDate = creationDate;
        this.vehicles = vehicles;
    }
    VehicleStorage.prototype.getAllVehicles = function () {
        return this.vehicles;
    };
    VehicleStorage.prototype.sortVehiclesByBrand = function () {
        return this.vehicles.sort(function (a, b) { return a.brand.localeCompare(b.brand); });
    };
    VehicleStorage.prototype.filterVehicles = function (brand) {
        return this.vehicles.filter(function (vehicle) { return vehicle.brand.startsWith(brand); });
    };
    return VehicleStorage;
}());
var motorbike1 = new Motorbike('Honda', 'CBR600RR', 2020, '987654321', 'XYZ456', 'Jane Smith', 'Aluminum', true);
var motorbike2 = new Motorbike('Konda', 'CBR600RR', 2020, '987654321', 'XYZ456', 'Jane Smith', 'Aluminum', true);
var motorbike3 = new Motorbike('Bonda', 'CBR600RR', 2020, '987654321', 'XYZ456', 'Jane Smith', 'Aluminum', true);
// Создание экземпляра класса VehicleStorage
var vehicleStorage = new VehicleStorage(new Date(), [motorbike1, motorbike2, motorbike3]);
// Получение отсортированного массива транспортных средств по марке
var sortedVehicles = vehicleStorage.sortVehiclesByBrand();
var filterVehicles = vehicleStorage.filterVehicles('Bo');
console.log(filterVehicles);
console.log('kfjhkdjfffdjfk');
// Вывод отсортированного массива транспортных средств
console.log(sortedVehicles);
// const vehicles: IVehicle[] = [
//   car, motorbike
// ];
// const storage = new VehicleStorage(new Date(), vehicles);
// console.log(storage.getAllVehicles());
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
