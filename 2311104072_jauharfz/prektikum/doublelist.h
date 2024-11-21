#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    string kelas;
    float nilaiAsesmen;
    float nilaiPraktikum;
};

typedef Mahasiswa infotype;
typedef struct elmList *address;

struct elmList
{
    infotype info;
    address next;
    address prev;
};

struct List
{
    address first;
    address last;
};

address newElement(infotype data);
List createNewList();
bool isEmpty(List L);
void insertLast(List &L, address P);
void insertAfter(List &L, infotype x, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
int length(List L);
address findElement(List L, infotype x);
void printList(List L);

void tambahNData(List &L, int N);
void tampilNilaiAsesmenTertinggi(List L);
void hapusDuplikatNIM(List &L);

#endif
