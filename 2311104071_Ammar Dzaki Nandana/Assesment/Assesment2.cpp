// Nama: AMMAR DZAKI NANDANA
// Kelas: SE 07 02
// NIM: 2311104071
// Assesment Struktur Data (singel linked list)

/*a. Buatlah subprogram untuk menambahkan sebanyak N data baru kedalam list. List
mungkin kosong. Catatan : Mekanisme Insert First untuk NIM ganjil. Insert last
untuk NIM genap. */

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    long long NIM; 
    string kelas;
    double nilaiAssesment;
    double nilaiTugas;
};

struct Node {
    Mahasiswa info;
    Node* next;
};

using Address = Node*;

struct List {
    Address first;
};

List createNewList() {
    List L;
    L.first = nullptr;
    return L;
}

Address newElement(Mahasiswa data) {
    Address p = new Node;
    p->info = data;
    p->next = nullptr;
    return p;
}

void insertFirst(List &L, Address p) {
    if (L.first == nullptr) {
        L.first = p;
    } else {
        p->next = L.first;
        L.first = p;
    }
}

void tambahDataN(List &L, Mahasiswa data[], int N) {
    for (int i = 0; i < N; i++) {
        Address p = newElement(data[i]);
        if (data[i].NIM % 2 == 0) {
            insertFirst(L, p);
        }
    }
}

// b. menampilkan data mahasiswa yang memiliki nilai asesmen paling tinggi.

void nilaiTertinggi(List L) {
    if (L.first == nullptr) {
        cout << "List Kosong." << endl;
        return;
    }

    Address p = L.first;
    Address max = p;
    while (p != nullptr) {
        if (p->info.nilaiAssesment > max->info.nilaiAssesment) {
            max = p;
        }
        p = p->next;
    }

    cout << "Mahasiswa Dengan Nilai Assesment Tertinggi: " << endl;
    cout << "Nama: " << max->info.nama 
         << ", NIM: " << max->info.NIM 
         << ", Nilai Assesment: " << max->info.nilaiAssesment << endl;
}

/* c. Buatlah subprogram untuk menghapus data mahasiswa yang duplikat (Misal hapus
data mahasiswa jika NIMnya duplikat*/

void menghapusDuplikat(List &L) {
    Address p = L.first;
    while (p != nullptr && p->next != nullptr) {
        Address q = p;
        while (q->next != nullptr) {
            if (q->next->info.NIM == p->info.NIM) {
                Address temp = q->next;
                q->next = temp->next;
                delete temp;
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }
}

void printList(List L) {
    Address p = L.first;
    while (p != nullptr) {
        cout << "Nama: " << p->info.nama 
             << ", NIM: " << p->info.NIM 
             << ", Kelas: " << p->info.kelas 
             << ", Nilai Assesment: " << p->info.nilaiAssesment 
             << ", Nilai Tugas: " << p->info.nilaiTugas << endl;
        p = p->next;
    }
}

// Main program Nilai Mahasiswa

int main() {
    List L = createNewList();

    Mahasiswa data[] = {
        {"Ammar", 2311104088, "SE-07-02", 90.5, 85.0},
        {"Ammar", 2311104088, "SE-07-02", 78.0, 82.0},
        {"Nandana", 2311104077, "SE-07-02", 88.0, 79.0}, 
        {"Dzaki", 2311104066, "SE-07-02", 89.0, 69.0}, 
    };

    tambahDataN(L, data, 3);

    cout << "Isi List:" << endl;
    printList(L);

    cout << "\nMahasiswa Dengan Nilai Assesment Tertinggi:" << endl;
    nilaiTertinggi(L);

    menghapusDuplikat(L);

    cout << "\nIsi List Setelah Menghapus Duplikat:" << endl;
    printList(L);

    return 0;
}
