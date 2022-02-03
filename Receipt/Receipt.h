#pragma once
#ifndef __RECEIPT_H_INCLUDE__
#define __RECEIPT_H_INCLUDE__

#include <iostream>
#include <fstream>
#include "../HotelBooking/HotelBooking.h"

class Receipt : public HotelBooking {
public:
    double totalCost;
    std::string line;

    double getTotalCost();
    void printReceipt();
};

#endif  // __RECEIPT_H_INCLUDE__
