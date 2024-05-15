
  
 enum Document_Type {
    Passport = "Паспорт",
    IDCard = "Удостоверение личности"
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
  
   class Owner implements IOwner {
    private _surname: string;
    private _name: string;
    private _secondName: string;
    private _dateOfBirth: Date;
    private _documentType: Document_Type;
    private _documentSeries: string;
    private _documentNumber: string;
     static surname: string;
     static secondName: string;
  
    constructor(surname: string,name: string,secondName: string,dateOfBirth: Date,documentType: Document_Type,documentSeries: string,documentNumber: string
    ) 
    {
      this._surname = surname;
      this._name = name;
      this._secondName = secondName;
      this._dateOfBirth = dateOfBirth;
      this._documentType = documentType;
      this._documentSeries = documentSeries;
      this._documentNumber = documentNumber;
    }
     secondName: string;
  
    get surname(): string {
      return this._surname;
    }
  
    set surname(value: string) {
      this._surname = value;
    }
  
    get name(): string {
      return this._name;
    }
  
    set name(value: string) {
      this._name = value;
    }
  
    get patronymic(): string {
      return this._secondName;
    }
  
    set patronymic(value: string) {
      this._secondName = value;
    }
  
    get dateOfBirth(): Date {
      return this._dateOfBirth;
    }
  
    set dateOfBirth(value: Date) {
      this._dateOfBirth = value;
    }
  
    get documentType(): Document_Type {
      return this._documentType;
    }
  
    set documentType(value: Document_Type) {
      this._documentType = value;
    }
  
    get documentSeries(): string {
      return this._documentSeries;
    }
  
    set documentSeries(value: string) {
      this._documentSeries = value;
    }
  
    get documentNumber(): string {
      return this._documentNumber;
    }
  
    set documentNumber(value: string) {
      this._documentNumber = value;
    }
  
    printOwnerInfo(): void {
      console.log(
        `Фамилия: ${this.surname}\n` +
        `Имя: ${this.name}\n` +
        `Отчество: ${this.secondName}\n` +
        `Дата рождения: ${this.dateOfBirth.toString()}\n` +
        `Тип документа: ${this.documentType}\n` +
        `Серия документа: ${this.documentSeries}\n` +
        `Номер документа: ${this.documentNumber}\n`
      );
    }
  }
  
  // // Создаем объект и выводим информацию в консоль
  const owner: IOwner = new Owner(
    "Иванов",
    "Иван",
    "Иванович",
    new Date(),
    Document_Type.Passport,
    "1234",
    "567890"
  );
  
  owner.printOwnerInfo();
  
  
  
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
    private _brand: string;
    private _model: string;
    private _year: number;
    private _vin: string;
    private _registrationNumber: string;
    private _ownerInfo: string;
    private _owner: IOwner;
  
    constructor(
      brand: string,
      model: string,
      year: number,
      vin: string,
      registrationNumber: string,
      ownerInfo: string
      
      
    ) {
      this._brand = brand;
      this._model = model;
      this._year = year;
      this._vin = vin;
      this._registrationNumber = registrationNumber;
      this._ownerInfo = ownerInfo;
      this._owner = owner;
    }
  
    get brand(): string {
      return this._brand;
    }
  
    get model(): string {
      return this._model;
    }
  
    get year(): number {
      return this._year;
    }
  
    get vin(): string {
      return this._vin;
    }
  
    get registrationNumber(): string {
      return this._registrationNumber;
    }
  
    get ownerInfo(): string {
      return this._ownerInfo;
    }
    
    public get owner(): IOwner {
      return this._owner;
  }
  public set owner(value: IOwner) {
      this._owner = value;
  }
  
    printVehicleInfo(): void {
      console.log(`Марка: ${this.brand}`);
      console.log(`Модель: ${this.model}`);
      console.log(`Год выпуска: ${this.year}`);
      console.log(`VIN-номер: ${this.vin}`);
      console.log(`Регистрационный номер: ${this.registrationNumber}`);
    }
    getVehicle(): string {
      return `VIN: ${this.vin}, ФИО владельца: ${this.ownerInfo}, Регистрационный номер: ${this.registrationNumber}`;
    }
  }
  
  // // Пример использования
  const vehicle = new Vehicle("Audi", "A4", 2022, "1234567890", "AB123CD", "Иванов Иван Иванович");
  console.log( vehicle.getVehicle());
  
  
  
  // тип кузовa
 enum BodyType {
    Sedan = 'Sedan',
    SUV = 'SUV',
    Hatchback = 'Hatchback'
  }
  
  // класс авто
   enum CarClass {
    Economy = 'Economy',
    Midsize = 'Midsize',
    Luxury = 'Luxury'
  }
  
  
  // Интерфейс для Автомобиля, наследующий от IVehicle
   interface ICar extends IVehicle {
    bodyType: BodyType;
    carClass: CarClass;
  }
  
  


function sealed(constructor: Function) {
    console.log("sealed decorator");
    Object.seal(constructor);
    Object.seal(constructor.prototype);
   }
   

   function upperCase(target: any, propertyKey: string, descriptor: PropertyDescriptor) {
    const originalMethod = descriptor.value;
  
    descriptor.value = function() {
      const result = originalMethod.apply(this);
      if (typeof result === 'string') {
        return result.toUpperCase();
      }
      return result;
    };
  
    return descriptor;
  }

@sealed
   class Car extends Vehicle  implements ICar {
    bodyType: BodyType;
    private _typeOfBody: BodyType;
    private _carClass: CarClass;

    public get typeOfBody(): BodyType {
        return this._typeOfBody;
    }
    public set typeOfBody(value: BodyType) {
        this._typeOfBody = value;
    }

    public get carClass(): CarClass {
        return this._carClass;
    }
    public set carClass(value: CarClass) {
        this._carClass = value;
    }
    constructor(brand: string, model: string, year: number, vin: string, registrationNumber: string, ownerInfo: string, carclass: CarClass, bodytype: BodyType) {
      super(brand, model, year, vin, registrationNumber, ownerInfo);
      this._carClass = carclass;
      this._typeOfBody = bodytype;
  }
  
    // printVehicleInfo() {
    //   console.log(`Car Information - Brand: ${this.brand}, Model: ${this.model}, Type: ${this.bodyType}, Class: ${this.carClass}`);
    //   console.log(`Year: ${this.year}, VIN: ${this.vin}, Registration Number: ${this.registrationNumber}`);
    //   console.log(`Owner Info: ${this.ownerInfo}`);
    // }
    @upperCase
    getOwnerInfo(): string {
        let owner = this.owner;
        return owner.name + " " + owner.surname + " " + owner.secondName + " " + owner.dateOfBirth;
    }

    
  }
  
  const myCar = new Car('Toyota', 'Camry', 2021, '123456789', 'AB123CD', 'John Doe', CarClass.Midsize, BodyType.Sedan);
  let info = myCar.getOwnerInfo();
  console.log(info);
  
  
  
  
  
  
   interface IMotorbike extends IVehicle {
    frameType: string;
    forSport: boolean;
  }
  
   class Motorbike implements IMotorbike {
    constructor(
      public brand: string,
      public model: string,
      public year: number,
      public vin: string,
      public registrationNumber: string,
      public ownerInfo: string,
      public frameType: string,
      public forSport: boolean
    ) {}
    printVehicleInfo() {
      console.log(`Motorbike Information - Brand: ${this.brand}, Model: ${this.model}, Frame Type: ${this.frameType}, For Sport: ${this.forSport}`);
      console.log(`Year: ${this.year}, VIN: ${this.vin}, Registration Number: ${this.registrationNumber}`);
      console.log(`Owner Info: ${this.ownerInfo}`);
    }
  }
  
  // // Пример использования класса MotorbikeImpl
  // const motorbike = new Motorbike('Honda', 'CBR600RR', 2020, '987654321', 'XYZ456', 'Jane Smith', 'Aluminum', true);
  // motorbike.printVehicleInfo();
  
  
  
   interface IVehicleStorage<T extends IVehicle> {
    creationDate: Date;
    vehicles: T[];

    
    getAllVehicles(): T[];
  }
  
   class VehicleStorage<T extends IVehicle> implements VehicleStorage<T> {
    constructor(public creationDate: Date, public vehicles: T[]) {}
  
    getAllVehicles(): T[] {
      return this.vehicles;
    }
    sortVehiclesByBrand(): T[] {
      return this.vehicles.sort((a, b) => a.brand.localeCompare(b.brand));


    }

    filterVehicles(brand:string) : T[] {
      return this.vehicles.filter(vehicle=>vehicle.brand.startsWith(brand))
    }
  }
  
  const motorbike1 = new Motorbike('Honda', 'CBR600RR', 2020, '987654321', 'XYZ456', 'Jane Smith', 'Aluminum', true);
  const motorbike2 = new Motorbike('Konda', 'CBR600RR', 2020, '987654321', 'XYZ456', 'Jane Smith', 'Aluminum', true);
  const motorbike3 = new Motorbike('Bonda', 'CBR600RR', 2020, '987654321', 'XYZ456', 'Jane Smith', 'Aluminum', true);


// Создание экземпляра класса VehicleStorage
const vehicleStorage = new VehicleStorage<IVehicle>(new Date(), [motorbike1, motorbike2,motorbike3]);

// Получение отсортированного массива транспортных средств по марке
const sortedVehicles = vehicleStorage.sortVehiclesByBrand();
const filterVehicles = vehicleStorage.filterVehicles('Bo');

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
  
  
  
  
  
  