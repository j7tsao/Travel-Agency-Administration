#pragma once
#ifndef __CARRENTALS_H_INCLUDE__
#define __CARRENTALS_H_INCLUDE__

#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include "../Flights/Flights.h"

class CarRentals : public Flights {
public:
    int carTypeSelect;
    int numDays;
    double carCostPerDay;
    static double carRentalCost;

    int getCarType();
    int getCarRentalPeriod();
    double getCarRentalCost();
    void getCarRentalInfo();
    void printCarRentalInfo();
};

#endif  // __CARRENTALS_H_INCLUDE__
