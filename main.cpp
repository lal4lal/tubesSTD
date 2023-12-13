#include "whatsApp.cpp"
#include <iostream>
using namespace std;

int main() { 
    listGroup LG;
    adrGroup group;
    infotypeGroup x;

    listUser LU;
    adrUser user;
    infotypeUser y;

    // HARDCODED GROUP //
    createListGroup(LG);
    createListUser(LU);
    x.groupName = "SobatHacker";
    x.numOfMember = 2;
    group = createElmGroup(x);   
    insertLast_Group(LG,group);

    x.groupName = "RPLa";
    x.numOfMember = 2;
    group = createElmGroup(x);   
    insertLast_Group(LG,group);

    x.groupName = "TanpaImam";
    x.numOfMember = 3;
    group = createElmGroup(x); 
    insertLast_Group(LG,group);
    showAlldata_Group(LG);

    // HARDCODED USER //
    y.nama = "Dito";
    y.noTelepon = "081389018701";
    user = createElmUser(y);
    insertLast_User(LU,user);

    y.nama = "Hilal";
    y.noTelepon = "081389018701";
    user = createElmUser(y);
    insertLast_User(LU,user);

    y.nama = "Fariz";
    y.noTelepon = "081389018701";
    user = createElmUser(y);
    insertLast_User(LU,user);

    showAlldata_User(LU);


    cout << endl;
    

    if(searchData_Group(LG,"SobatHacker") == NULL) {
        cout << "Data Group not found"<< endl;
    }else {
        cout << "Data group found in address " << searchData_Group(LG, "SobatHacker") << endl;
    }

    cout << endl;

    if(searchData_User(LU,"Hilal") == NULL) {
        cout << "Data User not found"<< endl;
    }else {
        cout << "Data User found in address " << searchData_User(LU, "Hilal") << endl;
    }

    return 0;
}