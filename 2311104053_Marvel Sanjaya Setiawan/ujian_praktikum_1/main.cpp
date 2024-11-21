//Marvel Sanjaya Setiawan
//2311104053

#include "LinkedList.h"
#include "LinkedList.cpp"

int main() {
    LinkedList list;
    list.createNewList();
    int N;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string nama, nim, kelas;
        float nilaiAsesmen, nilaiPraktikum;
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        cout << "Masukkan kelas: ";
        cin >> kelas;
        cout << "Masukkan nilai asesmen: ";
        cin >> nilaiAsesmen;
        cout << "Masukkan nilai praktikum: ";
        cin >> nilaiPraktikum;

        Mahasiswa* newMahasiswa = list.newElement(nama, nim, kelas, nilaiAsesmen, nilaiPraktikum);

        list.insertFirst(newMahasiswa);  // Insert menggunakan mekanisme insertFirst tanpa memeriksa NIM
    }

    cout << "\nData mahasiswa: \n";
    list.printList();

    Mahasiswa* highest = list.findHighestAsesmen();
    if (highest != nullptr) {
        cout << "\nMahasiswa dengan nilai asesmen tertinggi: \n";
        cout << "Nama: " << highest->nama << ", NIM: " << highest->nim << ", Kelas: " << highest->kelas
             << ", Nilai Asesmen: " << highest->nilaiAsesmen << ", Nilai Praktikum: " << highest->nilaiPraktikum << endl;
    }

    list.removeDuplicates();
    cout << "\nData mahasiswa setelah menghapus duplikat: \n";
    list.printList();

    return 0;
}

