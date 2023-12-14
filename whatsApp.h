#ifndef WHATSAPP_H_INCLUDED
#define WHATSAPP_H_INCLUDED

#include <iostream>
using namespace std;
#define infoGroup(P) P->infoGroup
#define infoUser(P) P->infoUser
#define nextRel(P) P->nextRel
#define nextUser(P) P->nextUser
#define nextGroup(P) P->nextGroup
#define firstRel(P) P->firstRel
#define firstUser(L) L.firstUser
#define firstGroup(L) L.firstGroup

struct infotypeUser {
    string nama;
    string noTelepon;
};

struct infotypeGroup {
    string groupName;
    int numOfMember;
};

typedef struct elmUser *adrUser;
typedef struct elmRel *adrRel;
typedef struct elmGroup *adrGroup;

struct elmUser {
    infotypeUser infoUser;
    adrUser nextUser;
    adrRel firstRel;
};
struct elmRel {
    adrGroup nextGroup;
    adrRel nextRel;
};
struct elmGroup {
    infotypeGroup infoGroup;
    adrGroup nextGroup;
};

struct listUser {
    adrUser firstUser;
};

struct listGroup {
    adrGroup firstGroup;
};


void createListUser(listUser &LU);
void createListGroup(listGroup &LG);
adrUser createElmUser(infotypeUser x);
adrGroup createElmGroup(infotypeGroup x);
adrRel createElmRel(adrGroup pGroup);


// 1. Insert data grup dari belakang (5)
void insertLast_Group(listGroup &LG, adrGroup pGroup);

// 2.Show all data grup (5)
void showAlldata_Group(listGroup LG);

// 3.	Menghapus data grup beserta relasinya (15)
void deleteGroup(listGroup &LG, adrGroup &delGroup, string namaGroup);
void deleteRel(listUser &LU, adrRel prec, adrRel &delRel, adrUser pUser);
void deleteGroup_rel(listGroup &LG, listUser &LU, string namaGroup , adrGroup &delGroup);

// 4. Mencari data grup (5) & Mencari data user (5)
adrGroup searchData_Group(listGroup LG,string namaGroup);

// 6.	Menambahkan data user (5)
void insertLast_User(listUser &LU, adrUser pUser);

// 5. mencari data user
adrUser searchData_User(listUser LU, string noTelepon);
void showAlldata_User(listUser LU);
void takeOption(int &option);
void menu();
void addUsers(listUser &LU);
void hapusGrup(listUser &LU, listGroup &LG);
void addGroups(listGroup &LG);
void cariDataGrup(listGroup LG);
void cariDataUser(listUser LU);
void addUsers(listUser &LU);

// 7.	Menghubungkan data grup ke data user (5)
void joinGroup_menu(listUser &LU, listGroup &LG);
void joinGroup(listUser &LU, listGroup &LG, string noTelp, string namaGroup);

//8. 
void showAlldata_Group(listGroup LG, listUser LU);
void showAlldata_GroupMenu(listGroup LG, listUser LU);
#endif /*WHATSAPP_H_INCLUDED*/
