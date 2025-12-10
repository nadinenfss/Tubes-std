#include "header.h"

void createListBuku(listBuku &L){
    L.first = nullptr;
    L.last = nullptr;
};
bool isEmptyBuku(listBuku L){
    return L.first == nullptr && L.last == nullptr;
};
bool isEmptyKey(adrBuku p){
    return p->firstKeyword == nullptr;
};
adrBuku createElementBuku(string kode, string judul, string pengarang, int tahun, string kategori){
    adrBuku p = new elmBuku;
    p->info.kode = kode;
    p->info.judul = judul;
    p->info.pengarang = pengarang;
    p->info.tahun = tahun;
    p->info.kategori = kategori;
    p->next = nullptr;
    p->prev = nullptr;
    p->firstKeyword = nullptr;
    return p;
};
adrKey createElementKey(string key){
    adrKey q = new elmKey;
    q->info.key = key;
    q->next = nullptr;
    q->prev = nullptr:
    return q;
};

void addBuku(listBuku &L, adrBuku p){ // pake insert last
    if (isEmptyBuku(L)){
        L.first = p;
        L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = L.last->next;
    }
};
void addKey(adrBuku &p, adrKey q){ // pake insert last
    if () {
        L.
        L
    } else {
        p
        while () {
            r
        }
    }
};

deleteBuku();
deleteKey();

adrBuku searchBukuJudul(listBuku L, string judul){
};

adrBuku searchBukuPengarang(listBuku L, string pengarang){
};
adrBuku searchBukuKategori(listBuku L, string kategori);{
}
adrBuku searchBukuKey(){
};

int jmlBukuPerKategori(listBuku L){
};

adrBuku displayBukuTahunLamaDanBaru(listBuku L){
};
adrBuku displayBukuKey(listBuku L, string key);{
}
void displayListBuku(listBuku L);{

}
