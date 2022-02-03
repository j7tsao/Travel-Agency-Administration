#pragma once
#ifndef __CUSTOMER_H_INCLUDE__
#define __CUSTOMER_H_INCLUDE__

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include "../ManageMenu/ManageMenu.h"

class Customer : public ManageMenu {
public:
    static std::string fullName;

    std::string birthdate,
                gender,
                phone,
                line;

    int subMenuTag,
        gotoMainMenuTag;

    void getName();
    void getGender();
    void getBirthdate();
    void getPhone();
    void getCustomerInfo();
    void showAllClients();
    void subMenu();
    void gotoMainMenu();
};

#endif	// __CUSTOMER_H_INCLUDE__ 