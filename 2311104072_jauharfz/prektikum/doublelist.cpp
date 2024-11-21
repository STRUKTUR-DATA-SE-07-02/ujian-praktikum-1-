#include "doubleList.h"

address newElement(infotype data)
{
    address P = new elmList;
    P->info = data;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

List createNewList()
{
    List L;
    L.first = NULL;
    L.last = NULL;
    return L;
}

bool isEmpty(List L)
{
    return (L.first == NULL && L.last == NULL);
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

void insertAfter(List &L, infotype x, address P)
{
    if (!isEmpty(L))
    {
        address Q = L.first;
        while (Q != NULL && Q->info.nim != x.nim)
        {
            Q = Q->next;
        }
        if (Q != NULL)
        {
            P->next = Q->next;
            P->prev = Q;
            if (Q->next != NULL)
            {
                Q->next->prev = P;
            }
            else
            {
                L.last = P;
            }
            Q->next = P;
        }
    }
}

void deleteFirst(List &L, address &P)
{
    if (!isEmpty(L))
    {
        P = L.first;
        if (L.first == L.last)
        {
            L.first = NULL;
            L.last = NULL;
        }
        else
        {
            L.first = P->next;
            L.first->prev = NULL;
            P->next = NULL;
        }
    }
}

void deleteLast(List &L, address &P)
{
    if (!isEmpty(L))
    {
        P = L.last;
        if (L.first == L.last)
        {
            L.first = NULL;
            L.last = NULL;
        }
        else
        {
            L.last = P->prev;
            L.last->next = NULL;
            P->prev = NULL;
        }
    }
}

int length(List L)
{
    int count = 0;
    address P = L.first;
    while (P != NULL)
    {
        count++;
        P = P->next;
    }
    return count;
}

address findElement(List L, infotype x)
{
    address P = L.first;
    while (P != NULL)
    {
        if (P->info.nim == x.nim)
        {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void printList(List L)
{
    if (!isEmpty(L))
    {
        address P = L.first;
        while (P != NULL)
        {
            cout << "NIM: " << P->info.nim << endl;
            cout << "Nama: " << P->info.nama << endl;
            cout << "Kelas: " << P->info.kelas << endl;
            cout << "Nilai Asesmen: " << P->info.nilaiAsesmen << endl;
            cout << "Nilai Praktikum: " << P->info.nilaiPraktikum << endl;
            cout << "------------------------" << endl;
            P = P->next;
        }
    }
    else
    {
        cout << "List Kosong" << endl;
    }
}

void tambahNData(List &L, int N)
{
    for (int i = 0; i < N; i++)
    {
        infotype data;
        cout << "Data ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> data.nama;
        cout << "NIM: ";
        cin >> data.nim;
        cout << "Kelas: ";
        cin >> data.kelas;
        cout << "Nilai Asesmen: ";
        cin >> data.nilaiAsesmen;
        cout << "Nilai Praktikum: ";
        cin >> data.nilaiPraktikum;

        address P = newElement(data);
        insertLast(L, P);
    }
}

void tampilNilaiAsesmenTertinggi(List L)
{
    if (!isEmpty(L))
    {
        address P = L.first;
        address maxP = P;
        float maxNilai = P->info.nilaiAsesmen;

        while (P != NULL)
        {
            if (P->info.nilaiAsesmen > maxNilai)
            {
                maxNilai = P->info.nilaiAsesmen;
                maxP = P;
            }
            P = P->next;
        }

        cout << "Mahasiswa dengan nilai asesmen tertinggi:" << endl;
        cout << "NIM: " << maxP->info.nim << endl;
        cout << "Nama: " << maxP->info.nama << endl;
        cout << "Kelas: " << maxP->info.kelas << endl;
        cout << "Nilai Asesmen: " << maxP->info.nilaiAsesmen << endl;
        cout << "Nilai Praktikum: " << maxP->info.nilaiPraktikum << endl;
    }
}

void hapusDuplikatNIM(List &L)
{
    if (!isEmpty(L))
    {
        address P = L.first;
        while (P != NULL)
        {
            address Q = P->next;
            while (Q != NULL)
            {
                if (P->info.nim == Q->info.nim)
                {
                    if (Q == L.last)
                    {
                        L.last = Q->prev;
                        L.last->next = NULL;
                    }
                    else
                    {
                        Q->prev->next = Q->next;
                        Q->next->prev = Q->prev;
                    }
                    address temp = Q;
                    Q = Q->next;
                    delete temp;
                }
                else
                {
                    Q = Q->next;
                }
            }
            P = P->next;
        }
    }
}
