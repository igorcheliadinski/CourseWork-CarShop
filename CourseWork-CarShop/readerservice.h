//
//  readerservice.h
//  CourseWork-CarShop
//
//  Created by Igor Cheliadinski on 12/16/14.
//  Copyright (c) 2014 Igor Cheliadinski. All rights reserved.
//

#ifndef __CourseWork_CarShop__readerservice__
#define __CourseWork_CarShop__readerservice__

#include "usedcar.h"
#include "newcar.h"
#include "rarecar.h"

#include <stdio.h>

UsedCar findUsedCar(string mark, string model, int year, string fuelType, string transmission, double price, string condition);
NewCar findNewCar(string mark, string model, int year, string fuelType, string transmission, double price, int guarantee);
RareCar findRareCar(string mark, string model, int year, string fuelType, string transmission, double price, string personalDriver);

#endif /* defined(__CourseWork_CarShop__readerservice__) */
