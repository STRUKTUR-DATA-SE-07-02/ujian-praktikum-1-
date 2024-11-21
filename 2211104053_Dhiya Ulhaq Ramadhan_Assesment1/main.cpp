// Soal no 1
// Nama : Dhiya Ulhaq Ramadhan
// Kelas : SE-07-02
// NIM : 2211104053

// Soal no 2 : Single List

#include <iostream>
#include <string>
using namespace std;

// Soal no 3 dan 4
struct infotype {
    string nama;
    string nim;
    string kelas;
    float nilaiAsesmen;
    float nilaiPraktikum;
};

struct Node {
    infotype data;
    Node* next;
};

// Soal no 4 a,b, dan c
Node* newElement(infotype data) {
    Node* p = new Node;
    p->data = data;
    p->next = nullptr;
    return p;
}

Node* createNewList() {
    return nullptr;
}

void insertFirst(Node*& first, Node* p) {
    p->next = first;
    first = p;
}

void insertLast(Node*& first, Node* p) {
    if (first == nullptr) {
        first = p;
    } else {
        Node* temp = first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void printList(Node* first) {
    Node* temp = first;
    while (temp != nullptr) {
        cout << "Nama: " << temp->data.nama << ", NIM: " << temp->data.nim
             << ", Kelas: " << temp->data.kelas
             << ", Nilai Asesmen: " << temp->data.nilaiAsesmen
             << ", Nilai Praktikum: " << temp->data.nilaiPraktikum << endl;
        temp = temp->next;
    }
}

//Soal 5.b
infotype findMaxAsesmen(Node* first) {
    Node* temp = first;
    infotype maxData;
    if (temp == nullptr) {
        throw runtime_error("List kosong");
    }
    maxData = temp->data;
    while (temp != nullptr) {
        if (temp->data.nilaiAsesmen > maxData.nilaiAsesmen) {
            maxData = temp->data;
        }
        temp = temp->next;
    }
    return maxData;
}

//Soal 5.c
void removeDuplicates(Node*& first) {
    Node* current = first;
    while (current != nullptr) {
        Node* temp = current;
        while (temp->next != nullptr) {
            if (temp->next->data.nim == current->data.nim) {
                Node* duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

int main() {
    Node* first = createNewList();

    // Soal no 5.a
    int n;
    cout << "Masukkan jumlah data Mahasiswa: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        infotype data;
        cout << "Nama: ";
        cin >> data.nama;
        cout << "NIM: ";
        cin >> data.nim;
        cout << "Kelas: ";
        cin >> data.kelas;
        cout << "Nilai Asesmen: ";
        cin >> data.nilaiAsesmen;
        cout << "Nilai Praktikum: ";
        cin >> data.nilaiPraktikum;

        Node* p = newElement(data);
        if (stoi(data.nim) % 2 == 0) {
            insertLast(first, p);
        } else {
            insertFirst(first, p);
        }
    }

    cout << "\nDaftar Mahasiswa:\n";
    printList(first);

    // Soal 5.b
    try {
        infotype maxData = findMaxAsesmen(first);
        cout << "\nMahasiswa dengan nilai asesmen tertinggi:\n";
        cout << "Nama: " << maxData.nama << ", NIM: " << maxData.nim
             << ", Nilai Asesmen: " << maxData.nilaiAsesmen << endl;
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }

    // Soal 5.c
    removeDuplicates(first);
    cout << "\nDaftar Mahasiswa setelah menghapus duplikat:\n";
    printList(first);

    return 0;
}
