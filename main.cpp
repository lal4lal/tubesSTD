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

    string noTelp,namaGroup;

    string option;
    string backToMenu;

    // HARDCODED GROUP //
    createListGroup(LG);
    createListUser(LU);

    load_dataset(LU, LG);
    menu();
    takeOption(option);
    while ((option == "1" || option == "2" || option == "3" || option == "4" || option == "5" || option == "6" || option == "7" ||
           option == "8" || option == "9" || option == "10") || option == "11") {
        if (option == "1") {
            addGroups(LG, backToMenu);
        } else if (option == "2") {
            showAlldata_Group(LG, backToMenu);
        } else if (option == "3") {
            hapusGrup(LU, LG, backToMenu);
        } else if (option == "4") {
            cariDataGrup(LG, backToMenu);
        } else if (option == "5") {
            cariDataUser(LU, backToMenu);
        } else if (option == "6") {
            addUsers(LU, backToMenu);
        } else if (option == "7") {
            joinGroup_menu(LU,LG, backToMenu);
        } else if (option == "8") {
            showGroupMember(LG, LU, backToMenu);
        } else if (option == "9") {
            searchUserinGroup(LG, LU, backToMenu);
        } else if (option == "10") {
            leftGroupMenu(LU,LG,backToMenu);
        } else if (option == "11") {
            showGroupMem5(LG, backToMenu);
        }
        if (backToMenu == "Y" || backToMenu == "y") {
            menu();
            takeOption(option);
        }
    }

    return 0;
}
