#pragma once
#ifndef __HOTELBOOKING_H_INCLUDE
#define __HOTELBOOKING_H_INCLUDE

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>  // setprecision()
#include "../CarRentals/CarRentals.h"

class HotelBooking : public CarRentals {
public:
    int selectHotel,
        readHotelDetail,
        sheratonSelect,
        hiltonSelect,
        marriottSelect,
        numDaysHotelStay;

    double hotelCostPerDay;
    static double hotelCost;
    std::string checkInDate;

    void hotelSubMenu();
    void sheraton();
    void hilton();
    void marriott();
    std::string getCheckInDate();
    int getNumDaysHotelStay();
    void getHotelCheckInfo();
    double getHotelCost();
    void printHotelCost();
    void hotelBookingCharge();
};

#endif  // __HOTELBOOKING_H_INCLUDE
