//Zhafir Zaidan Avail
//2311104059
// Kelas : S1-SE-07-02

#include "doublelinkedlist.h"
#include <iostream>
#include <string>

// Fungsi utama
int main() {
    List list = newList(); // Inisialisasi linked list
    int N;

    std::cout << "Jumlah Data Mahasiswa: ";
    std::cin >> N;

    // Memasukkan data mahasiswa
    for (int i = 0; i < N; ++i) {
        Mahasiswa mhs;
        std::cout << "\nMahasiswa ke-" << (i + 1) << ":\n";

        std::cout << "Masukan Nama: ";
        std::cin.ignore(); // Membersihkan buffer
        std::getline(std::cin, mhs.nama);

        std::cout << "Masukan NIM: ";
        std::getline(std::cin, mhs.NIM);

        std::cout << "Masukan Kelas: ";
        std::getline(std::cin, mhs.kelas);

        std::cout << "Masukan Nilai Assesmen: ";
        std::cin >> mhs.nilaiAsesmen;

        std::cout << "Masukan Nilai Praktikum: ";
        std::cin >> mhs.nilaiPraktikum;

        // Menambahkan data mahasiswa ke akhir list
        Node* newNode = newElement(mhs);
        insertLast(list, newNode);
    }

    std::cout << "\nData mahasiswa dalam list:\n";
    printList(list);

    Mahasiswa tertinggi = findHighestAsesmen(list);
    std::cout << "\nMahasiswa dengan nilai asesmen tertinggi:\n";
    std::cout << "Nama: " << tertinggi.nama << ", NIM: " << tertinggi.NIM
              << ", Kelas: " << tertinggi.kelas << ", Nilai Asesmen: " << tertinggi.nilaiAsesmen
              << ", Nilai Praktikum: " << tertinggi.nilaiPraktikum << std::endl;

    removeDuplicates(list);
    std::cout << "\nSetelah pengecekan duplikat:\n";
    printList(list);

    return 0;
}
