#include "ManageMenu.h"

void ManageMenu::launchMainMenu() {
    std::cout << "\n\n\t\t Please Enter your name as Admin: ";
    getline(std::cin, admin);
    std::cout << "\n\t\t Welcome, " << admin << " !\n\n";
    mainMenu();
}

std::string ManageMenu::getAdmin() {
    return admin;
}