//
//  readerservice.cpp
//  CourseWork-CarShop
//
//  Created by Igor Cheliadinski on 12/16/14.
//  Copyright (c) 2014 Igor Cheliadinski. All rights reserved.
//

#include <fstream>
#include <list>
#include "readerservice.h"

//UsedCar findUsedCar(string mark, string model, int year, string fuelType, string transmission, double price, string condition);
//NewCar findNewCar(string mark, string model, int year, string fuelType, string transmission, double price, int guarantee);
//RareCar findRareCar(string mark, string model, int year, string fuelType, string transmission, double price, string personalDriver);

UsedCar findUsedCar(string mark, string model, int year, string fuelType, string transmission, double price, string condition) {
    list<UsedCar*> cars;
    
    ifstream input("usedCars.txt");
}