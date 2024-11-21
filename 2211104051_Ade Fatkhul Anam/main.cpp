// 1. Nama: Ade Fatkhul Anam
//    NIM: 211511051
//    Kelas: SE07-02

// 2. Nomor Meja: Ganjil

    #include <iostream>
    #include <string>
    #include <stdexcept>
    using namespace std;

// 3. Lengkapi infotype pada ADT
    struct infotype {
        string namaMahasiswa;
        string NIM;
        string kelas;
        int nilaiAsesmen;
        int nilaiPraktikum;
    };

    struct Node {
        infotype info;
        Node* next;
    };

    typedef Node* address;
    struct List {
                address first;
    };

    // 4. Melengkapi Subprogram
    // Function newElement
    address newElement(infotype data) {
        address p = new Node;
        p->info = data;
        p->next = nullptr;
        return p;
    }

    // Function createNewList
    List createNewList() {
        List L;
        L.first = nullptr;
        return L;
    }

    // Function printList
    void printList(List L) {
    address p = L.first;
    while (p != nullptr) {
    cout << "Nama: " << p->info.namaMahasiswa
                        << ", NIM: " << p->info.NIM
                        << ", Kelas: " << p->info.kelas
                        << ", Nilai Asesmen: " << p->info.nilaiAsesmen
                        << ", Nilai Praktikum: " << p->info.nilaiPraktikum << endl;
                    p = p->next;
                }
            }

    // 5. Soal 
    // a. Subprogram Utama
        void insertFirst(List &L, address p) {
            p->next = L.first;
            L.first = p;
            }

        void insertLast(List &L, address p) {
            if (L.first == nullptr) {
                    L.first = p;
            } else {
                    address q = L.first;
            while (q->next != nullptr) {
                        q = q->next;
                }
                    q->next = p;
                }
            }


    // Validasi NIM sebelum di-convert menggunakan stoi
    bool isNumeric(const string &str) {
        for (char c : str) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    void tambahData(List &L, int N) {
        for (int i = 0; i < N; i++) {
            infotype data;
            cout << "Masukkan Nama: "; cin >> data.namaMahasiswa;
            cout << "Masukkan NIM: "; cin >> data.NIM;

            // Validasi input NIM
            if (!isNumeric(data.NIM)) {
                cout << "NIM tidak valid. Harus berupa angka." << endl;
                i--; // Ulangi iterasi untuk data ini
                continue;
            }

            cout << "Masukkan Kelas: "; cin >> data.kelas;
            cout << "Masukkan Nilai Asesmen: "; cin >> data.nilaiAsesmen;
            cout << "Masukkan Nilai Praktikum: "; cin >> data.nilaiPraktikum;

            address p = newElement(data);

            if (stoi(data.NIM) % 20 == 0) {
                insertLast(L, p);
            } else {
                insertFirst(L, p);
            }
        }
    }


            // b. Data mahasiswa yang memiliki asesmen paling tinggi

            infotype cariNilaiTertinggi(List L) {
                address p = L.first;
                infotype maxInfo = p->info;

                while (p != nullptr) {
                    if (p->info.nilaiAsesmen > maxInfo.nilaiAsesmen) {
                        maxInfo = p->info;
                    }
                    p = p->next;
                }

                return maxInfo;
            }

            // c. Buatlah subprogram untuk menghapus data mahasiswa yang duplikat
            void hapusDuplikat(List &L) {
            address p = L.first;
            while (p != nullptr && p->next != nullptr) {
                address q = p;
                while (q->next != nullptr) {
                    if (q->next->info.NIM == p->info.NIM) {
                        address temp = q->next;
                        q->next = q->next->next;
                        delete temp;
                    } else {
                        q = q->next;
                    }
                }
                p = p->next;
            }
        }

            // 6. Main Program
            int main() {
            List L = createNewList();

            int N;
            cout << "Masukkan jumlah data: ";
            cin >> N;

            tambahData(L, N);
            cout << "\nData Mahasiswa:\n";
            printList(L);

            infotype max = cariNilaiTertinggi(L);
            cout << "\nMahasiswa dengan nilai asesmen tertinggi:\n";
            cout << "Nama: " << max.namaMahasiswa
                << ", NIM: " << max.NIM
                << ", Nilai Asesmen: " << max.nilaiAsesmen << endl;

            hapusDuplikat(L);
            cout << "\nData setelah menghapus duplikat:\n";
            printList(L);

            return 0;
        }
