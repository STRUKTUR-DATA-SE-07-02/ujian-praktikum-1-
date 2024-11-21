#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string nama;
    int nim;
    string kelas;
    float nilaiAsesmen;
    float nilaiPraktikum;
    Node*prev;
    Node*next;
};

    class DoubleLinkedList(){
    private:
        Node = nullptr;
        Node = nullptr;

    public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(string nama,int nim, string kelas,float nilaiAsesmen, float nilaiPraktikum){
        if (nim % 2 != 0){
        cout<"nim ganjil tidak ada"<< endl;
        return;
        }

        Node*newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->kelas = kelas;
        newNode->nilaiAsesmen = nilaiAsesmen;
        newNode->nilaiPraktikum = nilaiPraktikum;

        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (!head){
            head = newNode;
            tail = newNode;

        } else {
            tail-> next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void findHighest(){
        if (!head){
            cout << "list kosong "<< endl;
            return;
        }
        
        Node* temp = head;
        Node* highest = head;
        while(temp){   
            if (temp-> nilaiAsesmen > highest-> nilaiAsesmen){
                highest = temp;
            }
            temp = temp-> next;
        }
        cout <<"mahasiswa dengan nilai asesmen tertinggi :" <<endl;
        cout <<"nama:"<<highest-> nama << NIM: << highest->  nim
            <<", nilai asesmen:" <<highest ->nilaiAsesmen << endl;
    }

    void deleteDuplicates(){
        Node* current = tail;

        while (current != nullptr) {
            Node* checker = current->prev;

            while (checker != nullptr) {
                if (checker->nim == current->nim) {
                    // Menghapus node duplikat
                    if (checker->prev) {
                        checker->prev->next = checker->next;
                    }
                    if (checker->next) {
                        checker->next->prev = checker->prev;
                    }
                    if (checker == head) {
                        head = checker->next;
                    }

                    Node* duplicate = checker;
                    checker = checker->prev;

                    delete duplicate; // Dealokasi node duplikat
                } else {
                    checker = checker->prev;
                }
            }

            current = current->prev;
        }
    }

    // Fungsi untuk mencetak isi list
    void print() {
        if (!head) {
            cout << "List kosong." << endl;
            return;
        }

        Node* current = head;
        while (current) {
            cout << "Nama: " << current->nama << endl;
            cout << "NIM: " << current->nim << endl;
            cout << "Kelas: " << current->kelas << endl;
            cout << "Nilai Asesmen: " << current->nilaiAsesmen << endl;
            cout << "Nilai Praktikum: " << current->nilaiPraktikum << endl;
            cout << "-----------------------" << endl;
            current = current->next;
        }
    }
};

int main() {
    DoubleLinkedList list;

    int n;
    cout << "Masukkan jumlah data mahasiswa: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string nama, kelas;
        int nim;
        float nilaiAsesmen, nilaiPraktikum;

        cout << "Nama: ";
        cin >> nama;
        cout << "NIM: ";
        cin >> nim;
        cout << "Kelas: ";
        cin >> kelas;
        cout << "Nilai Asesmen: ";
        cin >> nilaiAsesmen;
        cout << "Nilai Praktikum: ";
        cin >> nilaiPraktikum;

        list.insert(nama, nim, kelas, nilaiAsesmen, nilaiPraktikum);
    }

    cout << "\nData Mahasiswa:" << endl;
    list.print();

    cout << "\nMenghapus data duplikat berdasarkan NIM..." << endl;
    list.deleteDuplicates();

    cout << "\nData Mahasiswa setelah penghapusan duplikat:" << endl;
    list.print();

    return 0;
}