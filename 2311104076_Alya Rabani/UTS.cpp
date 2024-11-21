#include <iostream>
#include <string>

using namespace std;
struct Mahasiswa{
    string nama;
    int NIM;
    string kelas;
    float nilaiAssesment;
    float nilaiPraktikum;
    Mahasiswa* prev;
    Mahasiswa* next;
};

Mahasiswa* newElement(string nama, int NIM, string kelas, float nilaiAssesment, float nilaiPraktikum){
    Mahasiswa* newNode = new Mahasiswa;
    newNode -> nama = nama;
    newNode -> NIM = NIM;
    newNode -> kelas = kelas;
    newNode -> nilaiAssesment = nilaiAssesment;
    newNode -> nilaiPraktikum = nilaiPraktikum;
    newNode -> prev = nullptr;
    newNode -> next = nullptr;
    return newNode;
}

void printList (Mahasiswa *head){
    if (!head) {
        cout << "List kosong.";
        return;
    }
    Mahasiswa *temp = head;
    while (temp) {
        cout << "Nama: " << temp->nama
            << ", NIM: " << temp->NIM
            << ", Kelas: " << temp->kelas
            << ", Nilai Assesment: " << temp->nilaiAssesment
            << ", Nilai Praktikum: " << temp->nilaiPraktikum << endl;
        temp = temp->next;
    }
}

void insertLast(Mahasiswa* &head, Mahasiswa* &tail, string nama, int NIM, string kelas, float nilaiAssesment, float nilaiPraktikum){
    Mahasiswa* newNode = newElement(nama, NIM, kelas, nilaiAssesment, nilaiPraktikum);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
}

void removeDuplicates(Mahasiswa* &head, Mahasiswa* &tail){
    for (Mahasiswa *outer = head; outer; outer = outer->next){
        for (Mahasiswa *inner = outer->next; inner;){
            if (inner->NIM == outer->NIM){
                Mahasiswa *duplicate = inner;
                inner = inner-> next;

                if (duplicate->prev) duplicate->prev->next = duplicate->next;
                if (duplicate->next) duplicate->next->prev = duplicate->prev;
                if (duplicate == head) head = duplicate->next;
                if (duplicate == tail) tail = duplicate->prev;

                delete duplicate;
            } else{
                inner = inner->next;
            }
        }
    }
}

void printHIghestAssesment(Mahasiswa *head){
    if (!head){
        cout << "List Kosong.";
        return;
    }

    Mahasiswa *maxNode = head;
    for (Mahasiswa *temp = head->next; temp; temp = temp->next){
        if (temp->nilaiAssesment > maxNode->nilaiAssesment) {
            maxNode = temp;
        }
    }

    cout << "Mahasiswa dengan nilai assesment tertinggi: ";
    cout << "Nama: " << maxNode->nama
        << ", NIM: " << maxNode->NIM
        << ", Nilai Assesment: " << maxNode->nilaiAssesment << endl;
}

int main()
{
    cout << "Nama: Alya Rabani" << endl;
    cout << "NIM: 2311104076" << endl;
    cout << "Kelas: S1SE-07-02" << endl;

    Mahasiswa *head = nullptr, *tail = nullptr;
    insertLast(head, tail, "Alya", 2311104076, "02", 14.5, 30.5);
    insertLast(head, tail, "Madmax", 2311104011, "01", 50.5, 75.0);
    insertLast(head, tail, "Eleven", 20114012, "03", 47.8, 25.3);
    insertLast(head, tail, "Erica", 21114037, "02", 15.4, 23.7);

    cout << "Daftar Mahasiswa: ";
    printList(head);

    printHIghestAssesment(head);

    removeDuplicates(head, tail);
    cout << "Setelah menghapus data duplikat: ";
    printList(head);

    return 0;
}