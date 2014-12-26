//
//  writerservice.cpp
//  CourseWork-CarShop
//
//  Created by Igor Cheliadinski on 12/16/14.
//  Copyright (c) 2014 Igor Cheliadinski. All rights reserved.
//

#include <fstream>
#include "writerservice.h"

void saveCar(UsedCar* car) {
    ofstream output;
    output.open("usedCars.txt", std::ios_base::app);
    output << car -> getMark() + " ";
    output << car -> getModel() + " ";
    output << to_string( car -> getYear() ) + " ";
    output << car -> getFuelType() + " ";
    output << car -> getTransmission() + " ";
    output << to_string( car -> getPrice() ) + " ";
    output << car -> getCondition();
    output << endl;
    output.close();
}

void saveCar(NewCar* car) {
    ofstream output;
    output.open("newCars.txt", std::ios_base::app);
    output << car -> getMark() + " ";
    output << car -> getModel() + " ";
    output << to_string( car -> getYear() ) + " ";
    output << car -> getFuelType() + " ";
    output << car -> getTransmission() + " ";
    output << to_string( car -> getPrice() ) + " ";
    output << to_string( car -> getGuarantee() );
    output << endl;
    output.close();
}

void saveCar(RareCar* car) {
    ofstream output;
    output.open("rareCars.txt", std::ios_base::app);
    output << car -> getMark() + " ";
    output << car -> getModel() + " ";
    output << to_string( car -> getYear() ) + " ";
    output << car -> getFuelType() + " ";
    output << car -> getTransmission() + " ";
    output << to_string( car -> getPrice() ) + " ";
    output << car -> getPersonalDriverInfo();
    output << endl;
    output.close();
}

void updateCar(UsedCar* car, string newMark, string newModel, int newYear, string newFuelType, string newTransmission, double newPrice, string newCondition) {
    car -> setMark(newMark);
    car -> setModel(newModel);
    car -> setYear(newYear);
    car -> setFuelType(newFuelType);
    car -> setTransmission(newTransmission);
    car -> setPrice(newPrice);
    car -> setCondition(newCondition);
}

void updateCar(NewCar* car, string newMark, string newModel, int newYear, string newFuelType, string newTransmission, double newPrice, int newGuarantee) {
    car -> setMark(newMark);
    car -> setModel(newModel);
    car -> setYear(newYear);
    car -> setFuelType(newFuelType);
    car -> setTransmission(newTransmission);
    car -> setPrice(newPrice);
    car -> setGuarantee(newGuarantee);
}

void updateCar(RareCar* car, string newMark, string newModel, int newYear, string newFuelType, string newTransmission, double newPrice, string newPersonalDriver) {
    car -> setMark(newMark);
    car -> setModel(newModel);
    car -> setYear(newYear);
    car -> setFuelType(newFuelType);
    car -> setTransmission(newTransmission);
    car -> setPrice(newPrice);
    car -> setPersonalDriverInfo(newPersonalDriver);
}