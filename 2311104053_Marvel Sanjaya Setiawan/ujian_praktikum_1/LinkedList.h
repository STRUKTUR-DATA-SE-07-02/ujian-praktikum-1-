#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string kelas;
    float nilaiAsesmen;
    float nilaiPraktikum;
    Mahasiswa* next;
};

class LinkedList {
public:
    LinkedList();
    void createNewList();
    void insertFirst(Mahasiswa* newMahasiswa);
    Mahasiswa* newElement(const string& nama, const string& nim, const string& kelas, float nilaiAsesmen, float nilaiPraktikum);
    bool isEmpty();
    void deleteFirst();
    int length();
    Mahasiswa* findElement(const string& nim);
    void printList();
    Mahasiswa* findHighestAsesmen();
    void removeDuplicates();
private:
    Mahasiswa* head;
};

LinkedList::LinkedList() {
    head = nullptr;
}

#endif // LINKEDLIST_H_INCLUDED
