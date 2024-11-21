//ILHAMLII
//2311104068
//SE0703
//ASSESMENT
//===========================
//===========================

#include <iostream>
#include <string>

using namespace std;

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

DoubleLinkedList newList() {
    DoubleLinkedList list;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

Node* newElement(Mahasiswa data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

bool isEmpty(DoubleLinkedList list) {
    return list.head == NULL;
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
    while (current != NULL) {
        cout << "Nama: " << current->data.nama; 
        cout << ", NIM: " << current->data.NIM;
        cout << ", Kelas: " << current->data.kelas;
        cout << ", Nilai Asesmen: " << current->data.nilaiAsesmen; 
        cout << ", Nilai Praktikum: " << current->data.nilaiPraktikum << endl;
        current = current->next;
    }
}

Mahasiswa findMaxAsesmen(DoubleLinkedList list) {
    Node* current = list.head;
    Mahasiswa maxData = current->data;
    while (current != NULL) {
        if (current->data.nilaiAsesmen > maxData.nilaiAsesmen) {
            maxData = current->data;
        }
        current = current->next;
    }
    return maxData;
}

void removeDuplicate(DoubleLinkedList &list) {
    Node* current = list.head;
    while (current != NULL) {
        Node* checker = current->next;
        while (checker != NULL) {
            if (checker->data.NIM == current->data.NIM) {
             
                if (checker->next != NULL) {
                    checker->next->prev = checker->prev;
                }
                if (checker->prev != NULL) {
                    checker->prev->next = checker->next;
                }
                if (checker == list.tail) {
                    list.tail = checker->prev; 
                }
                Node* duplicate = checker;
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

        Node* newNode = newElement(mhs);
        insertLast(list, newNode); 
    }

    cout << "\n========Data Mahasiswa: ==========\n";
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
