// Nama : Satria Putra Dharma Prayudha
// NIM : 21104036
// Kelas : SE-07-02

#include "doublelist.h"
#include <iostream>

int main() {
    List list = newList();
    int N;

    std::cout << "Jumlah Data Mahasiswa: ";
    std::cin >> N;

    addNData(list, N);

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