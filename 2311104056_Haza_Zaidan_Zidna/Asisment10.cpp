#include <iostream>
#include <string>
#include <set>

using namespace std;

// Struktur data Mahasiswa
struct Mahasiswa {
    string nama;
    string NIM;
    string kelas;
    int nilaiAsesmen;
    int nilaiPraktikum;
};

// Struktur Node untuk Double Linked List
struct Node {
    Mahasiswa data;
    Node* next;
    Node* prev;
};

// Struktur List
struct List {
    Node* first;
    Node* last;
};

// Function untuk membuat elemen baru
Node* newElement(Mahasiswa data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Function untuk membuat list baru
List createNewList() {
    List list;
    list.first = nullptr;
    list.last = nullptr;
    return list;
}

// Procedure untuk menambahkan elemen di awal list
void insertFirst(List &list, Node* p) {
    if (list.first == nullptr) {
        list.first = list.last = p;
    } else {
        p->next = list.first;
        list.first->prev = p;
        list.first = p;
    }
}

// Procedure untuk menambahkan elemen di akhir list
void insertLast(List &list, Node* p) {
    if (list.last == nullptr) {
        list.first = list.last = p;
    } else {
        p->prev = list.last;
        list.last->next = p;
        list.last = p;
    }
}

// Procedure untuk menambahkan data mahasiswa
void addData(List &list, Mahasiswa data) {
    Node* p = newElement(data);
    if (stoi(data.NIM) % 2 == 0) { // NIM genap
        insertLast(list, p);
    } else { // NIM ganjil
        insertFirst(list, p);
    }
}

// Procedure untuk mencetak isi list
void printList(List list) {
    if (list.first == nullptr) {
        cout << "List kosong." << endl;
        return;
    }
    Node* current = list.first;
    while (current != nullptr) {
        cout << "Nama: " << current->data.nama 
             << ", NIM: " << current->data.NIM 
             << ", Kelas: " << current->data.kelas 
             << ", Nilai Asesmen: " << current->data.nilaiAsesmen 
             << ", Nilai Praktikum: " << current->data.nilaiPraktikum << endl;
        current = current->next;
    }
}

// Function untuk mencari mahasiswa dengan nilai asesmen tertinggi
void findMaxAsesmen(List list) {
    Node* current = list.first;
    Node* maxNode = nullptr;
    int maxValue = -1;

    while (current != nullptr) {
        if (current->data.nilaiAsesmen > maxValue) {
            maxValue = current->data.nilaiAsesmen;
            maxNode = current;
        }
        current = current->next;
    }

    if (maxNode != nullptr) {
        cout << "Mahasiswa dengan nilai asesmen tertinggi:" << endl;
        cout << "Nama: " << maxNode->data.nama 
             << ", NIM: " << maxNode->data.NIM 
             << ", Nilai: " << maxNode->data.nilaiAsesmen << endl;
    } else {
        cout << "List kosong, tidak ada data." << endl;
    }
}

// Procedure untuk menghapus data duplikat berdasarkan NIM
void removeDuplicates(List &list) {
    Node* current = list.first;

    while (current != nullptr) {
        Node* check = current->next;
        while (check != nullptr) {
            if (current->data.NIM == check->data.NIM) {
                Node* temp = check;
                check = check->next;

                // Update pointer untuk node sebelum dan sesudah
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;

                // Perbarui pointer first/last jika elemen dihapus
                if (temp == list.first) list.first = temp->next;
                if (temp == list.last) list.last = temp->prev;

                delete temp;
            } else {
                check = check->next;
            }
        }
        current = current->next;
    }
}

// Main Program
int main() {
    List list = createNewList();
    int N;

    // Tambahkan data
    cout << "Masukkan jumlah data mahasiswa yang akan ditambahkan: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        Mahasiswa m;
        cout << "Masukkan data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> m.nama;
        cout << "NIM: ";
        cin >> m.NIM;
        cout << "Kelas: ";
        cin >> m.kelas;
        cout << "Nilai Asesmen: ";
        cin >> m.nilaiAsesmen;
        cout << "Nilai Praktikum: ";
        cin >> m.nilaiPraktikum;
        addData(list, m);
    }

    // Cetak data
    cout << "\nData Mahasiswa:" << endl;
    printList(list);

    // Cari nilai asesmen tertinggi
    cout << "\nMencari nilai asesmen tertinggi..." << endl;
    findMaxAsesmen(list);

    // Hapus duplikat
    cout << "\nMenghapus data duplikat..." << endl;
    removeDuplicates(list);

    // Cetak data setelah penghapusan duplikat
    cout << "\nData Mahasiswa Setelah Penghapusan Duplikat:" << endl;
    printList(list);

    return 0;
}