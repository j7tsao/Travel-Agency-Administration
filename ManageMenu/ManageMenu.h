#pragma once
#ifndef __MANAGEMENU_H_INCLUDE__
#define __MANAGEMENU_H_INCLUDE__

#include <iostream>
#include <string>

// forward declared dependencies
void mainMenu();

// class declaration 
class ManageMenu {
private:
    std::string admin;
public:
    void launchMainMenu();
    std::string getAdmin();
};

#endif  // __MANAGEMENU_H_INCLUDE__