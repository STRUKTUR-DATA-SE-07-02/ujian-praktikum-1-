//Dimastian Aji WIbowo
//2311104058
#include "doublelinkedlist.h"
#include <iostream>
using namespace std;

Mahasiswa* newElement(string nama, string nim, string kelas, int nilaiAsesmen, int nilaiPraktikum){
    Mahasiswa* p = new Mahasiswa;
    p->nama = nama;
    p->nim = nim;
    p->kelas = kelas;
    p->nilaiAsesmen = nilaiAsesmen;
    p->nilaiPraktikum = nilaiPraktikum;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}
Mahasiswa* createNewList(){
    return nullptr;
}
bool isEmpty(Mahasiswa* list){
    return list == nullptr;
}
void insertLast(Mahasiswa*& list, Mahasiswa* p){
    if(isEmpty(list)){
        list = p;
    }else{
        Mahasiswa* temp = list;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp;
    }
}
void deleteFirst(Mahasiswa*& list, Mahasiswa*& p){
    if(!isEmpty(list)){
        p = list;
        list = list->next;
        if (list != nullptr) list->prev = nullptr;
        p->next = nullptr;
    }
}
void deleteLast(Mahasiswa*& list, Mahasiswa*& p){
    if(!isEmpty(list)){
        if(list->next == nullptr){
            p = list;
            list = nullptr;
        }else{
            Mahasiswa* temp = list;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            p = temp;
            temp->prev->next = nullptr;
            temp->prev = nullptr;
        }
    }
}
int length(Mahasiswa* list){
    int count = 0;
    while (list != nullptr){
        count++;
        list = list->next;
    }
    return count;
}
Mahasiswa* findElement(Mahasiswa* list, string nim){
    while(list != nullptr){
        if (list->nim == nim) return list;
        list = list->next;
    }
    return nullptr;
}
void printList(Mahasiswa* list){
    while(list != nullptr){
        cout<<list->nama<<" | "<<list->nim<<" | "<<list->kelas
             <<" | Asesmen: "<<list->nilaiAsesmen
             <<" | Praktikum: "<<list->nilaiPraktikum<<endl;
        list = list->next;
    }
}
void tambahData(Mahasiswa*& list, int N){
    cin.ignore();
    for(int i = 0; i < N; i++){
        string nama, nim, kelas;
        int nilaiAsesmen, nilaiPraktikum;

        cout<<"Masukkan Nama: ";
        getline(cin, nama);

        cout<<"Masukkan NIM: ";
        cin>>nim;

        cout<<"Masukkan Kelas: ";
        cin>>kelas;

        cout<<"Masukkan Nilai Asesmen: ";
        cin>>nilaiAsesmen;

        cout<<"Masukkan Nilai Praktikum: ";
        cin>>nilaiPraktikum;

        cin.ignore();

        Mahasiswa* p = newElement(nama, nim, kelas, nilaiAsesmen, nilaiPraktikum);
        insertLast(list, p);
    }
}
void tampilkanNilaiTertinggi(Mahasiswa* list){
    if(isEmpty(list)){
        cout<<"List kosong.\n";
        return;
    }
    Mahasiswa* max = list;
    Mahasiswa* temp = list;
    while(temp != nullptr){
        if(temp->nilaiAsesmen > max->nilaiAsesmen){
            max = temp;
        }
        temp = temp->next;
    }
    cout<<"Mahasiswa dengan nilai asesmen tertinggi:\n";
    cout<<max->nama<<" | "<<max->nim<<" | "<<max->kelas
         <<" | Asesmen: "<<max->nilaiAsesmen
         <<" | Praktikum: "<<max->nilaiPraktikum<<endl;
}
void hapusDuplikat(Mahasiswa*& list){
    if(isEmpty(list)) return;

    Mahasiswa* current = list;
    while(current != nullptr){
        Mahasiswa* runner = current->next;
        while(runner != nullptr){
            if(runner->nim == current->nim){
                Mahasiswa* temp = runner;
                if(runner->prev != nullptr)runner->prev->next = runner->next;
                if(runner->next != nullptr)runner->next->prev = runner->prev;
                runner = runner->next;
                delete temp;
            }else{
                runner = runner->next;
            }
        }
        current = current->next;
    }
}
