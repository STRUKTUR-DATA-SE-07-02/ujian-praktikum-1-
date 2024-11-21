//Nama  : Ganesha Rahman Gibran
//NIM   : 2211104(058)
//Kelas : S1SE-07-02
//Soal  : Double Linked List (Genap)

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string NIM;
    string kelas;
    float nilaiAsesmen;
    float nilaiPraktikum;
};

struct Node {
    Mahasiswa data;
    Node* next;
    Node* prev;
};

struct List {
    Node* first;
    Node* last;
};

Node* newElement(Mahasiswa mhs) {
    Node* newNode = new Node();
    newNode->data = mhs;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

List* newList() {
    List* newList = new List();
    newList->first = nullptr;
    newList->last = nullptr;
    return newList;
}

void insertLast(List* list, Node* newNode) {
    if (list->last == nullptr) {
        list->first = newNode;
        list->last = newNode;
    } else {
        newNode->prev = list->last;
        list->last->next = newNode;
        list->last = newNode;
    }
}

void tambahMahasiswa(List* list, Mahasiswa mhs) {
    Node* newNode = newElement(mhs);
    insertLast(list, newNode);
}

void printList(List* list) {
    if (list->first == nullptr) {
        cout << "List kosong.\n";
        return;
    }
    Node* current = list->first;
    while (current != nullptr) {
        Mahasiswa mhs = current->data;
        cout << "Nama: " << mhs.nama
             << ", NIM: " << mhs.NIM
             << ", Kelas: " << mhs.kelas
             << ", Nilai Asesmen: " << mhs.nilaiAsesmen
             << ", Nilai Praktikum: " << mhs.nilaiPraktikum << endl;
        current = current->next;
    }
}

void asesmenTertinggi(List* list) {
    if (list->first == nullptr) {
        cout << "List kosong.\n";
        return;
    }
    Node* current = list->first;
    Node* maxNode = current;
    while (current != nullptr) {
        if (current->data.nilaiAsesmen > maxNode->data.nilaiAsesmen) {
            maxNode = current;
        }
        current = current->next;
    }
    Mahasiswa mhs = maxNode->data;
    cout << "Mahasiswa dengan nilai asesmen tertinggi:\n";
    cout << "Nama: " << mhs.nama
         << ", NIM: " << mhs.NIM
         << ", Kelas: " << mhs.kelas
         << ", Nilai Asesmen: " << mhs.nilaiAsesmen
         << ", Nilai Praktikum: " << mhs.nilaiPraktikum << endl;
}

void hapusDuplikat(List* list) {
    if (list->first == nullptr) return;

    Node* current = list->first;
    while (current != nullptr) {
        Node* checker = current->next;
        while (checker != nullptr) {
            if (current->data.NIM == checker->data.NIM) {
                Node* duplicate = checker;
                if (duplicate->next != nullptr) duplicate->next->prev = duplicate->prev;
                if (duplicate->prev != nullptr) duplicate->prev->next = duplicate->next;
                if (duplicate == list->last) list->last = duplicate->prev;
                checker = duplicate->next;
                delete duplicate;
            } else {
                checker = checker->next;
            }
        }
        current = current->next;
    }
}

void hapusNIM(List* list, string nim) {
    if (list->first == nullptr) return;

    Node* current = list->first;
    while (current != nullptr) {
        if (current->data.NIM == nim) {
            if (current->prev != nullptr) current->prev->next = current->next;
            if (current->next != nullptr) current->next->prev = current->prev;
            if (current == list->first) list->first = current->next;
            if (current == list->last) list->last = current->prev;
            delete current;
            cout << "NIM " << nim << " berhasil dihapus.\n";
            return;
        }
        current = current->next;
    }
    cout << "NIM " << nim << " tidak ditemukan.\n";
}

int main() {
    List* mahasiswaList = newList();
    int pilihan;

    do {
        cout << "\nMatakuliah Matematika\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Tampilkan Data\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int jumlah;
            cout << "Masukkan jumlah mahasiswa: ";
            cin >> jumlah;
            for (int i = 0; i < jumlah; i++) {
                Mahasiswa mhs;
                cout << "Masukkan Nama: ";
                cin >> mhs.nama;
                cout << "Masukkan NIM: ";
                cin >> mhs.NIM;
                cout << "Masukkan Kelas: ";
                cin >> mhs.kelas;
                cout << "Masukkan Nilai Asesmen: ";
                cin >> mhs.nilaiAsesmen;
                cout << "Masukkan Nilai Praktikum: ";
                cin >> mhs.nilaiPraktikum;
                tambahMahasiswa(mahasiswaList, mhs);
            }
        } else if (pilihan == 2) {
            int subPilihan;
            cout << "1. Hapus Duplikasi\n";
            cout << "2. Hapus Berdasarkan NIM\n";
            cout << "Pilih: ";
            cin >> subPilihan;
            if (subPilihan == 1) {
                hapusDuplikat(mahasiswaList);
                cout << "Duplikasi data berhasil dihapus.\n";
            } else if (subPilihan == 2) {
                string nim;
                cout << "Masukkan NIM yang akan dihapus: ";
                cin >> nim;
                hapusNIM(mahasiswaList, nim);
            } else {
                cout << "Pilihan tidak valid.\n";
            }
        } else if (pilihan == 3) {
            int subPilihan;
            cout << "1. Lihat semua list\n";
            cout << "2. Nilai asesmen tertinggi\n";
            cout << "Pilih: ";
            cin >> subPilihan;
            if (subPilihan == 1) {
                printList(mahasiswaList);
            } else if (subPilihan == 2) {
                asesmenTertinggi(mahasiswaList);
            } else {
                cout << "Pilihan tidak valid.\n";
            }
        } else if (pilihan == 4) {
            cout << "Keluar dari program.\n";
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}
