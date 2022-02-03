#include "CarRentals.h"

int CarRentals::getCarType() {
    std::cout << "\nPlease select the car types below:" << "\n \n";
    std::cout << "1. Economy - 2 Adults, 2 Bags. $28/day" << '\n';
    std::cout << "2. Compact - 4 Adults, 2 Bags. $30/day" << '\n';
    std::cout << "3. Standard - 5 Adults, 2 Bags. $33/day" << '\n';
    std::cout << "4. Standard SUV - 5 Adults, 3 Bags. $41/day" << '\n';
    std::cout << "5. Mini Van - 5 Adults, 5 Bags. $48/day" << '\n';
    std::cout << "6. Luxury - 5 Adults, 5 Bags. $62/day" << '\n';
    std::cout << "\nEnter your choice: ";
    std::cin >> carTypeSelect;
    if (!(  carTypeSelect == 1 ||
            carTypeSelect == 2 ||
            carTypeSelect == 3 ||
            carTypeSelect == 4 ||
            carTypeSelect == 5 ||
            carTypeSelect == 6))
        getCarType();
    return carTypeSelect;
}

int CarRentals::getCarRentalPeriod() {
    std::cout << "\nPlease enter how many days the clients are going to rent the car? ";
    std::cin >> numDays;
    return numDays;
}

double CarRentals::getCarRentalCost() {
    switch (carTypeSelect)
    {
    case 1: carCostPerDay = 28;
        break;
    case 2: carCostPerDay = 30;
        break;
    case 3: carCostPerDay = 33;
        break;
    case 4: carCostPerDay = 41;
        break;
    case 5: carCostPerDay = 48;
        break;
    case 6: carCostPerDay = 62;
        break;
    default: std::cout << "Please choose the car first." << '\n';
        break;
    }
    return carRentalCost = carCostPerDay * numDays;
}

void CarRentals::getCarRentalInfo() {
    std::cout << "\n===================== CAR RENTALS =====================\n\n";
    std::cout << "Please provide the following information. \n";
    std::cin.ignore();
    getCarType();
    getCarRentalPeriod();
    getCarRentalCost();
    std::cout << "Car Rentals Cost: $" << carRentalCost << '\n';

    // Write down car rental info into a file
    std::ofstream outFile("carRentalInfo.txt", std::ios::app);
    outFile << "\n_________ Car Rental Info Summary" << "_________" << "\n";
    outFile << "\nFull Name: " << fullName << '\n';
    outFile << "Car chosen: ";
    switch (carTypeSelect)
    {
    case 1: outFile << "Economy - 2 Adults, 2 Bags. $28/day" << '\n';
        break;
    case 2: outFile << "Compact - 4 Adults, 2 Bags. $30/day" << '\n';
        break;
    case 3: outFile << "Standard - 5 Adults, 2 Bags. $33/day" << '\n';
        break;
    case 4: outFile << "Standard SUV - 5 Adults, 3 Bags. $41/day" << '\n';
        break;
    case 5: outFile << "Mini Van - 5 Adults, 5 Bags. $48/day" << '\n';
        break;
    case 6: outFile << "Luxury - 5 Adults, 5 Bags. $62/day" << '\n';
        break;
    default: outFile << "Please choose the car first." << '\n';
        break;
    }
    outFile << "Days of Rental: " << numDays << " Days \n";
    outFile << "Car Rental Cost: " << "$" << carRentalCost << '\n';
    outFile.close();
}

void CarRentals::printCarRentalInfo() {
    std::cout << "\n_________ Car Rental Info Summary" << "_________" << "\n";
    std::cout << "\nFull Name: " << fullName << '\n';
    std::cout << "Car chosen: ";
    switch (carTypeSelect)
    {
    case 1: std::cout << "Economy - 2 Adults, 2 Bags. $28/day" << '\n';
        break;
    case 2: std::cout << "Compact - 4 Adults, 2 Bags. $30/day" << '\n';
        break;
    case 3: std::cout << "Standard - 5 Adults, 2 Bags. $33/day" << '\n';
        break;
    case 4: std::cout << "Standard SUV - 5 Adults, 3 Bags. $41/day" << '\n';
        break;
    case 5: std::cout << "Mini Van - 5 Adults, 5 Bags. $48/day" << '\n';
        break;
    case 6: std::cout << "Luxury - 5 Adults, 5 Bags. $62/day" << '\n';
        break;
    default: std::cout << "Please choose the car first." << '\n';
        break;
    }
    std::cout << "Days of Rental: " << numDays << " Days \n";
    std::cout << "Car Rental Cost: " << "$" << carRentalCost << '\n';
}
