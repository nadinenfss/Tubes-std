#include <iostream>
#include "header.h"
#define Nil NULL

using namespace std;

void createListKategori(listKategori &L){
    L.first = NULL;
    L.last = NULL;
}

bool isEmptyKategori(listKategori L){
    return L.first == NULL;
}
bool isEmptyBuku(adrKategori k){
    return k->firstBuku == NULL;
}

adrKategori createElmKategori(string nama){
    adrKategori k = new elmKategori;
    k->info.namaKat = nama;
    k->next = NULL;
    k->prev = NULL;
    k->firstBuku = NULL;
    return k;
}
adrBuku createElmBuku(string kode, string judul, string pengarang, int tahun, key katakunci, int hlm){
    int i;
    adrBuku p = new elmBuku;
    p->info.kode = kode;
    p->info.judul = judul;
    p->info.pengarang = pengarang;
    p->info.tahun = tahun;
    p->info.hlm = hlm;
    for (i=0; i<maxKey; i++) {
        p->info.katakunci[i] = katakunci[i];
    }

    p->next = NULL;
    p->prev = NULL;
    return p;
}

void addKategori(listKategori &L, adrKategori k){
    if (isEmptyKategori(L)){
        L.first = k;
        L.last = k;
    } else {
        k->prev = L.last;
        L.last->next = k;
        L.last = k;
    }
}
void addBuku(adrKategori &k, adrBuku p){
    if (isEmptyBuku(k)){
        k->firstBuku = p;
    } else {
        adrBuku r = k->firstBuku;
        while (r->next != NULL){
            r = r->next;
        }
        r->next = p;
        p->prev = r;
        p->next = NULL;
    }
}

void deleteBuku(listKategori &L){
    string ktg, kode;

    cout << "insert category: ";
    cin >> ktg;
    adrKategori k = searchKategori(L, ktg);
    if (k == NULL){
        cout << "Category not found! Please insert available categories or choose menu number 1 (add category)!\n";
    } else {
        cout << "insert book code: ";
        cin >> kode;
        adrBuku p = k->firstBuku;

        while (p != NULL && p->info.kode != kode){ // cari buku
            p = p->next;
        }
        // hapus buku
        if (p == NULL) {
            cout << "Book not found!";
        } else {
            if (p->prev == NULL && p->next == NULL) { // buku hanya 1
                k->firstBuku = NULL;
            } else if (p->prev == NULL){ // buku di awal
                k->firstBuku = p->next;
                p->next->prev = NULL;
            } else if (p->next == NULL){ // buku di akhir
                p->prev->next = NULL;
            } else {
                p->prev->next = p->next; // buku di tengah
                p->next->prev = p->prev;
            }
            p = NULL;
            cout << "Book deleted succesfully! " << endl;
        }
    }
}

void deleteKategori(listKategori &L){
    string ktg;

    cout << "insert category: ";
    cin >> ktg;
    adrKategori p = searchKategori(L, ktg);
    if (p == NULL){
        cout << "Category not found! Please insert available categories or choose menu number 1 (add category)!"<< endl;
    } else {
        adrBuku b = p->firstBuku; // hapus semua buku

        while (b != NULL){
            adrBuku temp = b; //pindahin variabel yg mau dihapus ke temp
            b = b->next;
            temp = NULL; // hapus
        }

        // hapus kategori
        if (p->prev == NULL && p->next == NULL) { // kat cuma 1
            L.first = NULL;
            L.last = NULL;
        } else if (p->prev == NULL){ // ktg di awal dan > 1
            L.first = p->next;
            p->next->prev = NULL;
        } else if (p->next == NULL){ // ktg di akhir
            L.last = p->prev;
            p->prev->next = NULL;
        } else {
            p->prev->next = p->next; // ktg di tengah
            p->next->prev = p->prev;
        }
        p = NULL;
        cout << "Category deleted successfully!" << endl;
    }
};

adrKategori searchKategori(listKategori L, string kategori){
    adrKategori k = L.first;
    while (k != NULL){
        if (k->info.namaKat == kategori){
            return k;
        }
        k = k->next;
    }
    return NULL;
}

adrBuku searchBukuKode(listKategori L, string kode){
    adrKategori k = L.first;
    while (k != NULL){
        adrBuku p = k->firstBuku;
        while (p != NULL){
            if (p->info.kode == kode){
                return p;
            }
            p = p->next;
        }
        k = k->next;
    }
    return NULL;
}

adrBuku searchBukuJudul(listKategori L, string judul){
    adrKategori k = L.first;
    while (k != NULL){
        adrBuku p = k->firstBuku;
        while (p != NULL){
            if (p->info.judul == judul){
                return p;
            }
            p = p->next;
        }
        k = k->next;
    }
    return NULL;
}
adrBuku searchBukuPengarang(listKategori L, string pengarang){
    adrKategori k = L.first;
    while (k != NULL){
        adrBuku p = k->firstBuku;
        while (p != NULL){
            if (p->info.pengarang == pengarang){
                return p;
            }
            p = p->next;
        }
        k = k->next;
    }
    return NULL;
}
void searchBukuKeyword(listKategori L, string keyword){
    bool found = false;
    int i;
    adrKategori k = L.first;
    while (k != NULL){
        adrBuku p = k->firstBuku;
        while (p != NULL){
            for (i=0; i<maxKey; i++) {
                if (p->info.katakunci[i] == keyword){
                    displayDetailBuku(p);
                    found = true;
                }
            }
            p = p->next;
        }
        k = k->next;
    }
    if (!found) {
        cout << "Book not found\n";
    }
};

adrBuku searchBukuTahun(listKategori L, int tahun){
    adrKategori k = L.first;
    while (k != NULL){
        adrBuku p = k->firstBuku;
        while (p != NULL){
            if (p->info.tahun == tahun){
                return p;
            }
            p = p->next;
        }
        k = k->next;
    }
    return NULL;
};

void formAddCategory(listKategori &L){
    string namaKat;
    cout << "insert category name: ";
    cin >> namaKat;
    adrKategori p = searchKategori(L, namaKat);
    if (p != NULL){
        cout << "Category already exists! Please insert a new category name!\n";
    } else {
        adrKategori k = createElmKategori(namaKat);
        addKategori(L, k);
        cout << "Category added successfully!\n";
    }
};

void formAddBook(listKategori &L){
    string kode, jdl, pengarang, ktg;
    string katakunci, key[maxKey];
    int i, thn, hlm, n;
    cout << "insert category: ";
    cin >> ktg;
    adrKategori p = searchKategori(L, ktg);
    if (p == NULL){
        cout << "Category not found! Please insert available categories or choose menu number 1 (add category)!\n";
    } else {
        cout << "insert code: ";
        cin >> kode;
        adrBuku kodeBaru = searchBukuKode(L, kode);
        while (kodeBaru != NULL) {
            if (kodeBaru != NULL) {
                cout << "Code already exists! Please insert a different code!\n";
                cout << "insert code: ";
                cin >> kode;
                kodeBaru = searchBukuKode(L, kode);
            }
        }
        cout << "insert title: ";
        cin >> jdl;
        cout << "insert author: ";
        cin >> pengarang;
        cout << "insert year published: ";
        cin >> thn;
        cout << "insert total keywords: ";
        cin >> n;
        cout << "insert keywords: \n";

        for (i=1; i<=n; i++) {
            cout << "Keyword " << i << ": ";
            cin >> katakunci;
            key[i] = katakunci;
        }

        cout << "insert number of pages: ";
        cin >> hlm;

        adrBuku q = createElmBuku(kode, jdl, pengarang, thn, key, hlm);
        addBuku(p, q);
        cout << "Book added successfully!\n";
    }
};

void formSearchBook(listKategori L){
    int angka, thn;
    string jdl, pengarang, ktg, katakunci;

    cout << "Search book by: \n";
    cout << "1. Title\n";
    cout << "2. Author\n";
    cout << "3. Category\n";
    cout << "4. Keyword\n";
    cout << "5. Year Published\n";
    cout << "Choose 1/2/3/4/5: ";
    cin >> angka;

    if (angka == 1) {
        cout << "Insert title: ";
        cin >> jdl;
        cout << endl;
        adrBuku p = searchBukuJudul(L, jdl);
        if (p != nullptr) {
            displayDetailBuku(p);
        } else {
            cout << "Book not found\n";
        }
    } else if (angka == 2) {
        cout << "Insert author: ";
        cin >> pengarang;
        cout << endl;
        adrBuku p = searchBukuPengarang(L, pengarang);
        if (p != nullptr) {
            displayDetailBuku(p);
        } else {
            cout << "Category not found\n";
        }
    } else if (angka == 3) {
        cout << "Insert category: ";
        cin >> ktg;
        cout << endl;
        adrKategori k = searchKategori(L, ktg);
        if (k != nullptr) {
            adrBuku b = k->firstBuku;
            if (b == NULL) {
                cout << "No books in this category!\n";
            } else {
                while (b != NULL){
                    displayDetailBuku(b);
                    b = b->next;
                };
            };
        } else {
            cout << "Category not found\n";
        };
    } else if (angka == 4) {
        cout << "Insert keyword: ";
        cin >> katakunci;
        cout << endl;
        searchBukuKeyword(L, katakunci);
    } else if (angka == 5) {
        cout << "Insert year published: ";
        cin >> thn;
        cout << endl;
        adrBuku p = searchBukuTahun(L, thn);
        if (p != nullptr) {
            displayDetailBuku(p);
        } else {
            cout << "Book not found\n";
        }
    } else {
        cout << "Invalid choice! Please input the valid number ^___^\n" << endl;
    }
}


void displayDetailBuku(adrBuku p){
    int i;
    cout << "Code : " << p->info.kode << endl;
    cout << "Title : " << p->info.judul << endl;
    cout << "Author : " << p->info.pengarang << endl;
    cout << "Year Published : " << p->info.tahun << endl;
    cout << "keyword : ";
    for (i=0; i<maxKey; i++) {
        if (p->info.katakunci[i] != "") {
            cout << p->info.katakunci[i] << ", ";
        };
    };
    cout << endl;
    cout << "Pages : " << p->info.hlm << endl;
    cout << endl;
};

void displayList(listKategori L){
    int i;
    adrKategori k = L.first;

    while (k != NULL){
        cout << "Category: " << k->info.namaKat << endl;
        cout << endl;
        cout << "List Buku: " << endl;
        adrBuku p = k->firstBuku;
        while (p != NULL){
            cout << "Code : " << p->info.kode << endl;
            cout << "Title : " << p->info.judul << endl;
            cout << "Author : " << p->info.pengarang << endl;
            cout << "Year Published : " << p->info.tahun << endl;
            cout << "keyword : ";
            for (i=0; i<maxKey; i++) {
                if (p->info.katakunci[i] != "") {
                    cout << p->info.katakunci[i] << ", ";
                }
            }
            cout << endl;
            cout << "Pages : " << p->info.hlm << endl;
            p = p->next;
            cout << endl;
        }
        k = k->next;
    }
}


void formCountBooksByCategory(listKategori L){
    int jmlBuku = 0;
    string ktg;

    cout << "insert category: ";
    cin >> ktg;
    adrKategori p = searchKategori(L, ktg);
    if (p == NULL){
        cout << "Category not found! Please insert available categories or choose menu number 1 (add category)!\n";
    } else {
        adrBuku b = p->firstBuku;
        while (b != NULL) {
            jmlBuku ++;
            b = b->next;
        };
        cout << "Number of books in category " << ktg << ": " << jmlBuku << endl;
        cout << endl;
    };
};

void formShowBooksByPublicationYear(listKategori L){
    int minYear = 2026;
    int maxYear = 0;
    adrKategori k = L.first;

    while (k != NULL) {
        adrBuku b = k->firstBuku;
        while (b != NULL) {
            int t = b->info.tahun;

            if (t < minYear) {
                minYear = t;
            }
            if (t > maxYear) {
                maxYear = t;
            }
            b = b->next;
        }
        k = k->next;
    }

    cout << "Oldest book: " << endl;
    adrBuku lama = searchBukuTahun(L, minYear);
    displayDetailBuku(lama);

    cout << "Newest book: " << endl;
    adrBuku baru = searchBukuTahun(L, maxYear);
    displayDetailBuku(baru);
    cout << endl;

};

void formShowAvgPagesByCategory(listKategori L){
    int jmlBuku = 0;
    int totalHlm = 0;
    string ktg;
    cout << "insert category: ";
    cin >> ktg;
    adrKategori p = searchKategori(L, ktg);
    if (p == NULL){
        cout << "Category not found! Please insert available categories or choose menu number 1 (add category)!\n";
    } else {
        adrBuku b = p->firstBuku;
        while (b != NULL) {
            jmlBuku ++;
            totalHlm += b->info.hlm;
            b = b->next;
        };
        double mean = totalHlm;// double sm kayak float64 kalo di golang
        mean = mean / jmlBuku;
        cout << "Average number of pages for books in category " << ktg << ": " << mean << endl;
    }
};

void formUpdateList(listKategori &L){
    int angka;

    cout << "choose data to edit: \n";
    cout << "1. Book details\n";
    cout << "2. Category name\n";
    cin >> angka;
    if (angka == 1) {
        updateBook(L);
    } else if (angka == 2){
        updateCategory(L);
    } else {
        cout << "Invalid choice! Please input the valid number ^___^\n" << endl;
    }
};

void updateCategory(listKategori &L){
    string lama, baru;
    cout << "insert category to edit: ";
    cin >> lama;
    adrKategori p = searchKategori(L, lama);
    if (p == NULL){
        cout << "Category not found! Please insert available category or choose menu number 2 (add book)!\n";
    } else {
        cout << "insert new category name: ";
        cin >> baru;
        while (searchKategori(L, baru) != NULL) {
            cout << "Category already exists! Please insert a different category name!\n";
            cout << "insert new category name: ";
            cin >> baru;
        }
        p->info.namaKat = baru;
        cout << "Category updated successfully!" << endl;
    }
};

void updateBook(listKategori &L){
    string a;
    int angka;

    cout << "insert book code to edit: ";
    cin >> a;
    adrBuku p = searchBukuKode(L, a);
    if (p == NULL){
        cout << "Book not found! Please insert available code books or choose menu number 2 (add book)!\n";
    } else {
        cout << "1. Title\n";
        cout << "2. Author\n";
        cout << "3. Year Published\n";
        cout << "4. Code\n";
        cout << "5. Pages\n";
        cout << "Choose 1/2/3/4/5: ";
        cin >> angka;

        if (angka == 1) {
            cout << "Insert new title: ";
            cin >> a;
            while (searchBukuJudul(L, a) != NULL) {
                cout << "Title already exists! Please insert a different title!\n";
                cout << "insert new title: ";
                cin >> a;
            }
            p->info.judul = a;
            cout << "Title updated successfully!" << endl;
        } else if (angka == 2) {
            cout << "Insert new author: ";
            cin >> p->info.pengarang;
            cout << "Author updated successfully!" << endl;
        } else if (angka == 3) {
            cout << "Insert new year published: ";
            cin >> p->info.tahun;
            cout << "Year published updated successfully!" << endl;
        } else if (angka == 4) {
            cout << "Insert new code: ";
            cin >> a;
            while (searchBukuKode(L, a) != NULL) {
                cout << "Code already exists! Please insert a different code!\n";
                cout << "insert new code: ";
                cin >> a;
            }
            p->info.kode = a;
            cout << "Code updated successfully!" << endl;
        } else if (angka == 5) {
            cout << "Insert new number of pages: ";
            cin >> p->info.hlm;
            cout << "Pages updated successfully!" << endl;
        } else {
            cout << "Invalid choice! Please input the valid number ^___^" << endl;
        };
    };
};
