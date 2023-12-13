#include "whatsApp.h"
#include <iostream>
using namespace std;

int main() { 
    listGroup LG;
    adrGroup group;
    infotypeGroup x;

    listUser LU;
    adrUser user;
    infotypeUser y;

    int option;

    // HARDCODED GROUP //
    createListGroup(LG);
    createListUser(LU);
    
    menu();
    takeOption(option);
    while (option != 0) {
        if (option == 1) {
            addGroups(LG);
        } else if (option == 2) {
            showAlldata_Group(LG);
        } else if (option == 3) {
            hapusGrup(LU, LG);
        } else if (option == 4) {
            cariDataGrup(LG);
        } else if (option == 5) {
            cariDataUser(LU);
        } else if (option == 6) {
            addUsers(LU);
        }
        menu();
        takeOption(option);
    }

    return 0;
}