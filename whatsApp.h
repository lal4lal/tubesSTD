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

#endif /*WHATSAPP_H_INCLUDED*/