#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string namaMhs;
    string nimMhs;
    string kelasMhs;
    float nilaiAssesmentMhs;
    float nilaiPraktikumMhs;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

Node* newElement(Mahasiswa data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

bool isEmpty(Node* head) {
    return head == nullptr;
}

void insertFirst(Node*& head, Node* newNode) {
    newNode->next = head;
    head = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << "Nama Mahasiswa: " << current->data.namaMhs << endl;
        cout << "NIM Mahasiswa: " << current->data.nimMhs << endl;
        cout << "Kelas Mahasiswa: " << current->data.kelasMhs << endl;
        cout << "Nilai Asesmen Mahasiswa: " << current->data.nilaiAssesmentMhs << endl;
        cout << "Nilai Praktikum Mahasiswa: " << current->data.nilaiPraktikumMhs << endl;
        cout << "========================" << endl;
        current = current->next;
    }
}

void findHighestAsesmen(Node* head) {
    if (isEmpty(head)) {
        cout << "List kosong, tidak ada nilai asesmen tertinggi." << endl;
        return;
    }

    Node* current = head;
    Mahasiswa nilaitertinggi = current->data;

    while (current != nullptr) {
        if (current->data.nilaiAssesmentMhs > nilaitertinggi.nilaiAssesmentMhs) {
            nilaitertinggi = current->data;
        }
        current = current->next;
    }

    cout << "\nMahasiswa dengan nilai asesmen tertinggi:" << endl;
    cout << "Nama: " << nilaitertinggi.namaMhs << endl;
    cout << "NIM: " << nilaitertinggi.nimMhs << endl;
    cout << "Nilai Asesmen: " << nilaitertinggi.nilaiAssesmentMhs << endl;
}

void deleteDuplicates(Node*& head) {
    if (isEmpty(head)) return;

    Node* current = head;
    while (current != nullptr) {
        Node* prev = current;
        Node* dltdpkMhs = current->next;

        while (dltdpkMhs != nullptr) {
            if (dltdpkMhs->data.nimMhs == current->data.nimMhs) {
                cout << "Duplikat ditemukan: " << dltdpkMhs->data.nimMhs << endl;
                prev->next = dltdpkMhs->next;
                delete dltdpkMhs;
                dltdpkMhs = prev->next;
            } else {
                prev = dltdpkMhs;
                dltdpkMhs = dltdpkMhs->next;
            }
        }
        current = current->next;
    }
}

void TambahMahasiswa(Node*& head, int N) {
    for (int i = 0; i < N; ++i) {
        Mahasiswa mhs;
        cout << "\nMasukkan Data Mahasiswa ke-" << i + 1 << ":" << endl;
        cout << "Nama: ";
        getline(cin, mhs.namaMhs);
        cout << "NIM: ";
        cin >> mhs.nimMhs;
        cin.ignore();
        cout << "Kelas: ";
        getline(cin, mhs.kelasMhs);
        cout << "Nilai Asesmen: ";
        cin >> mhs.nilaiAssesmentMhs;
        cout << "Nilai Praktikum: ";
        cin >> mhs.nilaiPraktikumMhs;
        cin.ignore();

        if (!mhs.nimMhs.empty() && (mhs.nimMhs[0] % 2 != 0)) {
            Node* newNode = newElement(mhs);
            insertFirst(head, newNode);
        } else {
            cout << "NIM harus tidak kosong dan harus memiliki angka ganjil." << endl;
        }
    }
}

int main() {
    Node* head = nullptr;
    int N;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> N;
    cin.ignore();

    TambahMahasiswa(head, N);

    cout << "\n==== Data Mahasiswa ====" << endl;
    printList(head);

    findHighestAsesmen(head);

    deleteDuplicates(head);
    cout << "\n==== Data Mahasiswa Setelah Menghapus Duplikat ====" << endl;
    printList(head);

    return 0;
}
