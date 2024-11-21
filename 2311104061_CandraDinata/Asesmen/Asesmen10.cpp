//Nama:CandraDinata
//Nim:2311104061
//Kelas:SE0702

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    string kelas;
    float nilaiasesmen;
    float nilaipraktikum;
};
typedef Mahasiswa infotype;
struct Element {
    infotype info;
    Element *next;
};
typedef Element* address;
struct List {
    address first;
};
address newElement(infotype data) {
    address newEl = new Element;
    newEl->info = data;
    newEl->next = NULL;
    return newEl;
}
List createNewList() {
    List L;
    L.first = NULL;
    return L;
}
void insertFirst(List &L, address p) {
    p->next = L.first;
    L.first = p;
}
void printList(List L) {
    address p = L.first;
    while (p != NULL) {
        cout<<"Nama : "<<p->info.nama<<endl;
        cout<<"Nim : " <<p->info.nim<<endl;
        cout<<"Kelas : "<<p->info.kelas<<endl;
        cout<<"Nilai Asesmen : "<<p->info.nilaiasesmen<<endl;
        cout<<"Nilai Praktikum : "<<p->info.nilaipraktikum<<endl;
        cout<<"---------------------------" <<endl;
        p = p->next;
    }
}
void addMahasiswa(List &L, infotype data) {
    address p = newElement(data);
    insertFirst(L, p);
}

address findTopScore(List L) {
    address p = L.first;
    address top = NULL;
    if (p != NULL) {
        top = p;
        while (p != NULL) {
            if (p->info.nilaiasesmen > top->info.nilaiasesmen) {
                top = p;
            }
            p = p->next;
        }
    }
    return top;
}

bool removeDuplicate(List &L) {
    bool isDuplicateRemoved = false;
    address p = L.first;
    while (p != NULL) {
        address q = p;
        while (q->next != NULL) {
            if (q->next->info.nim == p->info.nim) {
                address temp = q->next;
                q->next = q->next->next;
                delete temp;
                isDuplicateRemoved = true;
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }
    return isDuplicateRemoved;
}

int main() {
    List L = createNewList();
    char pilihan;
    do {
        infotype data;
        cout<<"Masukkan Data Mahasiswa"<<endl;
        cout<<"Nama : ";
        cin>>data.nama;
        cout<<"Nim : ";
        cin>>data.nim;
        cout<<"Kelas : ";
        cin>>data.kelas;
        cout<<"Nilai Asesmen : ";
        cin>>data.nilaiasesmen;
        cout<<"Nilai Praktikum : ";
        cin>>data.nilaipraktikum;
        addMahasiswa(L, data);
        cout<<"Apakah ingin menambah data mahasiswa? (y/n) ";
        cin>>pilihan;
    } while (pilihan == 'y' || pilihan == 'Y');
    cout << "\nData mahasiswa:" << endl;
    printList(L);
    
address top = findTopScore(L);
    if (top != NULL) {
        cout<<"\nMahasiswa dengan nilai asesmen tertinggi : "<<endl;
        cout<<"Nama : "<<top->info.nama<<", Nim : "<< top->info.nim<< ", Nilai Asesmen: "<<top->info.nilaiasesmen<<endl;}  
    else {
        cout<<"\nTidak ada data mahasiswa."<<endl;
    }

cout<<"\nProses menghapus data mahasiswa yang memiliki Nim duplikat"<<endl;
    if (removeDuplicate(L)) {
        cout<<"Data mahasiswa dengan Nim duplikat berhasil dihapus."<<endl;} 
    else {
        cout<<"Tidak ditemukan Nim duplikat."<<endl;
    }
    cout<<"\nData mahasiswa setelah penghapusan Nim duplikat : "<<endl;
    printList(L);

    return 0;
}