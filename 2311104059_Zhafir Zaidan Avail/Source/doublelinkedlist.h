//Zhafir Zaidan Avail
//2311104059
// Kelas : S1-SE-07-02

#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include <vector>
#include <string>
struct Mahasiswa {
    std::string nama;
    std::string NIM;
    std::string kelas;
    float nilaiAsesmen;
    float nilaiPraktikum;
};
struct Node {
    Mahasiswa data;
    Node* next;
    Node* prev;
};
struct List {
    Node* head;
    Node* tail;
};
Node* newElement(Mahasiswa data);
List newList();
bool isEmpty(List list);
void insertFirst(List &list, Node* newNode);
void insertAfter(List &list, Mahasiswa data, Node* prevNode);
void insertLast(List &list, Node* newNode);
void deleteFirst(List &list, Node* &deletedNode);
void deleteLast(List &list, Node* &deletedNode);
int length(List list);
Node* findElement(List list, std::string NIM);
void printList(List list);
void addNData(List &list, int N);
Mahasiswa findHighestAsesmen(List list);
void removeDuplicates(List &list);

#endif
