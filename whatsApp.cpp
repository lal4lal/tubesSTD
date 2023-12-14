#include "whatsapp.h"

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

// 3.	Menghapus data grup beserta relasinya (15)
void deleteGroup(listGroup &LG, adrGroup &delGroup, string namaGroup) {
    delGroup = searchData_Group(LG, namaGroup);
    if (delGroup != NULL) {
        if (delGroup == firstGroup(LG) && nextGroup(delGroup) == firstGroup(LG)) { // Jika delGroup ada di first dan hanya 1 elemen di list Group
            firstGroup(LG) = NULL;
            nextGroup(delGroup) = NULL;
        } else if (delGroup == firstGroup(LG) && nextGroup(delGroup) != firstGroup(LG)) { // Jika delGroup ada di first dan ada lebih dari 1 elemen di list Group
            adrGroup lastGroup = firstGroup(LG);
            while (nextGroup(lastGroup) != firstGroup(LG)) {
                lastGroup = nextGroup(lastGroup);
            }
            nextGroup(lastGroup) = nextGroup(firstGroup(LG));
            firstGroup(LG) = nextGroup(firstGroup(LG));
            nextGroup(firstGroup(LG)) = NULL;
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

    Q = firstGroup(LG);
    while (nextGroup(Q)!= firstGroup(LG) && !found) {
        if (namaGroup == infoGroup(Q).groupName) {
            found = true;
        } else {
            Q= nextGroup(Q);
        }
    }
    if (nextGroup(Q)== firstGroup(LG)) {
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


void insertLast_User(listUser &LU, adrUser pUser){
    if (firstUser(LU) == NULL) {
        firstUser(LU) = pUser;
        nextUser(pUser) = firstUser(LU);
    }else {
        adrUser Q;
        Q = firstUser(LU);
        while (nextUser(Q) != firstUser(LU)) {
            Q = nextUser(Q);
        }
        nextUser(Q) = pUser;
        nextUser(pUser) = firstUser(LU);
    }
}

adrUser searchData_User(listUser LU,string noTelepon){
    adrUser pUser = firstUser(LU);
    while (pUser != NULL && infoUser(pUser).noTelepon != noTelepon) {
        pUser = nextUser(pUser);
    }

    return pUser;
}

void showAlldata_User(listUser LU) {
    if (firstUser(LU) == NULL) {
        cout << "User isn't created yet";
    } else {
        adrUser Q;
        Q = firstUser(LU);
        while (nextUser(Q) != firstUser(LU)) {
            cout << "Username : " << infoUser(Q).nama << endl;
            cout << "No Phone : " << infoUser(Q).noTelepon << endl;
            cout << endl;
            Q = nextUser(Q);
        }
        cout << "User Name : " << infoUser(Q).nama << endl;
        cout << "No Phone : " << infoUser(Q).noTelepon << endl;
    }
}

// 7.

adrRel createElmRel(adrGroup pGroup) {
    adrRel pRel = new elmRel;
    nextGroup(pRel) = pGroup;
    nextRel(pRel) = NULL;

    return pRel;
}



void joinGroup(listUser &LU, listGroup &LG, string noTelp, string namaGroup) {
   adrUser pUser = searchData_User(LU,noTelp);
   adrGroup pGroup = searchData_Group(LG,namaGroup);
   adrRel rel;

   rel = createElmRel(pGroup);
   if (firstRel(pUser) == NULL) {
        firstRel(pUser) = rel;
   } else {
        adrRel Q;
        Q = firstRel(pUser);
        while (nextRel(Q) != NULL) {
            Q = nextRel(Q);
        }
        nextRel(Q) = rel;
   }
   infoGroup(pGroup).numOfMember++;
   cout << infoUser(pUser).nama << " Joined " << infoGroup(pGroup).groupName << "." << endl;

   cout << endl;
}

