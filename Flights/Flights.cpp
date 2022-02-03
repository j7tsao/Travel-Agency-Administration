#include "Flights.h"

void Flights::getTripType() {
    std::cout << "Press '1' for One-way trip or '2' for Round-trip: ";
    std::cin >> tripType;
    while (!(tripType == 1 || tripType == 2)) {
        std::cout << "Press '1' for One-way trip or '2' for Round-trip: ";
        std::cin >> tripType;
    }
}

void Flights::getLocations() {
    std::cout << "Where is the flight leaving from? ";
    getline(std::cin, origion);
    std::cout << "Where is the flight going to? ";
    getline(std::cin, destination);
}

void Flights::getDates() {
    std::cout << "Departure Date (Ex: 01/01/2022): ";
    std::cin.ignore();
    getline(std::cin, departureDate);
    if (tripType == 2) {
        std::cout << "Return Date (Ex: 01/01/2022): ";
        getline(std::cin, returnDate);
    }
}

void Flights::getTime() {
    std::cout << "Choose '1' for 10AM departure or '2' for 5PM departure: ";
    std::cin >> departureTimeFlag;
    if (departureTimeFlag == 1) departureTime = "10AM";
    else if (departureTimeFlag == 2) departureTime = "5PM";
    while (!(departureTimeFlag == 1 || departureTimeFlag == 2)) {
        std::cout << "Choose '1' for 10AM departure or '2' for 5PM departure: ";
        std::cin >> departureTimeFlag;
    }
}

void Flights::getNumTraveler() {
    std::cout << "Number of Passengers: ";
    std::cin >> numTraveler;
}

void Flights::getSeatClass() {
    std::cout << "Choose '1' for Economy, '2' for Bussiness class, '3' for First class: ";
    std::cin >> seatClass;
    while (!(seatClass == 1 || seatClass == 2 || seatClass == 3)) {
        std::cout << "Choose '1' for Economy, '2' for Bussiness class, '3' for First class: ";
        std::cin >> seatClass;
    }
}

double Flights::getFlightCost() {
    if (seatClass == 1) {
        if (tripType == 2) return flightCost = economiceCost * 1.8 * numTraveler;
        else return flightCost = economiceCost * numTraveler;
    }
    else if (seatClass == 2) {
        if (tripType == 2) return flightCost = businessCost * 1.8 * numTraveler;
        else return flightCost = businessCost * numTraveler;
    }
    else {
        if (tripType == 2) return flightCost = firstClassCost * 1.8 * numTraveler;
        else return flightCost = firstClassCost * numTraveler;
    }
}

void Flights::getFlightInfo() {
    std::cout << "\n===================== FLIGHTS BOOKING =====================\n\n";
    std::cout << "Please provide the following information: \n";
    std::cin.ignore();
    getLocations();
    getTripType();
    getDates();
    getTime();
    getNumTraveler();
    getSeatClass();
    getFlightCost();

    // Write down customer Info into a file with append mode
    std::ofstream outFile("flightInfo.txt", std::ios::app);
    outFile << "_________ Travel itinerary for " << fullName << "_________" << '\n';
    outFile << "Full Name: " << fullName << '\n';
    outFile << "Depature: " << origion << '\n';
    outFile << "Arrival: " << destination << '\n';
    outFile << "Depature Date/Time: " << departureDate << ' ' << departureTime << '\n';
    if (tripType == 2) {
        outFile << "Return Date/Time: " << returnDate << ' ' << departureTime << '\n';
    }
    outFile << "Number of Passengers: " << numTraveler << '\n';
    outFile << "Seat of Class: " << seatClass << '\n';
    outFile << "Tickets Cost: " << "$" << flightCost << "\n\n";
    outFile << "\n***** Thank you! The flight has been booked on " << __DATE__ << " at " << __TIME__ << ". *****" << "\n\n";
    outFile.close();
}

void Flights::printFlightInfo() {
    std::cout << "\n_________ Travel itinerary for " << fullName << "_________" << '\n';
    std::cout << "Full Name: " << fullName << '\n';
    std::cout << "Depature: " << origion << '\n';
    std::cout << "Arrival: " << destination << '\n';
    std::cout << "Depature Date/Time: " << departureDate << ' ' << departureTime << '\n';
    if (tripType == 2) {
        std::cout << "Return Date/Time: " << returnDate << ' ' << departureTime << '\n';
    }
    std::cout << "Number of Passengers: " << numTraveler << '\n';
    std::cout << "Seat of Class: " << seatClass << '\n';
    std::cout << "Tickets Cost: " << "$" << flightCost << '\n';
    std::cout << "\n***** Thank you! The flight has been booked on " << __DATE__ << " at " << __TIME__ << ". *****" << "\n\n";
}

