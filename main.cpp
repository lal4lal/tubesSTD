#include "whatsApp.cpp"
#include <iostream>
using namespace std;

int main() { 
    listGroup LG;
    listUser LU;
    adrGroup group;
    infotypeGroup x;


    createListGroup(LG);
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
    

    if(searchData_Group(LG,"SobatHacker") == NULL) {
        cout << "Data not found"<< endl;
    }else {
        cout << "Data found in address " << searchData_Group(LG, "SobatHacker") << endl;
    }

    return 0;
}