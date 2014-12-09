//
//  rarecar.h
//  CourseWork-CarShop
//
//  Created by Igor Cheliadinski on 12/9/14.
//  Copyright (c) 2014 Igor Cheliadinski. All rights reserved.
//

#ifndef __CourseWork_CarShop__rarecar__
#define __CourseWork_CarShop__rarecar__

#include "car.h"
#include <iostream>
#include <string.h>
using namespace std;

// Class for rare cars
class RareCar : public Car {
private:
    bool _hasPersonalDriver;
    
public:
    RareCar(string make, string model, int year, string fuelType, string transmission, double price, bool hasPersonalDriver);
    
    bool getPersonalDriverInfo(void);
    void setPersonalDriverInfo(bool);
};

#endif /* defined(__CourseWork_CarShop__rarecar__) */
