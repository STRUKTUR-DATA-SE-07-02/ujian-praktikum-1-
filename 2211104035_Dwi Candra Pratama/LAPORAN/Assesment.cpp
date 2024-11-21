#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string kelas;
    float nilaiAsesmen;
    float nilaiPraktikum;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

struct List {
    Node* first;
};

// Function untuk membuat elemen baru
Node* newElement(Mahasiswa m) {
    Node* newNode = new Node;
    newNode->data = m;
    newNode->next = nullptr;
    return newNode;
}

// Function untuk membuat list kosong
List newList() {
    List l;
    l.first = nullptr;
    return l;
}

// Function untuk mengecek apakah list kosong
bool isEmpty(List l) {
    return l.first == nullptr;
}

// Procedure untuk menambahkan elemen di awal
void insertFirst(List& l, Node* p) {
    p->next = l.first;
    l.first = p;
}

// Procedure untuk menambahkan elemen di akhir
void insertLast(List& l, Node* p) {
    if (isEmpty(l)) {
        l.first = p;
    } else {
        Node* temp = l.first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

// Procedure untuk menampilkan isi list
void printList(List l) {
    Node* temp = l.first;
    while (temp != nullptr) {
        cout << "Nama: " << temp->data.nama
             << ", NIM: " << temp->data.nim
             << ", Kelas: " << temp->data.kelas
             << ", Nilai Asesmen: " << temp->data.nilaiAsesmen
             << ", Nilai Praktikum: " << temp->data.nilaiPraktikum << endl;
        temp = temp->next;
    }
}

// Procedure untuk menginputkan jumlah mahasiswa
void addMahasiswa(List& l, int N) {
    for (int i = 0; i < N; ++i) {
        Mahasiswa m;
        cout << "Masukkan Nama: "; cin >> m.nama;
        cout << "Masukkan NIM: "; cin >> m.nim;
        cout << "Masukkan Kelas: "; cin >> m.kelas;
        cout << "Masukkan Nilai Asesmen: "; cin >> m.nilaiAsesmen;
        cout << "Masukkan Nilai Praktikum: "; cin >> m.nilaiPraktikum;

        Node* newNode = newElement(m);
        if (stoi(m.nim) % 2 == 0) {
            insertLast(l, newNode);  
        } else {
            insertFirst(l, newNode);  
        }
    }
}

// Mencari mahasiswa dengan nilai asesmen tertinggi
void findHighestAsesmen(List l) {
    if (isEmpty(l)) {
        cout << "List kosong!" << endl;
        return;
    }

    Node* temp = l.first;
    Node* highest = temp;

    while (temp != nullptr) {
        if (temp->data.nilaiAsesmen > highest->data.nilaiAsesmen) {
            highest = temp;
        }
        temp = temp->next;
    }

    cout << "Mahasiswa dengan nilai asesmen tertinggi:" << endl;
    cout << "Nama: " << highest->data.nama
         << ", NIM: " << highest->data.nim
         << ", Nilai Asesmen: " << highest->data.nilaiAsesmen << endl;
}

// menghapus NIM yang sama
void deleteDuplicates(List& l) {
    Node *current = l.first, *prev = nullptr;

    while (current != nullptr) {
        Node* runner = current->next;
        prev = current;

        while (runner != nullptr) {
            if (runner->data.nim == current->data.nim) {
                Node* duplicate = runner;
                prev->next = runner->next;
                delete duplicate;
                runner = prev->next;
            } else {
                prev = runner;
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

// Program untuk menjalankan
int main() {
    List l = newList();
    int N;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> N;

    addMahasiswa(l, N);  // Menggunakan primitif untuk menambah data
    cout << "\nData Mahasiswa:" << endl;
    printList(l);  // Menggunakan `printList`

    cout << "\nMencari mahasiswa dengan nilai asesmen tertinggi:" << endl;
    findHighestAsesmen(l);  // Menggunakan primitif

    cout << "\nMenghapus data dengan NIM duplikat:" << endl;
    deleteDuplicates(l);  // Menggunakan primitif
    printList(l);  // Menggunakan `printList`

    return 0;
}
