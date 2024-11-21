// Rengganis Tantri Pramudita
// 2311104065
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama, nim, kelas;
    float nilaiAsesmen, nilaiPraktikum;
    Mahasiswa* next;
};

class LinkedList {
private:
    Mahasiswa* head;

public:
    LinkedList() : head(nullptr) {}

    void tambahMahasiswa(string nama, string nim, string kelas, float asesmen, float praktikum) {
        Mahasiswa* baru = new Mahasiswa{nama, nim, kelas, asesmen, praktikum, nullptr};
        char lastDigit = nim.back();
        if ((lastDigit - '0') % 2 == 0) {
            if (!head) {
                head = baru;
            } else {
                Mahasiswa* temp = head;
                while (temp->next) temp = temp->next;
                temp->next = baru;
            }
        } else {
            baru->next = head;
            head = baru;
        }
    }

    void cetakList() {
        Mahasiswa* temp = head;
        while (temp) {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->nim
                 << ", Nilai Asesmen: " << temp->nilaiAsesmen << endl;
            temp = temp->next;
        }
    }

    void nilaiTertinggi() {
        if (!head) {
            cout << "List kosong.\n";
            return;
        }
        Mahasiswa* tertinggi = head;
        Mahasiswa* temp = head;
        while (temp) {
            if (temp->nilaiAsesmen > tertinggi->nilaiAsesmen)
                tertinggi = temp;
            temp = temp->next;
        }
        cout << "Nilai Tertinggi: " << tertinggi->nama << " - "
             << tertinggi->nilaiAsesmen << endl;
    }

    void hapusDuplikat() {
        Mahasiswa* current = head;

        while (current && current->next) {
            Mahasiswa* prev = current;
            Mahasiswa* temp = current->next;

            while (temp) {
                if (current->nim == temp->nim) {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                } else {
                    prev = temp;
                    temp = temp->next;
                }
            }
            current = current->next;
        }
    }
};

int main() {
    LinkedList daftar;
    int n;

    cout << "Jumlah mahasiswa: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string nama, nim, kelas;
        float asesmen, praktikum;

        cout << "Nama: "; cin >> ws; getline(cin, nama);
        cout << "Kelas: "; getline(cin, kelas);
        cout << "Nilai Asesmen: "; cin >> asesmen;
        cout << "Nilai Praktikum: "; cin >> praktikum;

        daftar.tambahMahasiswa(nama, nim, kelas, asesmen, praktikum);
    }

    cout << "\nData Mahasiswa Sebelum Hapus Duplikat:\n";
    daftar.cetakList();

    daftar.hapusDuplikat();

    cout << "\nData Mahasiswa Setelah Hapus Duplikat:\n";
    daftar.cetakList();

    cout << "\nMahasiswa dengan Nilai Asesmen Tertinggi:\n";
    daftar.nilaiTertinggi();

    return 0;
}
