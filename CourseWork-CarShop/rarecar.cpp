//
//  rarecar.cpp
//  CourseWork-CarShop
//
//  Created by Igor Cheliadinski on 12/9/14.
//  Copyright (c) 2014 Igor Cheliadinski. All rights reserved.
//

#include "rarecar.h"

RareCar::RareCar(string make, string model, int year, string fuelType, string transmission, double price, string hasPersonalDriver) : Car(make, model, year, fuelType, transmission, price) {
    this->_hasPersonalDriver = hasPersonalDriver;
}

// Getter and setter for personal driver with car
string RareCar::getPersonalDriverInfo(void) {
    return this->_hasPersonalDriver;
}
void RareCar::setPersonalDriverInfo(string hasPersonalDriver) {
    this->_hasPersonalDriver = hasPersonalDriver;
}