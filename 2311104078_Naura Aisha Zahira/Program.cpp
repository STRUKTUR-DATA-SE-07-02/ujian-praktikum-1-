#include <iostream>
#include <string>

using namespace std;

// Nama : Naura Aisha Zahira 
// NIM  : 2311104078
// Kelas: S1SE-07-02

struct Mahasiswa {
    string nama;
    int NIM;
    string kelas;
    int nilaiAsesmen;
    int nilaiPraktikum;
};

struct Node {
    Mahasiswa data;
    Node* next;
    Node* prev;
};

struct DoubleLinkedList {
    Node* head;
    Node* tail;
};

DoubleLinkedList newList(){
    DoubleLinkedList list;
    list.head = nullptr;
    list.tail = nullptr;
    return list;
}

Node* newElemen(Mahasiswa data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

bool isEmpty(DoubleLinkedList list) {
    return list.head == nullptr;
}

void insertLast(DoubleLinkedList &list, Node* newNode) {
    if (isEmpty(list)) {
        list.head = list.tail = newNode;
    } else {
        newNode->prev = list.tail;
        list.tail->next = newNode;
        list.tail = newNode;
    }
}

void printList(DoubleLinkedList list) {
    Node* current = list.head;
    while (current != nullptr) {
        cout << "Nama: " << current->data.nama 
             << ", NIM: " << current->data.NIM 
             << ", Kelas: " << current->data.kelas 
             << ", Nilai Asesmen: " << current->data.nilaiAsesmen 
             << ", Nilai Praktikum: " << current->data.nilaiPraktikum << endl;
        current = current->next;
    }
}

Mahasiswa findMaxAsesmen(DoubleLinkedList list) {
    Node* current = list.head;
    Mahasiswa maxData = current->data;
    while (current != nullptr) {
        if (current->data.nilaiAsesmen > maxData.nilaiAsesmen) {
            maxData = current->data;
        }
        current = current->next;
    }
    return maxData;
}

void removeDuplicate(DoubleLinkedList &list) {
    Node* current = list.head;
    while (current != nullptr) {
        Node* checker = current->next;
        while (checker != nullptr) {
            if (checker->data.NIM == current->data.NIM) {
                Node* duplicate = checker;
                if (checker->next != nullptr) {
                    checker->next->prev = checker->prev;
                }
                if (checker->prev != nullptr) {
                    checker->prev->next = checker->next;
                }
                if (checker == list.tail) {
                    list.tail = checker->prev;
                }
                checker = checker->next;
                delete duplicate;
            } else {
                checker = checker->next;
            }
        }
        current = current->next;
    }
}

int main() {
    
    cout << "Nama  : Naura Aisha Zahira" << endl;
    cout << "NIM   : 2311104078" << endl;
    cout << "Kelas : S1SE-07-02" << endl;
    

    DoubleLinkedList list = newList();
    
    int N;
    cout << "\nMasukkan jumlah mahasiswa: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        Mahasiswa mhs;
        cout << "Nama: "; cin >> mhs.nama;
        cout << "NIM: "; cin >> mhs.NIM;
        cout << "Kelas: "; cin >> mhs.kelas;
        cout << "Nilai Asesmen: "; cin >> mhs.nilaiAsesmen;
        cout << "Nilai Praktikum: "; cin >> mhs.nilaiPraktikum;

        Node* newNode = newElemen(mhs);
        insertLast(list, newNode); // Menggunakan Insert Last
    }

    cout << "\nData Mahasiswa:\n";
    printList(list);

    Mahasiswa maxAsesmen = findMaxAsesmen(list);
    cout << "\nMahasiswa dengan nilai asesmen tertinggi:\n";
    cout << "Nama: " << maxAsesmen.nama << ", NIM: " << maxAsesmen.NIM 
         << ", Nilai Asesmen: " << maxAsesmen.nilaiAsesmen << endl;

    removeDuplicate(list);
    cout << "\nData Mahasiswa setelah menghapus duplikat:\n";
    printList(list);

    return 0;
}



