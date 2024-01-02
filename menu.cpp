#include "whatsApp.h"

void menu() {
    cout << "*==================================================*" << endl;
    cout << "|                       MENU                       |" << endl;
    cout << "*==================================================*" << endl;
    cout << "|                                                  |" << endl;
    cout << "|      1. Insert data grup dari belakang (5)       |" << endl;
    cout << "|                                                  |" << endl;
    cout << "|      2. Show all data grup (5)                   |" << endl;
    cout << "|                                                  |" << endl;
    cout << "|      3. Menghapus data grup beserta              |" << endl;
    cout << "|         relasinya (15)                           |" << endl;
    cout << "|                                                  |" << endl;
    cout << "|      4. Mencari data grup (5)                    |" << endl;
    cout << "|                                                  |" << endl;
    cout << "|      5. Mencari data user (5)                    |" << endl;
    cout << "|                                                  |" << endl;
    cout << "|      6. Menambahkan data user (5)                |" << endl;
    cout << "|                                                  |" << endl;
    cout << "|      7. Menghubungkan data grup ke data          |" << endl;
    cout << "|         user (5)                                 |" << endl;
    cout << "|                                                  |" << endl;
    cout << "|      8. Menampilkan seluruh data grup            |" << endl;
    cout << "|         beserta usernya (15)                     |" << endl;
    cout << "|                                                  |" << endl;
    cout << "|      9. Mencari data user pada grup              |" << endl;
    cout << "|         tertentu (10)                            |" << endl;
    cout << "|                                                  |" << endl;
    cout << "|      10. Menghapus data user pada grup           |" << endl;
    cout << "|          tertentu beserta relasinya (15)         |" << endl;
    cout << "|                                                  |" << endl;
    cout << "|      11. Menampilkan data grup yang jumlah       |" << endl;
    cout << "|          usernya di bawah 5 orang (5)            |" << endl;
    cout << "|                                                  |" << endl;
    cout << "|      0. Keluar                                   |" << endl;
    cout << "|                                                  |" << endl;
    cout << "*==================================================*" << endl;
    cout << endl;
}

void takeOption(string &option) {
    cout << "*==================================================*" << endl;
    cout << "|                Masukkan Pilihan Menu             |" << endl;
    cout << "*==================================================*" << endl;
    cout << "  Masukkan Pilihan Anda: ";
    cin >> option;
    cout << endl;
    while (option != "0" && option != "1" && option != "2" && option != "3" && option != "4" && option != "5" && option != "6" && option != "7" &&
           option != "8" && option != "9" && option != "10" && option != "11") {
        cout << "*==================================================*" << endl;
        cout << "|                Masukkan Salah!!!                 |" << endl;
        cout << "|          Mohon Masukkan angka yang benar         |" << endl;
        cout << "*==================================================*" << endl;
        cout << "  Masukkan Pilihan Anda: ";
        cin >> option;
        cout << endl;
    }
}
// 1. Insert data grup dari belakang (5)
void addGroups(listGroup &LG, string &option) {
    infotypeGroup grup;
    adrGroup pGroup;
    cout << "*==================================================*" << endl;
    cout << "|                   Input Data Group               |" << endl;
    cout << "*==================================================*" << endl;
    cout << "  Masukkan Nama Grup: ";
    cin >> grup.groupName;
    grup.numOfMember = 0;

    pGroup = searchData_Group(LG, grup.groupName);
    if (pGroup == NULL) {
        pGroup = createElmGroup(grup);
        insertLast_Group(LG, pGroup);
        cout << "*==================================================*" << endl;
        cout << "|                  Input Data Sukses               |" << endl;
        cout << "*==================================================*" << endl;
        cout << endl;
    } else {
        cout << "*==================================================*" << endl;
        cout << "|               Group Already Exsisted             |" << endl;
        cout << "*==================================================*" << endl;
    }

    cout << "  Kembali ke Menu ketik (Y/N): ";
    cin >> option;
    cout << endl;
}

// 2.Show all data grup (5)
void showAlldata_Group(listGroup LG, string &option) {
    cout << "*==================================================*" << endl;
    cout << "|                     Daftar Grup                  |" << endl;
    cout << "*==================================================*" << endl;
    cout << endl;
    if (firstGroup(LG) == NULL) {
        cout << "*==================================================*" << endl;
        cout << "|                Group Not Created Yet             |" << endl;
        cout << "*==================================================*" << endl;
        cout << endl;
    } else {
        adrGroup Q;
        Q = firstGroup(LG);
        cout << "*==================================================*" << endl;
        do {
            cout << "  Group Name : " << infoGroup(Q).groupName << endl;
            cout << "  Member : " << infoGroup(Q).numOfMember << endl;
            cout << endl;
            Q = nextGroup(Q);
        } while (nextGroup(Q) != nextGroup(firstGroup(LG)));
        cout << "*==================================================*" << endl;
        cout << endl;
    }
    cout << "  Kembali ke Menu ketik (Y/N): ";
    cin >> option;
    cout << endl;
}

// 3.	Menghapus data grup beserta relasinya (15) PROGRESS
void hapusGrup(listUser &LU, listGroup &LG, string &option) {
    string namaGroup;
    adrGroup delGroup;
    cout << "*==================================================*" << endl;
    cout << "|                    Delete Group                  |" << endl;
    cout << "*==================================================*" << endl;
    cout << "  Masukkan Nama Group yang ingin dihapus: ";
    cin >> namaGroup;
    cout << endl;
    if (searchData_Group(LG, namaGroup) != NULL) {
        deleteGroup_rel(LG, LU, namaGroup, delGroup);
        cout << "*==================================================*" << endl;
        cout << "|                Delete Group Success              |" << endl;
        cout << "*==================================================*" << endl;
        cout << endl;
    } else {
        cout << "*==================================================*" << endl;
        cout << "|                   Group Not Found                |" << endl;
        cout << "|       Make Sure To Input Correct Group Name      |" << endl;
        cout << "*==================================================*" << endl;
        cout << endl;
    }
    cout << "  Kembali ke Menu ketik (Y/N): ";
    cin >> option;
    cout << endl;
}


// 4.	Mencari data grup (5) DONE
void cariDataGrup(listGroup LG, string &option) {
    string namaGroup;
    adrGroup pGroup;
    cout << "*==================================================*" << endl;
    cout << "|                    Search Group                  |" << endl;
    cout << "*==================================================*" << endl;
    cout << "  Masukkan Nama Group yang ingin dicari: ";
    cin >> namaGroup;
    cout << endl;
    pGroup = searchData_Group(LG, namaGroup);
    if (pGroup != NULL) {
        cout << "*==================================================*" << endl;
        cout << "  Address Group in memory: " << pGroup << endl;
        cout << endl;
        cout << "  Info Group" << endl;
        cout << "  Nama Group: " << infoGroup(pGroup).groupName << endl;
        cout << "  Anggota: " << infoGroup(pGroup).numOfMember << endl;
        cout << "*==================================================*" << endl;
        cout << endl;
    } else {
        cout << "*==================================================*" << endl;
        cout << "|                   Group Not Found                |" << endl;
        cout << "|       Make Sure To Input Correct Group Name      |" << endl;
        cout << "*==================================================*" << endl;
        cout << endl;
    }
    cout << "  Kembali ke Menu ketik (Y/N): ";
    cin >> option;
    cout << endl;
}

// 5.	Mencari data user (5) NOT YET
void cariDataUser(listUser LU, string &option) {
    string noTelepon;
    adrUser pUser;
    cout << "*==================================================*" << endl;
    cout << "|                     Search User                  |" << endl;
    cout << "*==================================================*" << endl;
    cout << "  Masukkan No Telepon User yang ingin dicari: ";
    cin >> noTelepon;
    cout << endl;
    pUser = searchData_User(LU, noTelepon);
    if (pUser != NULL) {
        cout << "*==================================================*" << endl;
        cout << "  Address User in memory: " << pUser << endl;
        cout << endl;
        cout << "  Info User" << endl;
        cout << "  Nama User: " << infoUser(pUser).nama << endl;
        cout << "  No Telepon: " << infoUser(pUser).noTelepon << endl;
        cout << "*==================================================*" << endl;
        cout << endl;
    } else {
        cout << "*==================================================*" << endl;
        cout << "|                   User Not Found                 |" << endl;
        cout << "|      Make Sure To Input Correct Phone Number     |" << endl;
        cout << "*==================================================*" << endl;
        cout << endl;
    }
    cout << "  Kembali ke Menu ketik (Y/N): ";
    cin >> option;
    cout << endl;
}

// 6.	Menambahkan data user (5) NOT YET
void addUsers(listUser &LU, string &option) {
    infotypeUser user;
    adrUser pUser;
    cout << "*==================================================*" << endl;
    cout << "|                   Input Data User                |" << endl;
    cout << "*==================================================*" << endl;
    cout << "  Masukkan Nama Pengguna: ";
    cin >> user.nama;
    cout << "  Masukkan No Telepon: ";
    cin >> user.noTelepon;

    pUser = searchData_User(LU, user.noTelepon);
    if (pUser == NULL) {
        pUser = createElmUser(user);
        insertLast_User(LU, pUser);
        cout << "*==================================================*" << endl;
        cout << "|                  Input Data Sukses               |" << endl;
        cout << "*==================================================*" << endl;
        cout << endl;
    } else {
        cout << "*==================================================*" << endl;
        cout << "|             Phone Number Already Used            |" << endl;
        cout << "|      Make Sure To Input Correct Phone Number     |" << endl;
        cout << "*==================================================*" << endl;
        cout << endl;
    }
    cout << "  Kembali ke Menu ketik (Y/N): ";
    cin >> option;
    cout << endl;
}

// 7.	Menghubungkan data grup ke data user (5) NOT YET
void joinGroup_menu(listUser &LU, listGroup &LG, string &option) {
    string noTelepon, namaGroup;
    do {
        cout << "*==================================================*" << endl;
        cout << "|                     Join Group                   |" << endl;
        cout << "*==================================================*" << endl;
        cout << "  Masukkan No Telepon Anda: ";
        cin >> noTelepon;
        cout << "  Masukkan Nama Group yang Anda ingin bergabung: ";
        cin >> namaGroup;
        cout << endl;

        adrUser pUser = searchData_User(LU, noTelepon);
        adrGroup pGroup = searchData_Group(LG, namaGroup);
        adrRel pRel = searchData_Rel(LU, LG, namaGroup, pUser);
        if (pUser != NULL) {
            if (pGroup != NULL) {
                if (pRel == NULL) {
                    joinGroup(LU,LG,noTelepon,namaGroup);
                    cout << "*==================================================*" << endl;
                    cout << "  " << noTelepon << " Joined " << namaGroup << "." << endl;
                    cout << "*==================================================*" << endl;
                    cout << endl;
                    option = "n";
                } else {
                    cout << "*==================================================*" << endl;
                    cout << "  You've already Join Group " << namaGroup << endl;
                    cout << "*==================================================*" << endl;
                    cout << endl;
                    option = "n";
                }
            } else {
                cout << "*==================================================*" << endl;
                cout << "|                   Group Not Found                |" << endl;
                cout << "|       Make Sure To Input Correct Group Name      |" << endl;
                cout << "*==================================================*" << endl;
                cout << "  Ingin input ulang? (Y/N): ";
                cin >> option;
                cout << endl;
            }
        } else {
            cout << "*==================================================*" << endl;
            cout << "|                   User Not Found                 |" << endl;
            cout << "|      Make Sure To Input Correct Phone Number     |" << endl;
            cout << "*==================================================*" << endl;
            cout << "  Ingin input ulang? (Y/N): ";
            cin >> option;
            cout << endl;
        }
    } while (option == "Y" || option == "y");
    cout << "  Kembali ke Menu ketik (Y/N): ";
    cin >> option;
    cout << endl;
}

// 8.	Menampilkan seluruh data grup beserta usernya (15) NOT YET
void showGroupMember(listGroup LG, listUser LU, string &option) {
    cout << "*==================================================*" << endl;
    cout << "|                Show Group and Member             |" << endl;
    cout << "*==================================================*" << endl;
    cout << endl;
    adrUser pUser;
    adrGroup pGroup = firstGroup(LG);
    adrRel pRel;

    if (pGroup == NULL) {
        cout << "*==================================================*" << endl;
        cout << "|               Group Not Created Yet              |" << endl;
        cout << "|          Make Sure To create Group First         |" << endl;
        cout << "*==================================================*" << endl;
        cout << endl;
    } else {
        do {
            pUser = firstUser(LU);
            int i = 1;
            cout << "*==================================================*" << endl;
            cout << "  " << infoGroup(pGroup).groupName << endl;
            cout << "*==================================================*" << endl;
            while (pUser != NULL) {
                pRel = firstRel(pUser);
                while (pRel != NULL) {
                    if (infoGroup(nextGroup(pRel)).groupName == infoGroup(pGroup).groupName) {
                        cout << "  " << i << ". " << infoUser(pUser).nama << " ( " << infoUser(pUser).noTelepon << " )" << endl;
                        i++;
                    }
                    pRel = nextRel(pRel);
                }
                pUser = nextUser(pUser);
            }
            pGroup = nextGroup(pGroup);
        } while (nextGroup(pGroup) != nextGroup(firstGroup(LG)));
    }
    cout << "*==================================================*" << endl;
    cout << endl;
    cout << "  Kembali ke Menu ketik (Y/N): ";
    cin >> option;
    cout << endl;
}

// 9.	Mencari data user pada grup tertentu (10) NOT YET
void searchUserinGroup(listGroup LG, listUser LU, string &option) {
    string noTelepon, namaGroup;
    cout << "*==================================================*" << endl;
    cout << "|               Search Member In Group             |" << endl;
    cout << "*==================================================*" << endl;
    cout << "  Masukkan nomor telepon user yang dicari: ";
    cin >> noTelepon;
    cout << "  Masukkan nama group user berada: ";
    cin >> namaGroup;
    cout << endl;
    adrUser pUser = searchData_User(LU, noTelepon);
    adrGroup pGroup = searchData_Group(LG, namaGroup);
    adrRel pRel;
    if (pUser != NULL) {
        if (pGroup != NULL) {
            pRel = searchData_Rel(LU, LG, namaGroup, pUser);
            if (pRel != NULL) {
                cout << "*==================================================*" << endl;
                cout << "  " << infoUser(pUser).nama << " (" << infoUser(pUser).noTelepon << ") tergabung di grup " << infoGroup(nextGroup(pRel)).groupName << endl;
                cout << "*==================================================*" << endl;
                cout << endl;
            } else {
                cout << "*==================================================*" << endl;
                cout << "  " << infoUser(pUser).nama << " (" << infoUser(pUser).noTelepon << ") Not Member of " << namaGroup << endl;
                cout << "*==================================================*" << endl;
                cout << endl;
            }
        } else {
            cout << "*==================================================*" << endl;
            cout << "|                   Group Not Found                |" << endl;
            cout << "|       Make Sure To Input Correct Group Name      |" << endl;
            cout << "*==================================================*" << endl;
        }
    } else {
        cout << "*==================================================*" << endl;
        cout << "|                 User Not Added Yet               |" << endl;
        cout << "|           Make Sure To create User First         |" << endl;
        cout << "*==================================================*" << endl;
        cout << endl;
    }
    cout << "  Kembali ke Menu ketik (Y/N): ";
    cin >> option;
    cout << endl;
}

// 10.	Menghapus data user pada grup tertentu beserta relasinya (15) NOT YET
void leftGroupMenu(listUser &LU, listGroup &LG, string &option) {
    string noTelepon, namaGroup;
    cout << "*==================================================*" << endl;
    cout << "|                     Left Group                   |" << endl;
    cout << "*==================================================*" << endl;
    cout << "  Masukkan No Telepon Anda: ";
    cin >> noTelepon;
    cout << "  Masukkan Nama Group yang Anda ingin Keluar: ";
    cin >> namaGroup;
    cout << endl;
    adrUser pUser = searchData_User(LU,noTelepon);
    adrRel pRel = searchData_Rel(LU, LG, namaGroup, pUser);
    if (pUser != NULL) {
        if (pRel != NULL) {
            leftGroup(LU,LG,noTelepon,namaGroup);
            cout << "*==================================================*" << endl;
            cout << "  " << infoUser(pUser).nama  << " Kicked from " << namaGroup << "." << endl;
            cout << "*==================================================*" << endl;
            cout << endl;
        } else {
            cout << "*==================================================*" << endl;
            cout << "  You're Not a member of " << namaGroup << endl;
            cout << "*==================================================*" << endl;
            cout << endl;
        }
    } else {
        cout << "*==================================================*" << endl;
        cout << "|                   User Not Found                 |" << endl;
        cout << "|      Make Sure To Input Correct Phone Number     |" << endl;
        cout << "*==================================================*" << endl;
        cout << endl;
    }
    cout << "  Kembali ke Menu ketik (Y/N): ";
    cin >> option;
    cout << endl;
}

// 11.	Menampilkan data grup yang jumlah usernya di bawah 5 orang (5) NOT YET
void showGroupMem5(listGroup LG, string &option) {
    adrGroup pGroup = firstGroup(LG);
    int Count = 0;
    cout << "*==================================================*" << endl;
    cout << "|                 Group Below 5 Member             |" << endl;
    cout << "*==================================================*" << endl;
    if (firstGroup(LG) == NULL) {
        cout << "*==================================================*" << endl;
        cout << "|                Group Not Created Yet             |" << endl;
        cout << "*==================================================*" << endl;
        cout << endl;
    } else {
        pGroup = firstGroup(LG);
        cout << "*==================================================*" << endl;
        do {
            if (infoGroup(pGroup).numOfMember < 5) {
                cout << "  Group Name : " << infoGroup(pGroup).groupName << endl;
                cout << "  Member : " << infoGroup(pGroup).numOfMember << endl;
                cout << endl;
                Count++;
            }
            pGroup = nextGroup(pGroup);
        } while (nextGroup(pGroup) != nextGroup(firstGroup(LG)));
        if (Count == 0) {
            cout << "|          NO GROUP HAS MEMBER LESS THEN 5         |" << endl;
        }
        cout << "*==================================================*" << endl;
        cout << endl;
    }
    cout << "  Kembali ke Menu ketik (Y/N): ";
    cin >> option;
    cout << endl;
}
