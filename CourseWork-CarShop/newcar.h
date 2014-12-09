//
//  newcar.h
//  CourseWork-CarShop
//
//  Created by Igor Cheliadinski on 12/10/14.
//  Copyright (c) 2014 Igor Cheliadinski. All rights reserved.
//

#ifndef __CourseWork_CarShop__newcar__
#define __CourseWork_CarShop__newcar__

#include "car.h"

// Class for new cars
class NewCar : public Car {
private:
    int _guarantee;
    
public:
    NewCar(string make, string model, int year, string fuelType, string transmission, double price, int guarantee);
    
    int getGuarantee(void);
    void setGuarantee(int);
};

#endif /* defined(__CourseWork_CarShop__newcar__) */
