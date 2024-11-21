//Dimastian Aji WIbowo
//2311104058
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <string>
using namespace std;

struct Mahasiswa{
    string nama;
    string nim;
    string kelas;
    int nilaiAsesmen;
    int nilaiPraktikum;
    Mahasiswa* next;
    Mahasiswa* prev;
};
Mahasiswa* newElement(string nama, string nim, string kelas, int nilaiAsesmen, int nilaiPraktikum);

Mahasiswa* createNewList();

bool isEmpty(Mahasiswa* list);

void insertLast(Mahasiswa*& list, Mahasiswa* p);

void deleteFirst(Mahasiswa*& list, Mahasiswa*& p);

void deleteLast(Mahasiswa*& list, Mahasiswa*& p);

int length(Mahasiswa* list);

Mahasiswa* findElement(Mahasiswa* list, string nim);

void printList(Mahasiswa* list);

void tambahData(Mahasiswa*& list, int N);

void tampilkanNilaiTertinggi(Mahasiswa* list);

void hapusDuplikat(Mahasiswa*& list);

#endif
