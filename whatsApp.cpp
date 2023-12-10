#include "whatsApp.h"

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
}

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
}

// 3.	Menghapus data grup beserta relasinya (15)
void deleteGroup(listGroup &LG, adrGroup &delGroup, string namaGroup) {
    delGroup = searchData_Group(LG, namaGroup);
    if (delGroup != NULL) {
        if (delGroup == firstGroup(LG) && nextGroup(delGroup) == firstGroup(LG)) { // Jika delGroup ada di first dan hanya 1 elemen di list Group
            firstGroup(LG) = NULL;
            nextGroup(delGroup) = NULL;
        } else if (delGroup == firstGroup(LG) && nextGroup(delGroup) != firstGroup(LG)) { // Jika delGroup ada di first dan ada lebih dari 1 elemen di list Group
            adrGroup lastGroup = nextGroup(delGroup);
            while (nextGroup(lastGroup) != firstGroup(LG)) {
                lastGroup = nextGroup(lastGroup);
            }
            nextGroup(lastGroup) = nextGroup(firstGroup(LG));
            firstGroup(LG) = nextGroup(firstGroup(LG));
            nextGroup(delGroup) = NULL;
        } else if (nextGroup(delGroup) == firstGroup(LG)) { // jika delGroup ada di akhir list Group
            adrGroup lastGroup = firstGroup(LG);
            while (nextGroup(lastGroup) != delGroup) {
                lastGroup = nextGroup(lastGroup);
            }
            nextGroup(delGroup) = NULL;
            nextGroup(lastGroup) = firstGroup(LG);
        } else { // jika delGroup ada ditengah tengah list Group
            adrGroup prevDel = firstGroup(LG);
             while (nextGroup(prevDel) != delGroup) {
                prevDel = nextGroup(prevDel);
            }
            nextGroup(prevDel) = nextGroup(delGroup);
            nextGroup(delGroup) = NULL;
        }
    } else {
        cout << "Group doesn't exist" << endl;
    }
}

void deleteRel(listUser &LU, adrRel prec, adrRel &delRel, adrUser pUser) {
    if (prec == firstRel(pUser) && nextRel(prec) == NULL) { // jika prec ada di first dan hanya ada 1 elemen di list Rel
        firstRel(pUser) = NULL;
    } else if (prec == firstRel(pUser) && nextRel(prec) != NULL) { // jika prec ada di first dan ada lebih dari 1 elemen di list Rel
        firstRel(pUser) = nextRel(prec);
        nextRel(prec) = NULL;
    } else if (nextRel(prec) == NULL) { // jika prec ada di akhir list Rel
        adrRel pRel = firstRel(pUser);
        while (nextRel(pRel) != prec) {
            pRel = nextRel(pRel);
        }
        nextRel(pRel) = NULL;
    } else { // jika prec ada di tengah tengah list Rel
        adrRel pRel = firstRel(pUser);
        while (nextRel(pRel) != prec) {
            pRel = nextRel(pRel);
        }
        nextRel(pRel) = nextRel(prec);
        nextRel(prec) = NULL;
    }
    delRel = prec;
}

void deleteGroup_rel(listGroup &LG, listUser &LU, string namaGroup , adrGroup &delGroup) {
    adrUser pUser = firstUser(LU);
    adrRel delRel = NULL;
    while (pUser != NULL) {
        adrRel pRel = firstRel(pUser);
        while (pRel != NULL) {
            if (infoGroup(nextGroup(pRel)).groupName == namaGroup) { // cek jika relasi terhubung ke namaGroup
                deleteRel(LU, pRel, delRel, pUser);
            }
            pRel = nextRel(pRel);
        }
    }
    deleteGroup(LG, delGroup, namaGroup);
}

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
}
adrUser searchData_User(listUser LU);

