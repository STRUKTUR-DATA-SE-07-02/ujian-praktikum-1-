#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa
{
    string nama;
    int NIM;
    string kelas;
    float nilaiUjian;
    float nilaiPraktikum;
};

typedef Mahasiswa infotype;
typedef struct Elemen *address;

struct Elemen
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

void createNewList(List &L);
bool isEmpty(List L);
address newElement(infotype data);
void printList(List L);
void insertLast(List &L, address P);
void printHighestUjian(List L);
void removeDuplicateNIM(List &L);

#endif
