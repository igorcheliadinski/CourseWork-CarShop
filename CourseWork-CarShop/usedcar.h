//
//  usedcar.h
//  CourseWork-CarShop
//
//  Created by Igor Cheliadinski on 12/10/14.
//  Copyright (c) 2014 Igor Cheliadinski. All rights reserved.
//

#ifndef __CourseWork_CarShop__usedcar__
#define __CourseWork_CarShop__usedcar__

#include "car.h"

class UsedCar : public Car {
private:
    string _condition;
    
public:
    UsedCar(string make, string model, int year, string fuelType, string transmission, double price, string condition);
    
    string getCondition(void);
    void setCondition(string);
};

istream& operator>>(istream& is, UsedCar& car);
ostream& operator<<(ostream& os, const UsedCar& car);

#endif /* defined(__CourseWork_CarShop__usedcar__) */
