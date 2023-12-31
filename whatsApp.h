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
void insertLast_Group(listGroup &LG, adrGroup pGroup);
void showAlldata_Group(listGroup LG, string &option);
void deleteGroup(listGroup &LG, adrGroup &delGroup, string namaGroup);
void deleteRel(listUser &LU, adrRel prec, adrRel &delRel, adrUser pUser);
void deleteGroup_rel(listGroup &LG, listUser &LU, string namaGroup , adrGroup &delGroup);
adrGroup searchData_Group(listGroup LG,string namaGroup);
void insertLast_User(listUser &LU, adrUser pUser);
adrUser searchData_User(listUser LU, string noTelepon);
void showAlldata_User(listUser LU);
void takeOption(string &option);
void menu();
void addUsers(listUser &LU, string &option);
void hapusGrup(listUser &LU, listGroup &LG, string &option);
void addGroups(listGroup &LG, string &option);
void cariDataGrup(listGroup LG, string &option);
void cariDataUser(listUser LU, string &option);
void showGroupMember(listGroup LG, listUser LU, string &option);
void joinGroup_menu(listUser &LU, listGroup &LG, string &option);
void joinGroup(listUser &LU, listGroup &LG, string noTelp, string namaGroup);
void showAlldata_Group(listGroup LG, listUser LU);
void showAlldata_GroupMenu(listGroup LG, listUser LU);
void load_dataset(listUser &LU, listGroup &LG);
void searchUserinGroup(listGroup LG, listUser LU, string &option);
adrRel searchData_Rel(listUser LU, listGroup LG, string namaGroup, adrUser pUser);
void showGroupMem5(listGroup LG, string &option);
void leftGroupMenu(listUser &LU, listGroup &LG, string &option);
void leftGroup(listUser LU,listGroup LG, string phoneNum,string groupName);

#endif /*WHATSAPP_H_INCLUDED*/
