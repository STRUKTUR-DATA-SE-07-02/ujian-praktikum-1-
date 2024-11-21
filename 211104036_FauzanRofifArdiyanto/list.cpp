#include "list_mahasiswa.h"

void createNewList(List &L)
{
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmpty(List L)
{
    return (L.first == nullptr && L.last == nullptr);
}

address newElement(infotype data)
{
    address P = new Elemen;
    P->info = data;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertLast(List &L, address P)
{
    if (isEmpty(L))
    {
        L.first = P;
        L.last = P;
    }
    else
    {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void printList(List L)
{
    if (isEmpty(L))
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address P = L.first;
        while (P != nullptr)
        {
            cout << "Nama: " << P->info.nama
                 << ", NIM: " << P->info.NIM
                 << ", Kelas: " << P->info.kelas
                 << ", Nilai Ujian: " << P->info.nilaiUjian
                 << ", Nilai Praktikum: " << P->info.nilaiPraktikum << endl;
            P = P->next;
        }
    }
}
    void printHighestUjian(List L)
    {
        if (isEmpty(L))
        {
            cout << "List kosong!" << endl;
            return;
        }

        address P = L.first;
        address highest = P;

        while (P != nullptr)
        {
            if (P->info.nilaiUjian > highest->info.nilaiUjian)
            {
                highest = P;
            }
            P = P->next;
        }

        cout << "Mahasiswa dengan Nilai Ujian Tertinggi:" << endl;
        cout << "Nama: " << highest->info.nama
             << ", NIM: " << highest->info.NIM
             << ", Kelas: " << highest->info.kelas
             << ", Nilai Ujian: " << highest->info.nilaiUjian
             << ", Nilai Praktikum: " << highest->info.nilaiPraktikum << endl;
    }

    void removeDuplicateNIM(List & L)
    {
        if (isEmpty(L))
        {
            return;
        }

        address P = L.first;
        while (P != nullptr)
        {
            address Q = P->next;
            while (Q != nullptr)
            {
                if (Q->info.NIM == P->info.NIM)
                {
                    address duplicate = Q;
                    if (Q->prev != nullptr)
                    {
                        Q->prev->next = Q->next;
                    }
                    if (Q->next != nullptr)
                    {
                        Q->next->prev = Q->prev;
                    }
                    if (Q == L.last)
                    {
                        L.last = Q->prev;
                    }
                    Q = Q->next;
                    delete duplicate;
                }
                else
                {
                    Q = Q->next;
                }
            }
            P = P->next;
        }
    }

