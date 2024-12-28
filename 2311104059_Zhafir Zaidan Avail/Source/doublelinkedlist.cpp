// Nama : Zhafir Zaidan Avail
// NIM : 2311104059
// Kelas : S1-SE-07-02

#include "doublelinkedlist.h"
#include <iostream>
#include <vector>
// Buat node baru
Node* newElement(Mahasiswa data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Buat list baru
List newList() {
    List list;
    list.head = nullptr;
    list.tail = nullptr;
    return list;
}

// Cek kosong
bool isEmpty(List list) {
    return list.head == nullptr;
}

// Insert data di awal
void insertFirst(List &list, Node* newNode) {
    if (isEmpty(list)) {
        list.head = newNode;
        list.tail = newNode;
    } else {
        newNode->next = list.head;
        list.head->prev = newNode;
        list.head = newNode;
    }
}

// Insert data setelah node tertentu
void insertAfter(List &list, Mahasiswa data, Node* prevNode) {
    if (prevNode == nullptr) return;
    Node* newNode = newElement(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    prevNode->next = newNode;
    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    } else {
        list.tail = newNode;
    }
}

// Insert data di akhir
void insertLast(List &list, Node* newNode) {
    if (isEmpty(list)) {
        list.head = newNode;
        list.tail = newNode;
    } else {
        list.tail->next = newNode;
        newNode->prev = list.tail;
        list.tail = newNode;
    }
}

// Hapus node pertama
void deleteFirst(List &list, Node* &deletedNode) {
    if (isEmpty(list)) return;
    deletedNode = list.head;
    list.head = list.head->next;
    if (list.head != nullptr) {
        list.head->prev = nullptr;
    } else {
        list.tail = nullptr;
    }
    delete deletedNode;
}

// Hapus node terakhir
void deleteLast(List &list, Node* &deletedNode) {
    if (isEmpty(list)) return;
    deletedNode = list.tail;
    list.tail = list.tail->prev;
    if (list.tail != nullptr) {
        list.tail->next = nullptr;
    } else {
        list.head = nullptr;
    }
    delete deletedNode;
}

// Hitung panjang list
int length(List list) {
    int count = 0;
    Node* current = list.head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Cari Node Tertentu
Node* findElement(List list, std::string NIM) {
    Node* current = list.head;
    while (current != nullptr) {
        if (current->data.NIM == NIM) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Cetak list
void printList(List list) {
    Node* current = list.head;
    while (current != nullptr) {
        std::cout << "Nama: " << current->data.nama << ", NIM: " << current->data.NIM
                  << ", Kelas: " << current->data.kelas << ", Nilai Asesmen: " << current->data.nilaiAsesmen
                  << ", Nilai Praktikum: " << current->data.nilaiPraktikum << std::endl;
        current = current->next;
    }
}

// Masukkan data
void addNData(List &list, int N) {
    for (int i = 0; i < N; i++) {
        Mahasiswa mhs;
        std::cout << "\nMahasiswa ke-" << (i + 1) << ":\n";

        std::cout << "Masukkan Nama: ";
        std::cin.ignore(); // Mengabaikan karakter newline sisa input sebelumnya
        std::getline(std::cin, mhs.nama);

        std::cout << "Masukkan NIM: ";
        std::getline(std::cin, mhs.NIM);

        std::cout << "Masukkan Kelas: ";
        std::getline(std::cin, mhs.kelas);

        std::cout << "Masukkan Nilai Asesmen: ";
        std::cin >> mhs.nilaiAsesmen;

        std::cout << "Masukkan Nilai Praktikum: ";
        std::cin >> mhs.nilaiPraktikum;

        Node* newNode = newElement(mhs);
        insertLast(list, newNode);
    }
}


// Cari Nilai Tertinggi
Mahasiswa findHighestAsesmen(List list) {
    Node* current = list.head;
    Mahasiswa tertinggi;
    if (current != nullptr) {
        tertinggi = current->data;
        current = current->next;
    }
    while (current != nullptr) {
        if (current->data.nilaiAsesmen > tertinggi.nilaiAsesmen) {
            tertinggi = current->data;
        }
        current = current->next;
    }
    return tertinggi;
}

// Delete NIM duplikat
void removeDuplicates(List &list) {
    Node* current = list.head;
    while (current != nullptr) {
        Node* runner = current->next;
        while (runner != nullptr) {
            if (runner->data.NIM == current->data.NIM) {
                Node* duplicate = runner;
                runner->prev->next = runner->next;
                if (runner->next != nullptr) {
                    runner->next->prev = runner->prev;
                } else {
                    list.tail = runner->prev;
                }
                runner = runner->next;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}
