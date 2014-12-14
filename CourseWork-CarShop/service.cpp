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
#include <sstream>
#include <string>
#include <list>
#include <math.h>

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
        ofstream output;
        output.open("usedCars.txt", std::ios_base::app);
        output << car->getMark() + " ";
        output << car->getModel() + " ";
        output << to_string( car->getYear() ) + " ";
        output << car->getFuelType() + " ";
        output << car->getTransmission() + " ";
        output << to_string( car->getPrice() ) + " ";
        output << car->getCondition();
        output << endl;
        output.close();
        cout << "Success! Used car has been added!" << endl;
//        ifstream input;
//        input.open("usedCars.txt");
//        while (input >> mark >> model >> year >> fuelType >> transmission >> price >> condition) {
//            cout << mark;
//        }
        
    } else if (type == 2) {
        int guarantee;
        
        cout << "Guarantee (How many years): ";
        cin >> guarantee;
        
        NewCar *car = new NewCar(mark, model, year, fuelType, transmission, price, guarantee);
        ofstream output;
        output.open("newCars.txt", std::ios_base::app);
        output << car->getMark() + " ";
        output << car->getModel() + " ";
        output << to_string( car->getYear() ) + " ";
        output << car->getFuelType() + " ";
        output << car->getTransmission() + " ";
        output << to_string( car->getPrice() ) + " ";
        output << to_string( car->getGuarantee() );
        output << endl;
        output.close();
        cout << "Success! New car has been added!" << endl;
    } else if (type == 3) {
        string hasPersonalDriver;
        
        cout << "Have car personal driver? ";
        cin >> hasPersonalDriver;
        
        RareCar *car = new RareCar(mark, model, year, fuelType, transmission, price, hasPersonalDriver);
        ofstream output;
        output.open("rareCars.txt", std::ios_base::app);
        output << car->getMark() + " ";
        output << car->getModel() + " ";
        output << to_string( car->getYear() ) + " ";
        output << car->getFuelType() + " ";
        output << car->getTransmission() + " ";
        output << to_string( car->getPrice() ) + " ";
        output << car->getPersonalDriverInfo();
        output << endl;
        output.close();
        cout << "Success! Rare car has been added!" << endl;
    }
    cout << "Write any char to continue...";
}