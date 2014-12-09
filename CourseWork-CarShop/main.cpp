//
//  main.cpp
//  CourseWork-CarShop
//
//  Created by Igor Cheliadinski on 12/9/14.
//  Copyright (c) 2014 Igor Cheliadinski. All rights reserved.
//
#include "rarecar.h"
#include "newcar.h"

int main(int argc, const char * argv[]) {
    Car *car = new Car("BMW", "323", 1994, "Gazoline", "Auto", 10000.00);
    RareCar *rareCar = new RareCar("BMW", "323", 1994, "Gazoline", "Auto", 10000.00, true);
    NewCar *newCar = new NewCar("Audi", "B4", 2000, "Disel", "Mechanical", 9200.00, 2);
    
    return 0;
}
