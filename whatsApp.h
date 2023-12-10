#ifndef WHATSAPP_H_INCLUDED
#define WHATSAPP_H_INCLUDED

#include <iostream>
using namespace std;
#define info(P) P->info
#define next(P) P->next
#define first(L) L.first

struct infotypeUser {
    string nama;
    string noTelepon;
};

struct infotypeGroup {
    string groupName;
    int numOfMember;
};

typedef struct elmUser *adrUser;



struct elmUser {
    infotypeUser infoUser;
    adrUser nextUser;
    adrRel firstRel;
};

typedef struct elmRel *adrRel;

struct elmRel {
    adrGroup nextGroup;
    adrRel nextRel;
};

typedef struct elmGroup *adrGroup;

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

#endif /*WHATSAPP_H_INCLUDED*/