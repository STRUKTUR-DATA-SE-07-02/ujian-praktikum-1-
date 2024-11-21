/*
Nama: Arzario Irsyad Al Fatih
NIM: 2211104032
Kelas: SE 07 02
*/
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
using namespace std;


struct Mahasiswa {
    string nama;
    int NIM;
    string kelas;
    float nilaiAsesmen;
    float nilaiPraktikum;
};

typedef Mahasiswa infotype;
typedef struct Elemen* address;

struct Elemen {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

// Deklarasi Fungsi dan Prosedur
void createNewList(List &L);
bool isEmpty(List L);
address newElement(infotype data);
void printList(List L);
void insertLast(List &L, address P);
void removeDuplicateNIM(List &L);
void printHighestAsesmen(List L);

#endif
