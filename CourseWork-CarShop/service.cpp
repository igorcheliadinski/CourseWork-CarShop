//
//  service.cpp
//  CourseWork-CarShop
//
//  Created by Igor Cheliadinski on 12/10/14.
//  Copyright (c) 2014 Igor Cheliadinski. All rights reserved.
//

#include "service.h"
#include "rarecar.h"
#include "newcar.h"
#include "usedcar.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <list>

void sellCar() {
    string mark, model, fuelType, transmission;
    int year, type;
    double price;

    cout << "Please enter details for your car:" << endl;

    cout << "Mark: ";
    cin >> mark;

    cout << "Model: ";
    cin >> model;

    cout << "Year: ";
    cin >> year;

    cout << "Fuel Type: ";
    cin >> fuelType;

    cout << "Transmission: ";
    cin >> transmission;

    cout << "Price: ";
    cin >> price;
    
    cout << "Which type your car of?" << endl;
    cout << "1) Used car\n2) New car\n3) Rare car" << endl;
    cin >> type;
    
    if (type == 1) {
        string condition;
        
        cout << "Car condition (Bad, Good, Wonderful): ";
        cin >> condition;
        
        UsedCar *car = new UsedCar(mark, model, year, fuelType, transmission, price, condition);
        list<UsedCar*> dataSet;
        dataSet.insert(dataSet.begin(), car);
        ofstream output;
        output.open("zelenka.bin", std::ios_base::app);
        output << &dataSet;
        output.close();
        ifstream input;
        input.open("zelenka.bin");
    } else if (type == 2) {
        int guarantee;
        
        cout << "Guarantee (How many years): ";
        cin >> guarantee;
        
        NewCar *car = new NewCar(mark, model, year, fuelType, transmission, price, guarantee);
    } else if (type == 3) {
        bool hasPersonalDriver;
        
        cout << "Have car personal driver? ";
        cin >> hasPersonalDriver;
        
        RareCar *car = new RareCar(mark, model, year, fuelType, transmission, price, hasPersonalDriver);
    }
}