#include "HotelBooking.h"

void HotelBooking::hotelSubMenu() {
    std::cout << "\n===================== HOTEL BOOKING =====================\n\n";
    std::cout << "We are currently cooperating with these hotels listed below:" << "\n\n";

    std::string hotelArr[] = { "Sheraton Hotel", "Hilton Hotel", "Marriott International" };
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << ". " << hotelArr[i] << '\n';
    }

    std::cout << "\nEnter the choice to see more details or enter other number to exit: ";
    std::cin >> readHotelDetail;
    switch (readHotelDetail)
    {
    case 1: sheraton();
        break;
    case 2: hilton();
        break;
    case 3: marriott();
        break;
    default: gotoMainMenu();
        break;
    }
}

void HotelBooking::sheraton() {
    std::cout << "\n-------------- WELCOME TO SHERATON HOTEL --------------" << "\n\n";
    std::cout << "The Garden, food and beverage. Enjoy free drinks and meals in Sheraton Hotel! " << "\n\n";
    std::cout << "Packages offered by Sheraton Hotel:\n" << '\n';
    std::cout << "1. Standard Package" << '\n';
    std::cout << "\tBasic Facilities All you need for - US$130 per day" << '\n';
    std::cout << "2. Premium Package" << '\n';
    std::cout << "\tEnjoy Premium - US$160 per day" << '\n';
    std::cout << "3. Luxury Pack" << '\n';
    std::cout << "\tLive a Luxury at Sheraton - US$199 per day" << "\n\n";
    std::cout << "Enter the choice or enter '4' to go back to Hotel Menu: ";
    std::cin >> sheratonSelect;
    if (sheratonSelect == 1) {
        getHotelCheckInfo();
        std::cout << "\nStadard Package Booked!" << '\n';
        hotelCostPerDay = 130;
        hotelBookingCharge();
    }
    else if (sheratonSelect == 2) {
        getHotelCheckInfo();
        std::cout << "\nPremium Package Booked!" << '\n';
        hotelCostPerDay = 160;
        hotelBookingCharge();
    }
    else if (sheratonSelect == 3) {
        getHotelCheckInfo();
        std::cout << "\nLuxury Package Booked!" << '\n';
        hotelCostPerDay = 199;
        hotelBookingCharge();
    }
    else if (sheratonSelect == 4) {
        hotelSubMenu();
    }
    else sheraton();
}

void HotelBooking::hilton() {
    std::cout << "\n-------------- WELCOME TO HILTON HOTEL --------------" << "\n\n";
    std::cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << '\n';
    std::cout << "Packages Offered by Hilton Hotel:\n" << '\n';
    std::cout << "1. Family Package" << '\n';
    std::cout << "\t US$249.99 for a day" << '\n';
    std::cout << "2. Couple Package" << '\n';
    std::cout << "\t US$189.99 for a day" << '\n';
    std::cout << "3. Single Package" << '\n';
    std::cout << "\t US$119.99 for a day" << "\n\n";
    std::cout << "Enter the choice or enter '4' to go back to Hotel Menu: ";
    std::cin >> hiltonSelect;
    if (hiltonSelect == 1) {
        getHotelCheckInfo();
        std::cout << "\nFamily Package Booked!" << '\n';
        hotelCostPerDay = 249.99;
        hotelBookingCharge();
    }
    else if (hiltonSelect == 2) {
        getHotelCheckInfo();
        std::cout << "\nCouple Package Booked!" << '\n';
        hotelCostPerDay = 189.99;
        hotelBookingCharge();
    }
    else if (hiltonSelect == 3) {
        getHotelCheckInfo();
        std::cout << "\nSingle Package Booked!" << '\n';
        hotelCostPerDay = 119.99;
        hotelBookingCharge();
    }
    else if (hiltonSelect == 4) {
        hotelSubMenu();
    }
    else hilton();
}

void HotelBooking::marriott() {
    std::cout << "\n-------------- WELCOME TO MARRIOTT INTERNATIONAL HOTEL --------------" << "\n\n";
    std::cout << "Located in tropical ocean island, Swimming with to dolphins and sea turtles!" << '\n';
    std::cout << "Special offer this summer: Diving + Whale cruise + Water activities" << "\n\n";
    std::cout << "1. Family Package" << '\n';
    std::cout << "\tUS$239.89 per day" << '\n';
    std::cout << "2. Couple Package" << '\n';
    std::cout << "\tUS$179.89 per day" << "\n\n";
    std::cout << "Enter the choice or enter '3' to go back to Hotel Menu: ";
    std::cin >> marriottSelect;
    if (marriottSelect == 1) {
        getHotelCheckInfo();
        std::cout << "\nFamily Package Booked!" << '\n';
        hotelCostPerDay = 239.89;
        hotelBookingCharge();
    }
    else if (marriottSelect == 2) {
        getHotelCheckInfo();
        std::cout << "\nCouple Package Booked!" << '\n';
        hotelCostPerDay = 179.89;
        hotelBookingCharge();
    }
    else if (marriottSelect == 3) {
        hotelSubMenu();
    }
    else marriott();
}

std::string HotelBooking::getCheckInDate() {
    std::cout << "\nCheck-in Date (Ex. 01/01/2020): ";
    std::cin >> checkInDate;
    return checkInDate;
}

int HotelBooking::getNumDaysHotelStay() {
    std::cout << "How many days to stay: ";
    std::cin >> numDaysHotelStay;
    return numDaysHotelStay;
}

void HotelBooking::getHotelCheckInfo() {
    getCheckInDate();
    getNumDaysHotelStay();
}

double HotelBooking::getHotelCost() {
    hotelCost = hotelCostPerDay * numDaysHotelStay;
    return hotelCost;
}

void HotelBooking::printHotelCost() {
    std::cout << "\nCheck-in Date: " << checkInDate << '\n';
    std::cout << "Days of stay: " << numDaysHotelStay << '\n';
    std::cout << "Hotel Cost: " << "$" << std::fixed << std::setprecision(2) << hotelCost << '\n';
}

void HotelBooking::hotelBookingCharge() {
    std::cout << "\n_________ Hotel Booking Charge " << "_________" << "\n";
    getHotelCost();
    printHotelCost();
    std::cout << "\nThank you!" << "\n\n";

    // Write down Hotel Booking Info into a file 
    std::ofstream outFile("hotelBookingInfo.txt", std::ios::app);
    outFile << "\n_________ Hotel Booking Charge " << "_________" << "\n";
    outFile << "\nFull Name: " << fullName << '\n';
    outFile << "Check-in Date: " << checkInDate << '\n';
    outFile << "Days of stay: " << numDaysHotelStay << '\n';
    outFile << "Hotel Cost: " << "$" << std::fixed << std::setprecision(2) << hotelCost << '\n';
    outFile.close();
    gotoMainMenu();
}

