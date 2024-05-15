export declare namespace Transport {
    enum Document_Type {
        Passport = "\u041F\u0430\u0441\u043F\u043E\u0440\u0442",
        IDCard = "\u0423\u0434\u043E\u0441\u0442\u043E\u0432\u0435\u0440\u0435\u043D\u0438\u0435 \u043B\u0438\u0447\u043D\u043E\u0441\u0442\u0438"
    }
    interface IOwner {
        surname: string;
        name: string;
        patronymic: string;
        dateOfBirth: Date;
        documentType: Document_Type;
        documentSeries: string;
        documentNumber: string;
        printOwnerInfo(): void;
    }
    class Owner implements IOwner {
        private _surname;
        private _name;
        private _patronymic;
        private _dateOfBirth;
        private _documentType;
        private _documentSeries;
        private _documentNumber;
        constructor(surname: string, name: string, patronymic: string, dateOfBirth: Date, documentType: Document_Type, documentSeries: string, documentNumber: string);
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
    interface IVehicle {
        brand: string;
        model: string;
        year: number;
        vin: string;
        registrationNumber: string;
        ownerInfo: string;
        printVehicleInfo(): void;
    }
    class Vehicle implements IVehicle {
        private _brand;
        private _model;
        private _year;
        private _vin;
        private _registrationNumber;
        private _ownerInfo;
        constructor(brand: string, model: string, year: number, vin: string, registrationNumber: string, ownerInfo: string);
        get brand(): string;
        get model(): string;
        get year(): number;
        get vin(): string;
        get registrationNumber(): string;
        get ownerInfo(): string;
        printVehicleInfo(): void;
    }
    enum BodyType {
        Sedan = "Sedan",
        SUV = "SUV",
        Hatchback = "Hatchback"
    }
    enum CarClass {
        Economy = "Economy",
        Midsize = "Midsize",
        Luxury = "Luxury"
    }
    interface ICar extends IVehicle {
        bodyType: BodyType;
        carClass: CarClass;
    }
    class Car implements ICar {
        brand: string;
        model: string;
        year: number;
        vin: string;
        registrationNumber: string;
        ownerInfo: string;
        bodyType: BodyType;
        carClass: CarClass;
        constructor(brand: string, model: string, year: number, vin: string, registrationNumber: string, ownerInfo: string, bodyType: BodyType, carClass: CarClass);
        printVehicleInfo(): void;
    }
    interface IMotorbike extends IVehicle {
        frameType: string;
        forSport: boolean;
    }
    class Motorbike implements IMotorbike {
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
    class VehicleStorage<T extends IVehicle> implements VehicleStorage<T> {
        creationDate: Date;
        vehicles: T[];
        constructor(creationDate: Date, vehicles: T[]);
        getAllVehicles(): T[];
    }
}
