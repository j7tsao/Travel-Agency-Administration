#include "Receipt/Receipt.h"

// 1. Required for static class members defined
// 2. or use "inline static" member inside class definition with C++17 compiler
std::string Customer::fullName;
double Flights::flightCost;
double CarRentals::carRentalCost;
double HotelBooking::hotelCost;

void mainMenu() {
    int mainChoice;

    std::cout << "\n         * XYZ Travel Agency Management System *         \n";
    std::cout << "\n======================= MAIN MENU =======================\n";
    std::cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << '\n';
    std::cout << "\t|\t\t\t\t\t|" << '\n';
    std::cout << "\t|\tClients Management  -> 1\t|" << '\n';
    std::cout << "\t|\tFlights             -> 2\t|" << '\n';
    std::cout << "\t|\tCar Rentals         -> 3\t|" << '\n';
    std::cout << "\t|\tHotels Booking      -> 4\t|" << '\n';
    std::cout << "\t|\tReceipt             -> 5\t|" << '\n';
    std::cout << "\t|\tExit                -> 6\t|" << '\n';
    std::cout << "\t|\t\t\t\t\t|" << '\n';
    std::cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << '\n';

    std::cout << "\nEnter Choice: ";
    std::cin >> mainChoice;

    Receipt* client1 = new Receipt;

    if (mainChoice == 1) {
        client1->subMenu();
    }
    else if (mainChoice == 2) {
        client1->getFlightInfo();
        client1->printFlightInfo();
        client1->gotoMainMenu();
    }
    else if (mainChoice == 3) {
        client1->getCarRentalInfo();
        client1->printCarRentalInfo();
        client1->gotoMainMenu();
    }
    else if (mainChoice == 4) {
        client1->hotelSubMenu();
    }
    else if (mainChoice == 5) {
        client1->printReceipt();
    }
    else if (mainChoice == 6) {
        std::cout << "\n\n------------ THANK YOU. HAVE A GOOD DAY! ------------\n\n";
        delete client1;
        return;
    }
    else mainMenu();
}

int main() {

    ManageMenu* start = new ManageMenu;
    start->launchMainMenu();

    delete start;
    return 0;
}