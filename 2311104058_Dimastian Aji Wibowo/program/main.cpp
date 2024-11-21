//Dimastian Aji WIbowo
//2311104058
#include "doublelinkedlist.h"
#include <iostream>
using namespace std;

int main(){
    Mahasiswa* list = createNewList();
    int N;

    cout<<"Masukkan jumlah data mahasiswa: ";
    cin>>N;

    tambahData(list, N);

    cout<<"\nData Mahasiswa:\n";
    printList(list);

    cout<<"\nMahasiswa dengan nilai asesmen tertinggi:\n";
    tampilkanNilaiTertinggi(list);

    hapusDuplikat(list);
    cout<<"\nData Mahasiswa setelah menghapus duplikat:\n";
    printList(list);

    return 0;
}
