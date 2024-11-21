#include "linked_list.h"

int main() {
    List mahasiswaList = createNewList();

    int n;
    cout << "Masukkan jumlah data mahasiswa: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Mahasiswa mahasiswa;
        cin.ignore();  
        cout << "Masukkan nama: ";
        getline(cin, mahasiswa.name);
        cout << "Masukkan NIM: ";
        cin >> mahasiswa.nim;
        while (mahasiswa.nim.length() != 10 || !isdigit(mahasiswa.nim[0])) {
            cout << "NIM harus berupa 10 digit angka. Masukkan ulang: ";
            cin >> mahasiswa.nim;
        }
        cin.ignore();  
        cout << "Masukkan kelas: ";
        getline(cin, mahasiswa.class_name);
        cout << "Masukkan nilai asesmen: ";
        cin >> mahasiswa.assessment_score;
        cout << "Masukkan nilai praktikum: ";
        cin >> mahasiswa.practical_score;

        Node* new_node = newElement(mahasiswa);
        if ((mahasiswa.nim[mahasiswa.nim.length() - 1] - '0') % 2 == 0) {
            insertLast(mahasiswaList, new_node);
        } else {
            insertFirst(mahasiswaList, new_node);
        }
    }

    cout << "\nData Mahasiswa:" << endl;
    printList(mahasiswaList);

    Node* highest = findHighestAssessment(mahasiswaList);
    if (highest != nullptr) {
        cout << "\nMahasiswa dengan nilai asesmen tertinggi:" << endl;
        cout << "Nama: " << highest->data.name
             << ", NIM: " << highest->data.nim
             << ", Nilai Asesmen: " << highest->data.assessment_score
             << endl;
    }

    cout << "\nMenghapus data mahasiswa dengan NIM duplikat..." << endl;
    removeDuplicates(mahasiswaList);

    cout << "\nData Mahasiswa setelah menghapus duplikat:" << endl;
    printList(mahasiswaList);

    return 0;
}