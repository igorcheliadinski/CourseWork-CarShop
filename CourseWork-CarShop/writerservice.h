//
//  writerservice.h
//  CourseWork-CarShop
//
//  Created by Igor Cheliadinski on 12/16/14.
//  Copyright (c) 2014 Igor Cheliadinski. All rights reserved.
//

#ifndef __CourseWork_CarShop__writerservice__
#define __CourseWork_CarShop__writerservice__

#include "usedcar.h"
#include "newcar.h"
#include "rarecar.h"

void saveCar(UsedCar*);
void saveCar(NewCar*);
void saveCar(RareCar*);

void updateCar(UsedCar*, string, string, int, string, string, double, string);
void updateCar(NewCar*, string, string, int, string, string, double, int);
void updateCar(RareCar*, string, string, int, string, string, double, string);

#endif /* defined(__CourseWork_CarShop__writerservice__) */
