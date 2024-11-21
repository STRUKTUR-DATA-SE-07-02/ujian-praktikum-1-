#include "dll_32.h"

int main() {
    List L;
    createNewList(L);

    int N;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        infotype data;

        // Input data mahasiswa
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

        address P = newElement(data);
        insertLast(L, P); 
    }

    cout << "Data Mahasiswa:" << endl;
    printList(L);

    printHighestAsesmen(L);
    
    removeDuplicateNIM(L);

    cout << "Data Mahasiswa setelah menghapus duplikat:" << endl;
    printList(L);

    return 0;
}
