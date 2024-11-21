#include <iostream>
#include <string>
using namespace std;

// Struktur Mahasiswa
struct Mahasiswa {
    string Nama;
    string Nim;
    string Kelas;
    float Nilai_Asesmen;
    float Nilai_Praktikum;
};

// Node untuk Single Linked List
struct Node {
    Mahasiswa info;
    Node* next;
};

// Function: Membuat node baru
Node* newElement(Mahasiswa data) {
    Node* newNode = new Node;
    newNode->info = data;
    newNode->next = nullptr;
    return newNode;
}

// Function: Membuat list baru (kosong)
Node* newList() {
    return nullptr;
}

// Procedure: Insert First untuk NIM ganjil
void insertFirst(Node*& head, Mahasiswa data) {
    Node* newNode = newElement(data);
    newNode->next = head;
    head = newNode;
}

// Procedure: Menampilkan semua data mahasiswa
void printList(Node* head) {
    if (head == nullptr) {
        cout << "List kosong!" << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << "Nama: " << current->info.Nama << endl;
        cout << "NIM: " << current->info.Nim << endl;
        cout << "Kelas: " << current->info.Kelas << endl;
        cout << "Nilai Asesmen: " << current->info.Nilai_Asesmen << endl;
        cout << "Nilai Praktikum: " << current->info.Nilai_Praktikum << endl;
        cout << "-----------------------------" << endl;
        current = current->next;
    }
}

// Procedure: Menampilkan mahasiswa dengan nilai asesmen tertinggi
void findHighestAsesmen(Node* head) {
    if (head == nullptr) {
        cout << "List kosong!" << endl;
        return;
    }

    Node* highest = head;
    Node* current = head->next;

    while (current != nullptr) {
        if (current->info.Nilai_Asesmen > highest->info.Nilai_Asesmen) {
            highest = current;
        }
        current = current->next;
    }

    cout << "\nMahasiswa dengan nilai asesmen tertinggi:" << endl;
    cout << "Nama: " << highest->info.Nama << endl;
    cout << "NIM: " << highest->info.Nim << endl;
    cout << "Nilai Asesmen: " << highest->info.Nilai_Asesmen << endl;
}

// Procedure: Menghapus data dengan NIM duplikat
void deleteDuplicates(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        Node* prev = current;
        Node* validasi = current->next;

        while (validasi != nullptr) {
            if (validasi->info.Nim == current->info.Nim) {
                prev->next = validasi->next;
                delete validasi;
                validasi = prev->next;
            } else {
                prev = validasi;
                validasi = validasi->next;
            }
        }
        current = current->next;
    }
}

// Program Utama
int main() {
    Node* list = newList(); // Membuat list kosong
    int N;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> N;
    cin.ignore(); 

    // Input data mahasiswa
    for (int i = 0; i < N; i++) {
        Mahasiswa data;
        cout << "\nMasukkan data mahasiswa ke-" << i + 1 << ":" << endl;
        cout << "Nama: ";
        getline(cin, data.Nama);
        cout << "NIM: ";
        cin >> data.Nim;
        cout << "Kelas: ";
        cin >> data.Kelas;
        cout << "Nilai Asesmen: ";
        cin >> data.Nilai_Asesmen;
        cout << "Nilai Praktikum: ";
        cin >> data.Nilai_Praktikum;
        cin.ignore(); 

        
        if (stoi(data.Nim) % 2 != 0) {
            insertFirst(list, data);
        } else {
            cout << "Data dengan NIM genap diabaikan." << endl;
        }
    }

    // Menampilkan semua data mahasiswa
    cout << "\nData Mahasiswa:" << endl;
    printList(list);

    // Menampilkan mahasiswa dengan nilai asesmen tertinggi
    findHighestAsesmen(list);

    // Menghapus data dengan NIM duplikat
    deleteDuplicates(list);
    cout << "\nList setelah menghapus duplikat:" << endl;
    printList(list);

    return 0;
}