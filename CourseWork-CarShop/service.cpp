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

void findCar() {
    string mark, model, fuelType, transmission;
    int type, year;
    double price;
    
    cout << "Which car type do you want to find?" << endl;
    cout << "1) Used car\n2) New car\n3) Rare car" << endl;
    cin >> type;
    
    if (type == 1) {
        string condition;
        list<UsedCar*> cars;
        
        ifstream input("usedCars.txt");
        while (input >> mark >> model >> year >> fuelType >> transmission >> price >> condition) {
            cars.push_back(new UsedCar(mark, model, year, fuelType, transmission, price, condition));
        }
        cout << "By which field you want to find (mark - 1, year - 2, price - 3, transmission - 4)? ";
        cin >> type;
        
        if (type == 1) {
            cout << "What mark you want to find? ";
            cin >> mark;
            
            for (list<UsedCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
                if ((*it)->getMark() == mark) {
                    cout << endl;
                    cout << "Car found!" << endl;
                    cout << "Mark: " << (*it)->getMark() << endl;
                    cout << "Model: " << (*it)->getModel() << endl;
                    cout << "Year: " << (*it)->getYear() << endl;
                    cout << "Fuel Type: " << (*it)->getFuelType() << endl;
                    cout << "Transmission: " << (*it)->getTransmission() << endl;
                    cout << "Price: " << (*it)->getPrice() << endl;
                    cout << "Condition: " << (*it)->getCondition() << endl << endl;
                }
            }
        } else if (type == 2) {
            int yearFrom, yearTo;
            cout << "Enter years interval.\nFrom: ";
            cin >> yearFrom;
            cout << "To: ";
            cin >> yearTo;
            
            for (list<UsedCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
                if ( yearFrom < (*it)->getYear() && (*it)->getYear() < yearTo ) {
                    cout << endl;
                    cout << "Car found!" << endl;
                    cout << "Mark: " << (*it)->getMark() << endl;
                    cout << "Model: " << (*it)->getModel() << endl;
                    cout << "Year: " << (*it)->getYear() << endl;
                    cout << "Fuel Type: " << (*it)->getFuelType() << endl;
                    cout << "Transmission: " << (*it)->getTransmission() << endl;
                    cout << "Price: " << (*it)->getPrice() << endl;
                    cout << "Condition: " << (*it)->getCondition() << endl << endl;
                }
            }
        } else if (type == 3) {
            double priceFrom, priceTo;
            cout << "Enter price interval.\nFrom: ";
            cin >> priceFrom;
            cout << "To: ";
            cin >> priceTo;
            
            for (list<UsedCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
                if ( priceFrom < (*it)->getPrice() && (*it)->getPrice() < priceTo ) {
                    cout << endl;
                    cout << "Car found!" << endl;
                    cout << "Mark: " << (*it)->getMark() << endl;
                    cout << "Model: " << (*it)->getModel() << endl;
                    cout << "Year: " << (*it)->getYear() << endl;
                    cout << "Fuel Type: " << (*it)->getFuelType() << endl;
                    cout << "Transmission: " << (*it)->getTransmission() << endl;
                    cout << "Price: " << (*it)->getPrice() << endl;
                    cout << "Condition: " << (*it)->getCondition() << endl << endl;
                }
            }
        } else if (type == 4) {
            cout << "Enter transmission type: ";
            cin >> transmission;
            
            for (list<UsedCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
                if ( transmission == (*it)->getTransmission() ) {
                    cout << endl;
                    cout << "Car found!" << endl;
                    cout << "Mark: " << (*it)->getMark() << endl;
                    cout << "Model: " << (*it)->getModel() << endl;
                    cout << "Year: " << (*it)->getYear() << endl;
                    cout << "Fuel Type: " << (*it)->getFuelType() << endl;
                    cout << "Transmission: " << (*it)->getTransmission() << endl;
                    cout << "Price: " << (*it)->getPrice() << endl;
                    cout << "Condition: " << (*it)->getCondition() << endl << endl;
                }
            }
        }
    } else if (type == 2) {
        int guarantee;
        list<NewCar*> cars;
        
        ifstream input("newCars.txt");
        while (input >> mark >> model >> year >> fuelType >> transmission >> price >> guarantee) {
            cars.push_back(new NewCar(mark, model, year, fuelType, transmission, price, guarantee));
        }
        cout << "By which field you want to find (mark - 1, year - 2, price - 3, transmission - 4)? ";
        cin >> type;
        
        if (type == 1) {
            cout << "What mark you want to find? ";
            cin >> mark;
            
            for (list<NewCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
                if ((*it)->getMark() == mark) {
                    cout << endl;
                    cout << "Car found!" << endl;
                    cout << "Mark: " << (*it)->getMark() << endl;
                    cout << "Model: " << (*it)->getModel() << endl;
                    cout << "Year: " << (*it)->getYear() << endl;
                    cout << "Fuel Type: " << (*it)->getFuelType() << endl;
                    cout << "Transmission: " << (*it)->getTransmission() << endl;
                    cout << "Price: " << (*it)->getPrice() << endl;
                    cout << "Guarantee: " << (*it)->getGuarantee() << endl << endl;
                }
            }
        } else if (type == 2) {
            int yearFrom, yearTo;
            cout << "Enter years interval.\nFrom: ";
            cin >> yearFrom;
            cout << "To: ";
            cin >> yearTo;
            
            for (list<NewCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
                if ( yearFrom < (*it)->getYear() && (*it)->getYear() < yearTo ) {
                    cout << endl;
                    cout << "Car found!" << endl;
                    cout << "Mark: " << (*it)->getMark() << endl;
                    cout << "Model: " << (*it)->getModel() << endl;
                    cout << "Year: " << (*it)->getYear() << endl;
                    cout << "Fuel Type: " << (*it)->getFuelType() << endl;
                    cout << "Transmission: " << (*it)->getTransmission() << endl;
                    cout << "Price: " << (*it)->getPrice() << endl;
                    cout << "Guarantee: " << (*it)->getGuarantee() << endl << endl;
                }
            }
        } else if (type == 3) {
            double priceFrom, priceTo;
            cout << "Enter price interval.\nFrom: ";
            cin >> priceFrom;
            cout << "To: ";
            cin >> priceTo;
            
            for (list<NewCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
                if ( priceFrom < (*it)->getPrice() && (*it)->getPrice() < priceTo ) {
                    cout << endl;
                    cout << "Car found!" << endl;
                    cout << "Mark: " << (*it)->getMark() << endl;
                    cout << "Model: " << (*it)->getModel() << endl;
                    cout << "Year: " << (*it)->getYear() << endl;
                    cout << "Fuel Type: " << (*it)->getFuelType() << endl;
                    cout << "Transmission: " << (*it)->getTransmission() << endl;
                    cout << "Price: " << (*it)->getPrice() << endl;
                    cout << "Guarantee: " << (*it)->getGuarantee() << endl << endl;
                }
            }
        } else if (type == 4) {
            cout << "Enter transmission type: ";
            cin >> transmission;
            
            for (list<NewCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
                if ( transmission == (*it)->getTransmission() ) {
                    cout << endl;
                    cout << "Car found!" << endl;
                    cout << "Mark: " << (*it)->getMark() << endl;
                    cout << "Model: " << (*it)->getModel() << endl;
                    cout << "Year: " << (*it)->getYear() << endl;
                    cout << "Fuel Type: " << (*it)->getFuelType() << endl;
                    cout << "Transmission: " << (*it)->getTransmission() << endl;
                    cout << "Price: " << (*it)->getPrice() << endl;
                    cout << "Guarantee: " << (*it)->getGuarantee() << endl << endl;
                }
            }
        }
    } else if (type == 3) {
        string hasPersonalDriver;
        list<RareCar*> cars;
        
        ifstream input("rareCars.txt");
        while (input >> mark >> model >> year >> fuelType >> transmission >> price >> hasPersonalDriver) {
            cars.push_back(new RareCar(mark, model, year, fuelType, transmission, price, hasPersonalDriver));
        }
        cout << "By which field you want to find (mark - 1, year - 2, price - 3, transmission - 4)? ";
        cin >> type;
        
        if (type == 1) {
            cout << "What mark you want to find? ";
            cin >> mark;
            
            for (list<RareCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
                if ((*it)->getMark() == mark) {
                    cout << endl;
                    cout << "Car found!" << endl;
                    cout << "Mark: " << (*it)->getMark() << endl;
                    cout << "Model: " << (*it)->getModel() << endl;
                    cout << "Year: " << (*it)->getYear() << endl;
                    cout << "Fuel Type: " << (*it)->getFuelType() << endl;
                    cout << "Transmission: " << (*it)->getTransmission() << endl;
                    cout << "Price: " << (*it)->getPrice() << endl;
                    cout << "Personal Driver: " << (*it)->getPersonalDriverInfo() << endl << endl;
                }
            }
        } else if (type == 2) {
            int yearFrom, yearTo;
            cout << "Enter years interval.\nFrom: ";
            cin >> yearFrom;
            cout << "To: ";
            cin >> yearTo;
            
            for (list<RareCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
                if ( yearFrom < (*it)->getYear() && (*it)->getYear() < yearTo ) {
                    cout << endl;
                    cout << "Car found!" << endl;
                    cout << "Mark: " << (*it)->getMark() << endl;
                    cout << "Model: " << (*it)->getModel() << endl;
                    cout << "Year: " << (*it)->getYear() << endl;
                    cout << "Fuel Type: " << (*it)->getFuelType() << endl;
                    cout << "Transmission: " << (*it)->getTransmission() << endl;
                    cout << "Price: " << (*it)->getPrice() << endl;
                    cout << "Personal Driver: " << (*it)->getPersonalDriverInfo() << endl << endl;
                }
            }
        } else if (type == 3) {
            double priceFrom, priceTo;
            cout << "Enter price interval.\nFrom: ";
            cin >> priceFrom;
            cout << "To: ";
            cin >> priceTo;
            
            for (list<RareCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
                if ( priceFrom < (*it)->getPrice() && (*it)->getPrice() < priceTo ) {
                    cout << endl;
                    cout << "Car found!" << endl;
                    cout << "Mark: " << (*it)->getMark() << endl;
                    cout << "Model: " << (*it)->getModel() << endl;
                    cout << "Year: " << (*it)->getYear() << endl;
                    cout << "Fuel Type: " << (*it)->getFuelType() << endl;
                    cout << "Transmission: " << (*it)->getTransmission() << endl;
                    cout << "Price: " << (*it)->getPrice() << endl;
                    cout << "Personal Driver: " << (*it)->getPersonalDriverInfo() << endl << endl;
                }
            }
        } else if (type == 4) {
            cout << "Enter transmission type: ";
            cin >> transmission;
            
            for (list<RareCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
                if ( transmission == (*it)->getTransmission() ) {
                    cout << endl;
                    cout << "Car found!" << endl;
                    cout << "Mark: " << (*it)->getMark() << endl;
                    cout << "Model: " << (*it)->getModel() << endl;
                    cout << "Year: " << (*it)->getYear() << endl;
                    cout << "Fuel Type: " << (*it)->getFuelType() << endl;
                    cout << "Transmission: " << (*it)->getTransmission() << endl;
                    cout << "Price: " << (*it)->getPrice() << endl;
                    cout << "Personal Driver: " << (*it)->getPersonalDriverInfo() << endl << endl;
                }
            }
        }
    }
}