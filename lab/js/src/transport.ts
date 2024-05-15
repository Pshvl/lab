import { Transport } from "./lab3";
import IOwner =Transport.IOwner;
import IVehicle =Transport.IVehicle;
import ICar = Transport.ICar;
import IMotorbike =Transport.IMotorbike;
import IVehicleStorage =Transport.IVehicleStorage;

import Owner =Transport.Owner;
import Vehicle =Transport.Vehicle;
import Car = Transport.Car;
import Motorbike =Transport.Motorbike;
import VehicleStorage =Transport.VehicleStorage;

import Document_Type=Transport.Document_Type;
import BodyType=Transport.BodyType;
import CarClass=Transport.CarClass;


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
const bike: IMotorbike = new Motorbike('Honda', 'CBR600RR', 2020, '987654321', 'XYZ456', 'Jane Smith', 'Aluminum', true);


const car:ICar= new Car('Toyota', 'Camry', 2021, '123456789', 'ABC123', 'John Doe', BodyType.Sedan, CarClass.Midsize);

const vehicles: IVehicle[] = [
    car, bike
  ];
const storage = new VehicleStorage<IVehicle>(new Date(), vehicles);
console.log(storage.getAllVehicles());