declare enum Document_Type {
    Passport = "\u041F\u0430\u0441\u043F\u043E\u0440\u0442",
    IDCard = "\u0423\u0434\u043E\u0441\u0442\u043E\u0432\u0435\u0440\u0435\u043D\u0438\u0435 \u043B\u0438\u0447\u043D\u043E\u0441\u0442\u0438"
}
interface IOwner {
    surname: string;
    name: string;
    secondName: string;
    dateOfBirth: Date;
    documentType: Document_Type;
    documentSeries: string;
    documentNumber: string;
    printOwnerInfo(): void;
}
declare class Owner implements IOwner {
    private _surname;
    private _name;
    private _secondName;
    private _dateOfBirth;
    private _documentType;
    private _documentSeries;
    private _documentNumber;
    static surname: string;
    static secondName: string;
    constructor(surname: string, name: string, secondName: string, dateOfBirth: Date, documentType: Document_Type, documentSeries: string, documentNumber: string);
    secondName: string;
    get surname(): string;
    set surname(value: string);
    get name(): string;
    set name(value: string);
    get patronymic(): string;
    set patronymic(value: string);
    get dateOfBirth(): Date;
    set dateOfBirth(value: Date);
    get documentType(): Document_Type;
    set documentType(value: Document_Type);
    get documentSeries(): string;
    set documentSeries(value: string);
    get documentNumber(): string;
    set documentNumber(value: string);
    printOwnerInfo(): void;
}
declare const owner: IOwner;
interface IVehicle {
    brand: string;
    model: string;
    year: number;
    vin: string;
    registrationNumber: string;
    ownerInfo: string;
    printVehicleInfo(): void;
}
declare class Vehicle implements IVehicle {
    private _brand;
    private _model;
    private _year;
    private _vin;
    private _registrationNumber;
    private _ownerInfo;
    private _owner;
    constructor(brand: string, model: string, year: number, vin: string, registrationNumber: string, ownerInfo: string);
    get brand(): string;
    get model(): string;
    get year(): number;
    get vin(): string;
    get registrationNumber(): string;
    get ownerInfo(): string;
    get owner(): IOwner;
    set owner(value: IOwner);
    printVehicleInfo(): void;
    getVehicle(): string;
}
declare const vehicle: Vehicle;
declare enum BodyType {
    Sedan = "Sedan",
    SUV = "SUV",
    Hatchback = "Hatchback"
}
declare enum CarClass {
    Economy = "Economy",
    Midsize = "Midsize",
    Luxury = "Luxury"
}
interface ICar extends IVehicle {
    bodyType: BodyType;
    carClass: CarClass;
}
declare function sealed(constructor: Function): void;
declare function upperCase(target: any, propertyKey: string, descriptor: PropertyDescriptor): PropertyDescriptor;
declare class Car extends Vehicle implements ICar {
    bodyType: BodyType;
    private _typeOfBody;
    private _carClass;
    get typeOfBody(): BodyType;
    set typeOfBody(value: BodyType);
    get carClass(): CarClass;
    set carClass(value: CarClass);
    constructor(brand: string, model: string, year: number, vin: string, registrationNumber: string, ownerInfo: string, carclass: CarClass, bodytype: BodyType);
    getOwnerInfo(): string;
}
declare const myCar: Car;
declare let info: string;
interface IMotorbike extends IVehicle {
    frameType: string;
    forSport: boolean;
}
declare class Motorbike implements IMotorbike {
    brand: string;
    model: string;
    year: number;
    vin: string;
    registrationNumber: string;
    ownerInfo: string;
    frameType: string;
    forSport: boolean;
    constructor(brand: string, model: string, year: number, vin: string, registrationNumber: string, ownerInfo: string, frameType: string, forSport: boolean);
    printVehicleInfo(): void;
}
interface IVehicleStorage<T extends IVehicle> {
    creationDate: Date;
    vehicles: T[];
    getAllVehicles(): T[];
}
declare class VehicleStorage<T extends IVehicle> implements VehicleStorage<T> {
    creationDate: Date;
    vehicles: T[];
    constructor(creationDate: Date, vehicles: T[]);
    getAllVehicles(): T[];
    sortVehiclesByBrand(): T[];
    filterVehicles(brand: string): T[];
}
declare const motorbike1: Motorbike;
declare const motorbike2: Motorbike;
declare const motorbike3: Motorbike;
declare const vehicleStorage: VehicleStorage<IVehicle>;
declare const sortedVehicles: IVehicle[];
declare const filterVehicles: IVehicle[];
