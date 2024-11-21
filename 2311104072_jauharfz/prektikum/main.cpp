/*
 *Jauhar Fajar Zuhair
 *2311104072
 *S1SE-07-02
 */
#include "doubleList.h"

int main()
{
    cout << "================================" << endl;
    cout << "Nama: [Isi Nama]" << endl;
    cout << "NIM: [Isi NIM]" << endl;
    cout << "Kelas: [Isi Kelas]" << endl;
    cout << "================================" << endl;

    List L = createNewList();
    int N;

    cout << "Masukkan jumlah data: ";
    cin >> N;

    tambahNData(L, N);

    cout << "\nData Mahasiswa:" << endl;
    printList(L);

    cout << "\nData Mahasiswa dengan Nilai Asesmen Tertinggi:" << endl;
    tampilNilaiAsesmenTertinggi(L);

    cout << "\nMenghapus Data Duplikat..." << endl;
    hapusDuplikatNIM(L);

    cout << "\nData Mahasiswa setelah penghapusan duplikat:" << endl;
    printList(L);

    return 0;
}
