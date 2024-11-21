// NAMA     : MUHAMMAD RALFI
// NIM      : 2211104054 - Double linked list
// Kelas    : SE-07-2

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    string kelas;
    float nilaiAsesmen;
    float nilaiPraktikum;
    Mahasiswa *next;
    Mahasiswa *prev;
};

struct List {
    Mahasiswa *first;
    Mahasiswa *last;
};

Mahasiswa* newElement(string nama, int nim, string kelas, float nilaiAsesmen, float nilaiPraktikum) {
    Mahasiswa* p = new Mahasiswa;
    p->nama = nama;
    p->nim = nim;
    p->kelas = kelas;
    p->nilaiAsesmen = nilaiAsesmen;
    p->nilaiPraktikum = nilaiPraktikum;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

List createNewList() {
    List l;
    l.first = nullptr;
    l.last = nullptr;
    return l;
}

void insertFirst(List &l, Mahasiswa *p) {
    if (l.first == nullptr) {
        l.first = l.last = p;
    } else {
        p->next = l.first;
        l.first->prev = p;
        l.first = p;
    }
}

void insertLast(List &l, Mahasiswa *p) {
    if (l.last == nullptr) {
        l.first = l.last = p;
    } else {
        p->prev = l.last;
        l.last->next = p;
        l.last = p;
    }
}

void printList(const List &l) {
    Mahasiswa *p = l.first;
    while (p != nullptr) {
        cout << "Nama: " << p->nama << ", NIM: " << p->nim << ", Kelas: " << p->kelas
             << ", Nilai Asesmen: " << p->nilaiAsesmen << ", Nilai Praktikum: " << p->nilaiPraktikum << endl;
        p = p->next;
    }
}

Mahasiswa* findHighestAssessment(const List &l) {
    Mahasiswa *p = l.first;
    Mahasiswa *highest = p;
    while (p != nullptr) {
        if (p->nilaiAsesmen > highest->nilaiAsesmen) {
            highest = p;
        }
        p = p->next;
    }
    return highest;
}

void deleteDuplicate(List &l) {
    Mahasiswa *p = l.first;
    while (p != nullptr) {
        Mahasiswa *q = p->next;
        while (q != nullptr) {
            if (q->nim == p->nim) {
                Mahasiswa *toDelete = q;
                if (q->prev) q->prev->next = q->next;
                if (q->next) q->next->prev = q->prev;
                if (q == l.last) l.last = q->prev;
                q = q->next;
                delete toDelete;
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }
}

int main() {
    List l = createNewList();

    int N;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        string nama, kelas;
        int nim;
        float nilaiAsesmen, nilaiPraktikum;

        cout << "Masukkan Nama, NIM, Kelas, Nilai Asesmen, Nilai Praktikum: ";
        cin >> nama >> nim >> kelas >> nilaiAsesmen >> nilaiPraktikum;

        Mahasiswa *p = newElement(nama, nim, kelas, nilaiAsesmen, nilaiPraktikum);

        if (nim % 2 == 0) {
            insertLast(l, p);
        } else {
            insertFirst(l, p);
        }
    }

    cout << "\nData Mahasiswa:\n";
    printList(l);

    Mahasiswa *highest = findHighestAssessment(l);
    cout << "\nMahasiswa dengan nilai asesmen tertinggi:\n";
    cout << "Nama: " << highest->nama << ", NIM: " << highest->nim << ", Nilai Asesmen: " << highest->nilaiAsesmen << endl;

    deleteDuplicate(l);

    cout << "\nData setelah menghapus duplikat:\n";
    printList(l);

    return 0;
}
