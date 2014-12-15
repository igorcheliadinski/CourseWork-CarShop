//
//  main.cpp
//  CourseWork-CarShop
//
//  Created by Igor Cheliadinski on 12/9/14.
//  Copyright (c) 2014 Igor Cheliadinski. All rights reserved.
//
#include "rarecar.h"
#include "newcar.h"
#include "usedcar.h"
#include "service.h"

int main(int argc, const char * argv[]) {
    // Car *car = new Car("BMW", "323", 1994, "Gazoline", "Auto", 10000.00);
    // RareCar *rareCar = new RareCar("BMW", "323", 1994, "Gazoline", "Auto", 10000.00, true);
    // NewCar *newCar = new NewCar("Audi", "B4", 2000, "Disel", "Mechanical", 9200.00, 2);
    // UsedCar *usedCar = new UsedCar("Bentley", "Viano", 2014, "Gazoline", "Auto", 70000.00, "Good");
    string name, code;
    
    cout << "Hello and welcome to our car shop!\nEnter your name, please: ";
    cin >> name;
    
    do {
        cout << name + " what do you want to do? (Choose variant)\n" << endl;
        cout << "1. Sell car\n2. Find car" << endl;
        
        int variant;
        cin >> variant;
        
        if (variant == 1) {
            sellCar();
        } else {
            findCar();
        }
    } while (cin >> code);
    
    return 0;
}