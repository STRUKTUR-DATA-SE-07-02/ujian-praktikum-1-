// Nama :Fauzan Rofif Ardiyanto
// Kelas : S1SE0602
//  Nim : 2211104036 //

#include "list_mahasiswa.h"

int main()
{
    List L;
    createNewList(L);

    int N;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        infotype data;

        cout << "Masukkan Nama: ";
        cin >> data.nama;
        cout << "Masukkan NIM: ";
        cin >> data.NIM;
        cout << "Masukkan Kelas: ";
        cin >> data.kelas;
        cout << "Masukkan Nilai Ujian: ";
        cin >> data.nilaiUjian;
        cout << "Masukkan Nilai Praktikum: ";
        cin >> data.nilaiPraktikum;

        address P = newElement(data);
        insertLast(L, P);
    }

    // Cetak isi list
    cout << "Data Mahasiswa:" << endl;
    printList(L);

    printHighestUjian(L);
    removeDuplicateNIM(L);
    cout << "Data Mahasiswa setelah menghapus duplikat:" << endl;
    printList(L);

    return 0;
}