#include <iostream>
#include "header.h"

using namespace std;

int main() {
    listKategori L;
    string jdl, pengarang, ktg, kode;
    int menu;
    string KK1[maxKey],KK2[maxKey], KK3[maxKey], KK4[maxKey], KK5[maxKey];
    string KK6[maxKey],KK7[maxKey], KK8[maxKey], KK9[maxKey], KK10[maxKey];

    createListKategori(L);

    adrKategori k1 = createElmKategori("Sejarah");
    adrKategori k2 = createElmKategori("Fiksi");
    adrKategori k3 = createElmKategori("Sastra");
    adrKategori k4 = createElmKategori("Sains");
    adrKategori k5 = createElmKategori("Teknologi");

    addKategori(L, k1);
    addKategori(L, k2);
    addKategori(L, k3);
    addKategori(L, k4);
    addKategori(L, k5);

    KK1[0] = "Perang"; // kategori sejarah
    KK1[1] = "Nasionalisme";
    KK1[2] = "Kemerdekaan";
    addBuku(k1, createElmBuku("S001", "Sejarah_Indonesia", "Sartono_Kartodirdjo", 1990, KK1, 420));
    KK2[0] = "Kolonial";
    KK2[1] = "Revolusi";
    KK2[2] = "Perjuangan";
    addBuku(k1, createElmBuku("S002", "Revolusi_Indonesia", "Taufik_Abdullah", 1988, KK2, 350));

    KK3[0] = "Fantasi"; // kategori Fiksi
    KK3[1] = "Politik";
    addBuku(k2, createElmBuku("F001", "Dune", "Frank_Herbert", 1965, KK3, 412));
    KK4[0] = "Petualangan";
    KK4[1] = "Sihir";
    KK4[2] = "Persahabatan";
    addBuku(k2, createElmBuku("F002", "Harry_Potter_and_the_Philosopher's_Stone", "J.K._Rowling", 1997, KK4, 384));
    KK10[0] = "Politik";
    KK10[1] = "Kemanusiaan";
    KK10[2] = "Tragedi_1998";
    addBuku(k2, createElmBuku("F003", "Laut_Bercerita", "Leila_S._Chudori", 2017, KK10, 379));

    KK5[0] = "Novel"; // kategori sastra
    KK5[1] = "Pendidikan";
    KK5[2] = "Persahabatan";
    addBuku(k3, createElmBuku("L001", "Laskar_Pelangi", "Andrea_Hirata", 2005, KK5, 524));
    KK6[0] = "Indonesia";
    KK6[2] = "Perjuangan";
    addBuku(k3, createElmBuku("L002", "Bumi_Manusia", "Pramoedya_Ananta_Toer", 1980, KK6, 420));

    KK7[0] = "Fisika"; // kategori sains
    KK7[1] = "Kosmologi";
    addBuku(k4, createElmBuku("SC001","A_Brief_History_of_Time", "Stephen_Hawking",1988, KK7 ,256));

    KK8[0] = "Algoritma";  // kategori teknologi
    KK8[1] = "Struktur_Data";
    KK8[2] = "Komputasi";
    addBuku(k5, createElmBuku("T001", "Introduction_to_Algorithms", "Thomas_H._Cormen", 2009, KK8, 1312 ));
    KK9[0] = "Pemrograman";
    KK9[1] = "Perangkat_ Lunak";
    addBuku(k5, createElmBuku("T002", "Clean_Code", "Robert_C._Martin", 2008, KK9, 464));


    while (true) {
        cout << "---------------------------------------------" << endl;
        cout << "|                                           |" << endl;
        cout << "|        Welcome to the Library Book        |" << endl;
        cout << "|           Collection Management           |" << endl;
        cout << "|                                           |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "                  Main Menu                  " << endl;
        cout << "1. add category" << endl;
        cout << "2. add book" << endl;
        cout << "3. search for book" << endl;
        cout << "4. display all books" << endl;
        cout << "5. delete category" << endl;
        cout << "6. delete book" << endl;
        cout << "7. count books by category" << endl;
        cout << "8. show books by old and new publication year" << endl;
        cout << "9. show average of book pages by category" << endl;
        cout << "10. update data" << endl;
        cout << "11. exit" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Choose 1/2/3/4/5/6/7/8/9/10/11" << endl;

        cin >> menu;

        switch (menu) {
            case 1: {
                formAddCategory(L);
                break;
            } case 2: {
                formAddBook(L);
                break;
            } case 3: {
                formSearchBook(L);
                break;
            } case 4: {
                displayList(L);
                break;
            } case 5: {
                deleteKategori(L);
                break;
            } case 6: {
                deleteBuku(L);
                break;
            } case 7: {
                formCountBooksByCategory(L);
                break;
            } case 8: {
                formShowBooksByPublicationYear(L);
                break;
            } case 9:{
                formShowAvgPagesByCategory(L);
                break;
            } case 10: {
                formUpdateList(L);
                break;
           } case 11: {
                return 0;
                break;
            } default: {
                cout << "Please input the valid number ^___^" << endl;
                break;
            }
            };
    };

    cout << endl;
    return 0;
};
