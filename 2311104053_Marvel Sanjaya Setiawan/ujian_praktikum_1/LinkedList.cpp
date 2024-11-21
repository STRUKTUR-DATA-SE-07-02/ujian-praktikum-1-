#include "LinkedList.h"

void LinkedList::createNewList() {
    head = nullptr;
}

void LinkedList::insertFirst(Mahasiswa* newMahasiswa) {
    newMahasiswa->next = head;
    head = newMahasiswa;
}

Mahasiswa* LinkedList::newElement(const string& nama, const string& nim, const string& kelas, float nilaiAsesmen, float nilaiPraktikum) {
    Mahasiswa* newMahasiswa = new Mahasiswa;
    newMahasiswa->nama = nama;
    newMahasiswa->nim = nim;
    newMahasiswa->kelas = kelas;
    newMahasiswa->nilaiAsesmen = nilaiAsesmen;
    newMahasiswa->nilaiPraktikum = nilaiPraktikum;
    newMahasiswa->next = nullptr;
    return newMahasiswa;
}

bool LinkedList::isEmpty() {
    return head == nullptr;
}

void LinkedList::deleteFirst() {
    if (isEmpty()) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    Mahasiswa* temp = head;
    head = head->next;
    delete temp;
}

int LinkedList::length() {
    int count = 0;
    Mahasiswa* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

Mahasiswa* LinkedList::findElement(const string& nim) {
    Mahasiswa* temp = head;
    while (temp != nullptr) {
        if (temp->nim == nim) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void LinkedList::printList() {
    Mahasiswa* temp = head;
    while (temp != nullptr) {
        cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << ", Kelas: " << temp->kelas
             << ", Nilai Asesmen: " << temp->nilaiAsesmen << ", Nilai Praktikum: " << temp->nilaiPraktikum << endl;
        temp = temp->next;
    }
}

Mahasiswa* LinkedList::findHighestAsesmen() {
    if (head == nullptr) return nullptr;
    Mahasiswa* temp = head;
    Mahasiswa* highest = head;
    while (temp != nullptr) {
        if (temp->nilaiAsesmen > highest->nilaiAsesmen) {
            highest = temp;
        }
        temp = temp->next;
    }
    return highest;
}

void LinkedList::removeDuplicates() {
    Mahasiswa* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        Mahasiswa* runner = temp;
        while (runner->next != nullptr) {
            if (temp->nim == runner->next->nim) {
                Mahasiswa* duplicate = runner->next;
                runner->next = runner->next->next;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }
        temp = temp->next;
    }
}
