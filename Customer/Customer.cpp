#include "Customer.h"

void Customer::getName() {
    std::cout << "Full name: ";
    getline(std::cin, fullName);
}

void Customer::getGender() {
    std::cout << "Gender: ";
    getline(std::cin, gender);
}

void Customer::getBirthdate() {
    std::cout << "Birthdate (Ex: 01/01/2000): ";
    getline(std::cin, birthdate);
}

void Customer::getPhone() {
    std::cout << "Phone: ";
    getline(std::cin, phone);
}

void Customer::getCustomerInfo() {
    std::cout << "\n_____________________ CLIENT INFORMATION _____________________\n\n";
    std::cout << "Please provide the following information for the client: \n";
    std::cin.ignore();
    getName();
    getGender();
    getBirthdate();
    getPhone();

    // Write down customer Info into the file (append mode)
    std::ofstream outFile("clientInfo.txt", std::ios::app);
    outFile << "\nFull Name: " << fullName << '\n';
    outFile << "Gender: " << gender << '\n';
    outFile << "Birthdate: " << birthdate << '\n';
    outFile << "Phone: " << phone << '\n';
    outFile << "__________________________________________\n";
    outFile.close();
    gotoMainMenu();
}

void Customer::showAllClients() {
    // Read the clients info from the file written
    std::ifstream readFile("clientInfo.txt");
    if (!readFile) {
        std::cout << "File Error!" << '\n';
    }
    while (getline(readFile, line)) {
        std::cout << line << '\n';
    }
    readFile.close();
    gotoMainMenu();
}

void Customer::subMenu() {
    std::cout << "\n___________ Clients Management ___________\n";
    std::cout << "\n1. Enter New Client\n";
    std::cout << "2. Display All Clients\n";
    std::cout << "\nEnter choice: ";
    std::cin >> subMenuTag;

    if (!(subMenuTag == 1 || subMenuTag == 2)) {
        std::cout << "\nPlease enter '1' or '2'!\n";
        subMenu();
    }
    // Regex is not necessray here but is added for learning:
    // 1. regex_match only works when "input" is in string type
    // 2. std::to_string(int), int cast to string 
    std::regex subMenuPattern("[1-2]");
    if (std::regex_match(std::to_string(subMenuTag), subMenuPattern)) {
        if (subMenuTag == 1)
            getCustomerInfo();
        else if (subMenuTag == 2)
            showAllClients();
    }
}

void Customer::gotoMainMenu() {
    std::cout << "\nPress 1 to go back to Main Menu: ";
    std::cin >> gotoMainMenuTag;
    if (gotoMainMenuTag == 1) {
        std::cout << '\n';
        mainMenu();
    }
    else gotoMainMenu();
}

