#include "Receipt.h"

double Receipt::getTotalCost() {
    return totalCost = flightCost + carRentalCost + hotelCost;
}

void Receipt::printReceipt() {
    // Write down the receipt into a file
    std::ofstream outReceipt("receipt.txt");
    outReceipt << "\n\n-------------- XYZ Travel Agency --------------\n";
    outReceipt << "------------------- Receipt -------------------\n";
    outReceipt << "_______________________________________________\n";
    outReceipt << "Customer Name: \t\t\t" << fullName << "\n\n";
    outReceipt << "Flight Cost: \t\t\t" << "$" << std::fixed << std::setprecision(2) << flightCost << "\n";
    outReceipt << "Car Rental Cost: \t\t" << "$" << std::fixed << std::setprecision(2) << carRentalCost << "\n";
    outReceipt << "Hotel Cost: \t\t\t" << "$" << std::fixed << std::setprecision(2) << hotelCost << "\n";
    getTotalCost();
    outReceipt << "_______________________________________________\n";
    outReceipt << "Total Charge: \t\t\t" << "$" << std::fixed << std::setprecision(2) << totalCost << "\n";
    outReceipt << "_______________________________________________\n";
    outReceipt << "------------------ THANK YOU ------------------\n\n";
    outReceipt.close();

    // 1. Read the receipt and print
    // 2. append the receipt to another file containing all receipts
    std::ofstream allReceipts("allReceipts.txt", std::ios::app);
    std::ifstream readReceipt("receipt.txt");
    if (!readReceipt) std::cout << "Read File receipt.txt Error!";
    while (getline(readReceipt, line)) {
        allReceipts << line << '\n';    // append info to a file
        std::cout << line << '\n';      // print info
    }
    allReceipts.close();
    readReceipt.close();

    gotoMainMenu();
}