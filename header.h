#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>

using namespace std;

const int maxKey = 20;

typedef struct elmKategori *adrKategori;
typedef struct elmBuku *adrBuku;
typedef string key[maxKey];

struct kategori{
    string namaKat;
};

struct buku{
    string kode;
    string judul;
    string pengarang;
    int tahun;
    key katakunci;
    int hlm;
};

struct elmKategori{
    kategori info;
    adrKategori next;
    adrKategori prev;
    adrBuku firstBuku;
};

struct elmBuku{
    buku info;
    adrBuku next;
    adrBuku prev;
};

struct listKategori{
    adrKategori first;
    adrKategori last;
};

void createListKategori(listKategori &L);

bool isEmptyKategori(listKategori L);
bool isEmptyBuku(adrKategori k);

adrKategori createElmKategori(string nama);
adrBuku createElmBuku(string kode, string judul, string pengarang, int tahun, key katakunci, int hlm);

void addKategori(listKategori &L, adrKategori k);
void addBuku(adrKategori &k, adrBuku p);

adrKategori searchKategori(listKategori L, string kategori);
adrBuku searchBukuJudul(listKategori L, string judul);
adrBuku searchBukuPengarang(listKategori L, string pengarang);
void searchBukuKeyword(listKategori L, string keyword);
adrBuku searchBukuTahun(listKategori L, int tahun);
adrBuku searchBukuKode(listKategori L, string kode);

void updateBook(listKategori &L);
void updateCategory(listKategori &L);

void displayDetailBuku(adrBuku p);
void displayList(listKategori L);

//menu
void deleteKategori(listKategori &L);
void deleteBuku(listKategori &L);

void formAddCategory(listKategori &L);
void formAddBook(listKategori &L);
void formSearchBook(listKategori L);
void formCountBooksByCategory(listKategori K);
void formShowBooksByPublicationYear(listKategori L);
void formShowAvgPagesByCategory(listKategori L);
void formUpdateList(listKategori &L);

#endif // HEADER_H_INCLUDED
