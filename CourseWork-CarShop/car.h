//
//  car.h
//  CourseWork-CarShop
//
//  Created by Igor Cheliadinski on 12/9/14.
//  Copyright (c) 2014 Igor Cheliadinski. All rights reserved.
//

#ifndef __CourseWork_CarShop__car__
#define __CourseWork_CarShop__car__

#include <iostream>
#include <string.h>
using namespace std;

// Car class
class Car {
    
private:
    string _mark;
    string _model;
    int _year;
    string _fuelType;
    string _transmission;
    double _price;
    Car() {}
    
public:
    Car(string mark, string model, int year, string fuelType, string transmission, double price);
    
    string getMark(void);
    void setMark(string);
    
    string getModel(void);
    void setModel(string);
    
    int getYear(void);
    void setYear(int);
    
    string getFuelType(void);
    void setFuelType(string);
    
    string getTransmission(void);
    void setTransmission(string);
    
    double getPrice(void);
    void setPrice(double);
};

#endif /* defined(__CourseWork_CarShop__car__) */