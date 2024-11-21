#include <iostream>
#include <string>
using namespace std;

// Dhiemas Tulus Ikhsan
// 2311104046 
// SE-07-02

struct infotype {
    string nama;
    string NIM;
    string kelas;
    float nilaiAsesmen;
    float nilaiPraktikum;
};

struct Node {
    infotype info;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;

Node* newElement (infotype data) {
    Node* p = new Node;
    p->info = data;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

void insertLast(Node* &head, Node* &tail, Node* p){
    if (head == nullptr) {
        head = p;
        tail = p;
    } else {
        p->prev = tail;
        tail->next = p;
        tail = p;
    }
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "List kosong!" << endl;
    } else {
        Node* p = head;
        while (p != nullptr) {
            cout << "Nama: " << p->info.nama << ", NIM: " << p->info.NIM
                 << ", Kelas: " << p->info.kelas
                 << ", Nilai Asesmen: " << p->info.nilaiAsesmen
                 << ", Nilai Praktikum: " << p->info.nilaiPraktikum << endl;
            p = p->next;
        }
    }
}

void showHighestAsesmen(Node* head){
    if (head == nullptr){
       cout << "List kosong!" << endl;
       return;
    }
    Node* p = head;
    Node* maxNode = head;
    while (p != nullptr) {
        if (p->info.nilaiAsesmen > maxNode->info.nilaiAsesmen) {
            maxNode = p;
        }
        p = p->next;
    }

    cout << "\nMahasiswa dengan nilai asesmen tertinggi:\n";
    cout << "Nama: " << maxNode->info.nama << ", NIM: " << maxNode->info.NIM
         << ", Kelas: " << maxNode->info.kelas
         << ", Nilai Asesmen: " << maxNode->info.nilaiAsesmen
         << ", Nilai Praktikum: " << maxNode->info.nilaiPraktikum << endl;
}

void deleteDuplicateNIM(Node* &head, Node* &tail) {
    if (head == nullptr){
        cout << "List kosong!" << endl;
        return;
    }

    bool foundDuplicate = false;

     Node* p = head;
    while (p != nullptr){
        Node* q = p->next;
        while (q != nullptr) {
            if (q->info.NIM == p->info.NIM) {
                Node* duplicate = q;
                if (q->next != nullptr) {
                    q->next->prev = q->prev;
                } else {
                    tail = q->prev;
                }

                if (q->prev != nullptr) {
                    q->prev->next = q->next;
                }

                q = q->next;
                delete duplicate;
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }
    if (foundDuplicate) {
        cout << "\nDuplikat NIM berhasil dihapus.\n";
    } else {
        cout << "\nTidak ada duplikat NIM ditemukan.\n";
    }
}

int main() {
    int N;
    cout << "Berapa banyak data yang akan dimasukkan? ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        infotype data;
        cout << "Masukkan Nama: ";
        cin >> data.nama;
        cout << "Masukkan NIM: ";
        cin >> data.NIM;
        cout << "Masukkan Kelas: ";
        cin >> data.kelas;
        cout << "Masukkan Nilai Asesmen: ";
        cin >> data.nilaiAsesmen;
        cout << "Masukkan Nilai Praktikum: ";
        cin >> data.nilaiPraktikum;


        Node* p = newElement(data);
        insertLast(head, tail, p);
    }

    cout << "\nData Mahasiswa dalam List:" << endl;
    printList(head);

    showHighestAsesmen(head);

    deleteDuplicateNIM(head, tail);
    cout << "\nData Mahasiswa setelah menghapus duplikat NIM:" << endl;
    printList(head);

    return 0;
}
