#pragma once
#ifndef __FLIGHTS_H_INCLUDE__
#define __FLIGHTS_H_INCLUDE__

#include <iostream>
#include <fstream>
#include <string>
#include "../Customer/Customer.h"

class Flights : public Customer {
public:
    std::string origion,
                destination,
                departureDate,
                returnDate,
                departureTime;

    int tripType,
        numTraveler,
        departureTimeFlag,
        seatClass;

    const double economiceCost = 700,
                 businessCost = 900,
                 firstClassCost = 1200;

    static double flightCost;

    void getTripType();
    void getLocations();
    void getDates();
    void getTime();
    void getNumTraveler();
    void getSeatClass();
    double getFlightCost();
    void getFlightInfo();
    void printFlightInfo();
};

#endif	// __FLIGHTS_H_INCLUDE__