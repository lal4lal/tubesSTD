#include "whatsApp.h"

void menu() {
    cout << "heloobitch" << endl;
}

void createListUser(listUser &LU) {
    firstUser(LU) = NULL;
}

void createListGroup(listGroup &LG) {
    firstGroup(LG) = NULL;
}

adrUser createElmUser(infotypeUser x) {
    adrUser pUser = new elmUser;
    infoUser(pUser) = x;
    nextUser(pUser) = NULL;
    firstRel(pUser) = NULL;

    return pUser;
}

adrGroup createElmGroup(infotypeGroup x) {
    adrGroup pGroup = new elmGroup;
    infoGroup(pGroup) = x;
    nextGroup(pGroup) = NULL;

    return pGroup;
}

adrRel createElmRel(adrGroup pGroup) {
    adrRel pRel = new elmRel;
    nextGroup(pRel) = pGroup;
    nextRel(pRel) = NULL;

    return pRel;
}

void insertLast_Group(listGroup &LG, adrGroup pGroup){
    if (firstGroup(LG) == NULL) {
        firstGroup(LG) = pGroup;
        nextGroup(pGroup) = firstGroup(LG); 
    }else {
        adrGroup Q;
        Q = firstGroup(LG);
        while (nextGroup(Q) != firstGroup(LG)) {
            Q = nextGroup(Q);
        }
        nextGroup(Q) = pGroup;
        nextGroup(pGroup) = firstGroup(LG);
    }
};

// 2.Show all data grup (5)
void showAlldata_Group(listGroup LG) {
    if (firstGroup(LG) == NULL) {
        cout << "Group isn't created yet";
    } else {
        cout << "HALO";
        adrGroup Q;
        Q = firstGroup(LG);
        while (nextGroup(Q) != firstGroup(LG)) {
            cout << "Group Name : " << infoGroup(Q).groupName << endl;
            cout << "Member : " << infoGroup(Q).numOfMember << endl;
            cout << endl;
            Q = nextGroup(Q);
        }
        cout << "Group Name : " << infoGroup(Q).groupName << endl;
        cout << "Member : " << infoGroup(Q).numOfMember << endl;
    }
};

// 3.	Menghapus data grup beserta relasinya (15)
void deleteGroup_rel(listGroup LG, adrGroup &delGroup);

// 4. Mencari data grup (5) & Mencari data user (5) 
adrGroup searchData_Group(listGroup LG, string namaGroup) {
    bool found =false;
    adrGroup Q;

    Q = firstGroup(Q);
    while (nextGroup(Q)!= firstGroup(Q) && !found) {
        if (namaGroup == infoGroup(Q).groupName) {
            found = true;
        } else {
            Q= nextGroup(Q);
        }
    }
    if (nextGroup(Q)== firstGroup(Q)) {
        if (namaGroup == infoGroup(Q).groupName) {
            found = true;
        } 
    }
    if (found) {
        return Q;
    } else {
        return NULL;
    }
};
adrUser searchData_User(listUser LU);

