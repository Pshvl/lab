"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var lab3_1 = require("./lab3");
var Owner = lab3_1.Transport.Owner;
var Car = lab3_1.Transport.Car;
var Motorbike = lab3_1.Transport.Motorbike;
var VehicleStorage = lab3_1.Transport.VehicleStorage;
var Document_Type = lab3_1.Transport.Document_Type;
var BodyType = lab3_1.Transport.BodyType;
var CarClass = lab3_1.Transport.CarClass;
var owner = new Owner("Иванов", "Иван", "Иванович", new Date(), Document_Type.Passport, "1234", "567890");
owner.printOwnerInfo();
var bike = new Motorbike('Honda', 'CBR600RR', 2020, '987654321', 'XYZ456', 'Jane Smith', 'Aluminum', true);
var car = new Car('Toyota', 'Camry', 2021, '123456789', 'ABC123', 'John Doe', BodyType.Sedan, CarClass.Midsize);
var vehicles = [
    car, bike
];
var storage = new VehicleStorage(new Date(), vehicles);
console.log(storage.getAllVehicles());
