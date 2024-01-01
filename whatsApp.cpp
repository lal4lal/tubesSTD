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
            firstGroup(LG) = nextGroup(lastGroup);
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
    }
}

void deleteRel(listUser &LU, adrRel precDel, adrRel &delRel, adrUser pUser) {
    if (firstRel(pUser) == precDel && nextRel(firstRel(pUser)) == NULL) { // jika prec ada di first dan hanya ada 1 elemen di list Rel
        firstRel(pUser) = NULL;
    } else if (firstRel(pUser) == precDel && nextRel(firstRel(pUser)) != NULL) { // jika prec ada di first dan ada lebih dari 1 elemen di list Rel
        firstRel(pUser) = nextRel(firstRel(pUser));
        nextRel(precDel) = NULL;
    } else if (nextRel(precDel) == NULL) {
        adrRel pRel = firstRel(pUser);
        while (nextRel(pRel) != precDel) {
            pRel = nextRel(pRel);
        }
        nextRel(pRel) = NULL;
    } else { // jika prec ada di tengah tengah list Rel
        adrRel pRel = firstRel(pUser);
        while (nextRel(pRel) != precDel) {
            pRel = nextRel(pRel);
        }
        nextRel(pRel) = nextRel(precDel);
        nextRel(precDel) = NULL;
    }
    delRel = precDel;
}



void deleteGroup_rel(listGroup &LG, listUser &LU, string namaGroup , adrGroup &delGroup) {
    adrUser pUser = firstUser(LU);
    adrRel delRel, pRel;
    bool found;
    while (pUser != NULL) {
        pRel = firstRel(pUser);
        found = false;
        while (pRel != NULL && !found) {
            if (infoGroup(nextGroup(pRel)).groupName == namaGroup) {
                found = true;
            } else {
                pRel = nextRel(pRel);
            }
        }
        if (found && pRel != NULL) {
            deleteRel(LU, pRel, delRel, pUser);
        }
        pUser = nextUser(pUser);
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
        nextUser(pUser) = NULL;
    }else {
        adrUser Q;
        Q = firstUser(LU);
        while (nextUser(Q) != NULL) {
            Q = nextUser(Q);
        }
        nextUser(Q) = pUser;
    }
}

adrUser searchData_User(listUser LU,string noTelepon){
    adrUser pUser = firstUser(LU);
    while (pUser != NULL && infoUser(pUser).noTelepon != noTelepon) {
        pUser = nextUser(pUser);
    }

    return pUser;
}

adrRel searchData_Rel(listUser LU, listGroup LG, string namaGroup, adrUser pUser) {
    adrRel pRel;
    if (pUser != NULL) {
        pRel = firstRel(pUser);
        while (pRel != NULL && infoGroup(nextGroup(pRel)).groupName != namaGroup) {
            pRel = nextRel(pRel);
        }
    }
    return pRel;
}

void showAlldata_User(listUser LU) {
    if (firstUser(LU) == NULL) {
        cout << "User isn't created yet";
    } else {
        adrUser Q;
        Q = firstUser(LU);
        while (Q != NULL) {
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
   cout << endl;
}



void leftGroup(listUser LU,listGroup LG, string phoneNum,string groupName) {
    adrUser pUser = searchData_User(LU,phoneNum);
    adrGroup pGroup = searchData_Group(LG,groupName);
    bool found = false;

    adrRel relUser;
    relUser = firstRel(pUser);
    while (nextRel(relUser) != NULL && !found) {
        if (nextGroup(relUser) == pGroup) {
            found = true;
        } else {
            relUser = nextRel(relUser);
        }
    }

    if (relUser == firstRel(pUser)) { // delete first
        firstRel(pUser) = nextRel(relUser);
        nextRel(relUser) = NULL;
        nextGroup(relUser)= NULL;
    } else if (nextRel(relUser) == NULL) { // delete last (ide : mencari elm sebelum relUser)
        adrRel prevRel;
        prevRel = firstRel(pUser);
        while (nextRel(nextRel(prevRel)) != NULL) {
            prevRel = nextRel(prevRel);
        }
        nextRel(prevRel) = NULL;
        nextGroup(relUser) = NULL;
    } else { // delete after relation (ide : mencari elm sebelum relUser = precRel)
        adrRel precRel;
        precRel = firstRel(pUser);
        while ( nextRel(precRel) != relUser) {
            precRel = nextRel(precRel);
        }
        nextRel(precRel) = nextRel(relUser);
        nextRel(relUser) = NULL;
        nextGroup(relUser) = NULL;
    }

}

void load_dataset(listUser &LU, listGroup &LG) {
    infotypeUser user;
    infotypeGroup grup;
    adrUser pUser;
    adrGroup pGroup;

    grup.groupName = "SobatHacker";
    grup.numOfMember = 0;
    pGroup = createElmGroup(grup);
    insertLast_Group(LG, pGroup);

    grup.groupName = "RPLa";
    grup.numOfMember = 0;
    pGroup = createElmGroup(grup);
    insertLast_Group(LG, pGroup);

    grup.groupName = "satsetsatset";
    grup.numOfMember = 0;
    pGroup = createElmGroup(grup);
    insertLast_Group(LG, pGroup);

    grup.groupName = "SirkelnyaFariz";
    grup.numOfMember = 0;
    pGroup = createElmGroup(grup);
    insertLast_Group(LG, pGroup);

    grup.groupName = "SirkelnyaMaruf";
    grup.numOfMember = 0;
    pGroup = createElmGroup(grup);
    insertLast_Group(LG, pGroup);

    grup.groupName = "SirkelnyaThaya";
    grup.numOfMember = 0;
    pGroup = createElmGroup(grup);
    insertLast_Group(LG, pGroup);

    grup.groupName = "OSTAIL";
    grup.numOfMember = 0;
    pGroup = createElmGroup(grup);
    insertLast_Group(LG, pGroup);

    grup.groupName = "IF-46-01";
    grup.numOfMember = 0;
    pGroup = createElmGroup(grup);
    insertLast_Group(LG, pGroup);

    grup.groupName = "PeluangMas";
    grup.numOfMember = 0;
    pGroup = createElmGroup(grup);
    insertLast_Group(LG, pGroup);

    grup.groupName = "Futsal01";
    grup.numOfMember = 0;
    pGroup = createElmGroup(grup);
    insertLast_Group(LG, pGroup);

    user.nama = "Dadis";
    user.noTelepon = "0895428453838";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "0895428453838", "IF-46-01");
    joinGroup(LU, LG, "0895428453838", "RPLa");


    user.nama = "Dito";
    user.noTelepon = "081389018701";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081389018701", "SobatHacker");
    joinGroup(LU, LG, "081389018701", "RPLa");
    joinGroup(LU, LG, "081389018701", "SirkelnyaMaruf");
    joinGroup(LU, LG, "081389018701", "OSTAIL");
    joinGroup(LU, LG, "081389018701", "IF-46-01");


    user.nama = "Lia";
    user.noTelepon = "08980234093";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "08980234093", "RPLa");
    joinGroup(LU, LG, "08980234093", "satsetsatset");
    joinGroup(LU, LG, "08980234093", "IF-46-01");


    user.nama = "Farhan";
    user.noTelepon = "085363034836";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "085363034836", "SirkelnyaFariz");
    joinGroup(LU, LG, "085363034836", "IF-46-01");


    user.nama = "William";
    user.noTelepon = "085298306196";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "085298306196", "SirkelnyaMaruf");
    joinGroup(LU, LG, "085298306196", "IF-46-01");


    user.nama = "Hazna";
    user.noTelepon = "082219190071";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "082219190071", "SirkelnyaThaya");
    joinGroup(LU, LG, "082219190071", "IF-46-01");


    user.nama = "Ghefin";
    user.noTelepon = "082268639543";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "082268639543", "SirkelnyaFariz");
    joinGroup(LU, LG, "082268639543", "RPLa");
    joinGroup(LU, LG, "082268639543", "IF-46-01");
    joinGroup(LU, LG, "082268639543", "Futsal01");


    user.nama = "Rifai";
    user.noTelepon = "081296961344";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081296961344", "IF-46-01");
    joinGroup(LU, LG, "081296961344", "Futsal01");


    user.nama = "Reno";
    user.noTelepon = "081286666668";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081286666668", "satsetsatset");
    joinGroup(LU, LG, "081286666668", "IF-46-01");
    joinGroup(LU, LG, "081286666668", "Futsal01");


    user.nama = "Hansel";
    user.noTelepon = "089517351725";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "089517351725", "SirkelnyaMaruf");
    joinGroup(LU, LG, "089517351725", "IF-46-01");


    user.nama = "Nailah";
    user.noTelepon = "081355941901";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081355941901", "SirkelnyaMaruf");
    joinGroup(LU, LG, "081355941901", "RPLa");
    joinGroup(LU, LG, "081355941901", "IF-46-01");


    user.nama = "Adi";
    user.noTelepon = "0895611699012";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "0895611699012", "satsetsatset");
    joinGroup(LU, LG, "0895611699012", "Futsal01");
    joinGroup(LU, LG, "0895611699012", "IF-46-01");


    user.nama = "Bagas";
    user.noTelepon = "087764096244";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "087764096244", "SirkelnyaFariz");
    joinGroup(LU, LG, "087764096244", "IF-46-01");


    user.nama = "Iqbal";
    user.noTelepon = "081931390430";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081931390430", "satsetsatset");
    joinGroup(LU, LG, "081931390430", "IF-46-01");
    joinGroup(LU, LG, "081931390430", "Futsal01");


    user.nama = "Bryan";
    user.noTelepon = "081364673045";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081364673045", "RPLa");
    joinGroup(LU, LG, "081364673045", "SirkelnyaMaruf");
    joinGroup(LU, LG, "081364673045", "OSTAIL");
    joinGroup(LU, LG, "081364673045", "IF-46-01");


    user.nama = "Fariz";
    user.noTelepon = "081236718873";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081236718873", "SobatHacker");
    joinGroup(LU, LG, "081236718873", "RPLa");
    joinGroup(LU, LG, "081236718873", "SirkelnyaFariz");
    joinGroup(LU, LG, "081236718873", "IF-46-01");
    joinGroup(LU, LG, "081236718873", "PeluangMas");


    user.nama = "Vito";
    user.noTelepon = "081910211428";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081910211428", "RPLa");
    joinGroup(LU, LG, "081910211428", "SirkelnyaMaruf");
    joinGroup(LU, LG, "081910211428", "IF-46-01");


    user.nama = "Maruf";
    user.noTelepon = "082133628466";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "082133628466", "RPLa");
    joinGroup(LU, LG, "082133628466", "SirkelnyaMaruf");
    joinGroup(LU, LG, "082133628466", "IF-46-01");


    user.nama = "Ando";
    user.noTelepon = "081248898619";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081248898619", "RPLa");
    joinGroup(LU, LG, "081248898619", "satsetsatset");
    joinGroup(LU, LG, "081248898619", "OSTAIL");
    joinGroup(LU, LG, "081248898619", "IF-46-01");
    joinGroup(LU, LG, "081248898619", "Futsal01");


    user.nama = "Bagja";
    user.noTelepon = "081320997664";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081320997664", "RPLa");
    joinGroup(LU, LG, "081320997664", "SirkelnyaFariz");
    joinGroup(LU, LG, "081320997664", "IF-46-01");


    user.nama = "Haidar";
    user.noTelepon = "0811952818";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "0811952818", "RPLa");
    joinGroup(LU, LG, "0811952818", "SirkelnyaFariz");
    joinGroup(LU, LG, "0811952818", "IF-46-01");
    joinGroup(LU, LG, "0811952818", "Futsal01");


    user.nama = "Imam";
    user.noTelepon = "0895414985953";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "0895414985953", "SobatHacker");
    joinGroup(LU, LG, "0895414985953", "RPLa");
    joinGroup(LU, LG, "0895414985953", "satsetsatset");
    joinGroup(LU, LG, "0895414985953", "IF-46-01");
    joinGroup(LU, LG, "0895414985953", "OSTAIL");
    joinGroup(LU, LG, "0895414985953", "Futsal01");
    joinGroup(LU, LG, "0895414985953", "PeluangMas");


    user.nama = "Widya";
    user.noTelepon = "081383278120";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081383278120", "SirkelnyaMaruf");
    joinGroup(LU, LG, "081383278120", "IF-46-01");


    user.nama = "Abdul";
    user.noTelepon = "081219148751";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081219148751", "satsetsatset");
    joinGroup(LU, LG, "081219148751", "IF-46-01");
    joinGroup(LU, LG, "081219148751", "Futsal01");


    user.nama = "Della";
    user.noTelepon = "082141730402";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "082141730402", "RPLa");
    joinGroup(LU, LG, "082141730402", "satsetsatset");
    joinGroup(LU, LG, "082141730402", "IF-46-01");


    user.nama = "Dzaki";
    user.noTelepon = "081313308020";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081313308020", "SirkelnyaFariz");
    joinGroup(LU, LG, "081313308020", "IF-46-01");
    joinGroup(LU, LG, "081313308020", "Futsal01");


    user.nama = "Iqal";
    user.noTelepon = "081318188273";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081318188273", "satsetsatset");
    joinGroup(LU, LG, "081318188273", "Futsal01");
    joinGroup(LU, LG, "081318188273", "IF-46-01");


    user.nama = "Hilal";
    user.noTelepon = "088218012536";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "088218012536", "SobatHacker");
    joinGroup(LU, LG, "088218012536", "RPLa");
    joinGroup(LU, LG, "088218012536", "satsetsatset");
    joinGroup(LU, LG, "088218012536", "OSTAIL");
    joinGroup(LU, LG, "088218012536", "IF-46-01");
    joinGroup(LU, LG, "088218012536", "PeluangMas");
    joinGroup(LU, LG, "088218012536", "Futsal01");


    user.nama = "Thaya";
    user.noTelepon = "082120969060";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "082120969060", "RPLa");
    joinGroup(LU, LG, "082120969060", "SirkelnyaThaya");
    joinGroup(LU, LG, "082120969060", "IF-46-01");


    user.nama = "Ali";
    user.noTelepon = "081220307648";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081220307648", "RPLa");
    joinGroup(LU, LG, "081220307648", "SirkelnyaFariz");
    joinGroup(LU, LG, "081220307648", "IF-46-01");


    user.nama = "Nabil";
    user.noTelepon = "085155440510";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "085155440510", "satsetsatset");
    joinGroup(LU, LG, "085155440510", "IF-46-01");


    user.nama = "Najwa";
    user.noTelepon = "08561170188";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "08561170188", "SirkelnyaThaya");
    joinGroup(LU, LG, "08561170188", "IF-46-01");


    user.nama = "Dior";
    user.noTelepon = "081364604772";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081364604772", "satsetsatset");
    joinGroup(LU, LG, "081364604772", "Futsal01");
    joinGroup(LU, LG, "081364604772", "IF-46-01");


    user.nama = "Riyan";
    user.noTelepon = "089512504822";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "089512504822", "SirkelnyaMaruf");
    joinGroup(LU, LG, "089512504822", "IF-46-01");


    user.nama = "Hanum";
    user.noTelepon = "082181757523";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "082181757523", "SirkelnyaThaya");
    joinGroup(LU, LG, "082181757523", "IF-46-01");


    user.nama = "Rafli";
    user.noTelepon = "08158739862";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "08158739862", "IF-46-01");
    joinGroup(LU, LG, "08158739862", "SirkelnyaFariz");


    user.nama = "Akmal";
    user.noTelepon = "081282598846";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081282598846", "SirkelnyaFariz");
    joinGroup(LU, LG, "081282598846", "Futsal01");
    joinGroup(LU, LG, "081282598846", "IF-46-01");


    user.nama = "Ibnu";
    user.noTelepon = "081225122418";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "081225122418", "RPLa");
    joinGroup(LU, LG, "081225122418", "SirkelnyaFariz");
    joinGroup(LU, LG, "081225122418", "IF-46-01");


    user.nama = "Rafel";
    user.noTelepon = "085714184281";
    pUser = createElmUser(user);
    insertLast_User(LU, pUser);
    joinGroup(LU, LG, "085714184281", "RPLa");
    joinGroup(LU, LG, "085714184281", "satsetsatset");
    joinGroup(LU, LG, "085714184281", "OSTAIL");
    joinGroup(LU, LG, "085714184281", "IF-46-01");

}