#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
include <iostream>

using namespace std;
typedef struct elmBuku *adrBuku;
typedef struct elmKey *adrKey;
struct buku{
    string kode;
    string judul;
    string pengarang;
    int tahun;
    string kategori;
};
struct KeyWord{
    string key;
};
struct elmBuku{
    buku info;
    adrBuku next;
    adrBuku prev;
    adrKey firstKeyword;
};
struct elmKey{
    KataKunci info;
    adrKey next;
    adrKey prev;
};
struct listBuku{
    adrBuku first;
    adrBuku last;
};

void createListBuku(listBuku &L);
bool isEmptyBuku(listBuku L);
bool isEmptyKey(adrBuku p);
adrBuku createElementBuku(string kode, string judul, string pengarang, int tahun, string kategori);
adrKey createElementKey(string key);

// pake insert last
void addBuku(listBuku &L, adrBuku p);
void addKey(adrBuku &p, adrKey q);

deleteBuku();
deleteKey();

adrBuku searchBukuJudul(listBuku L, string judul);
adrBuku searchBukuPengarang(listBuku L, string pengarang);
adrBuku searchBukuKategori(listBuku L, string kategori);
adrBuku searchBukuKey();

int jmlBukuPerKategori(listBuku L);
adrBuku displayBukuTahunLamaDanBaru(listBuku L);
adrBuku displayBukuKey(listBuku L, string key);

void displayListBuku(listBuku L);

#endif // HEADER_H_INCLUDED
