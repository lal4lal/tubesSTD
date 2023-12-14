#include "whatsapp.h"
#include <iostream>
using namespace std;

int main() {
    listGroup LG;
    adrGroup group;
    infotypeGroup x;

    listUser LU;
    adrUser user;
    infotypeUser y;

    string noTelp,namaGroup;

    int option;
    string backToMenu;

    // HARDCODED GROUP //
    createListGroup(LG);
    createListUser(LU);

    menu();
    takeOption(option);
    while (option != 0) {
        if (option == 1) {
            addGroups(LG, backToMenu);
        } else if (option == 2) {
            showAlldata_Group(LG, backToMenu);
        } else if (option == 3) {
            hapusGrup(LU, LG, backToMenu);
        } else if (option == 4) {
            cariDataGrup(LG, backToMenu);
        } else if (option == 5) {
            cariDataUser(LU, backToMenu);
        } else if (option == 6) {
            addUsers(LU, backToMenu);
        } else if (option == 7) {
            joinGroup_menu(LU,LG);
        }
        if (backToMenu == "Y") {
            menu();
            takeOption(option);
        } else {
            option = 0;
        } 
    }

    return 0;
}
