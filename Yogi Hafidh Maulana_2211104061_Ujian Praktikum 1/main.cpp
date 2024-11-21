#include <iostream>
#include <string>

using namespace std;

struct infotype
{
    string name;
    string nim;
    string class_name;
    float assessment_score;
    float practical_score;
};

typedef infotype dataType;

struct Node
{
    infotype data;
    Node *next;
};

typedef Node *address;
typedef address List;

// Function mengembalikan alamat elemen list hasil alokasi, info berisi data dari masukan
address newElement(dataType data)
{
    address new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    return new_node;
}

// Function untuk mengembalikan sebuah list kosong
List createNewList()
{
    return nullptr;
}

// Function untuk mengembalikan true apabila list a kosong, atau false apabila sebaliknya
bool isEmpty(List a)
{
    return (a == nullptr);
}

// Insert element baru pada posisi awal list
void insertFirst(List &a, address p)
{
    p->next = a;
    a = p;
}

// Insert element baru pada posisi tertentu list
void insertAfter(List &a, dataType x, address p)
{
    if (isEmpty(a))
    {
        cout << "List kosong, tidak dapat insert after!" << endl;
        return;
    }

    address temp = a;
    while (temp != nullptr)
    {
        if (temp->data.nim == x.nim)
        {
            p->next = temp->next;
            temp->next = p;
            return;
        }
        temp = temp->next;
    }

    cout << "Element dengan NIM " << x.nim << " tidak ditemukan!" << endl;
}

// Insert element baru pada posisi akhir list
void insertLast(List &a, address p)
{
    if (isEmpty(a))
    {
        insertFirst(a, p);
    }
    else
    {
        address temp = a;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}

// Delete element pertama dari list
void deleteFirst(List &a, address &p)
{
    if (!isEmpty(a))
    {
        p = a;
        a = a->next;
        p->next = nullptr;
    }
}

// Delete element terakhir dari list
void deleteLast(List &a, address &p)
{
    if (!isEmpty(a))
    {
        address temp = a;
        address prev = nullptr;
        while (temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev != nullptr)
        {
            prev->next = nullptr;
        }
        else
        {
            a = nullptr;
        }
        p = temp;
    }
}

// Function untuk menemukan element pada list
address findElement(List a, dataType x)
{
    address temp = a;
    while (temp != nullptr)
    {
        if (temp->data.nim == x.nim)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// Function untuk menemukan mahasiswa dengan score tertinggi pada assesment
address findHighestAssessment(List a)
{
    if (isEmpty(a))
        return nullptr;

    address highest = a;
    address temp = a->next;
    while (temp != nullptr)
    {
        if (temp->data.assessment_score > highest->data.assessment_score)
        {
            highest = temp;
        }
        temp = temp->next;
    }
    return highest;
}

// Delete mahasiswa dengan duplikat NIM
void deleteDuplicate(List &a)
{
    address current = a;
    address prev = nullptr;
    while (current != nullptr)
    {
        address runner = current;
        while (runner->next != nullptr)
        {
            if (current->data.nim == runner->next->data.nim)
            {
                address duplicate = runner->next;
                runner->next = duplicate->next;
                delete duplicate;
            }
            else
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

// Function untuk menampilkan semua element pada list
void printList(List a)
{
    address temp = a;
    while (temp != nullptr)
    {
        cout << "Name: " << temp->data.name << ", NIM: " << temp->data.nim
             << ", Class: " << temp->data.class_name
             << ", Assessment Score: " << temp->data.assessment_score
             << ", Practical Score: " << temp->data.practical_score << endl;
        temp = temp->next;
    }
}

// Function untuk insert data berdasarkan NIM(odd = InsertFirst, even = InsertLast)
void insertData(List &a, dataType data)
{
    address newNode = newElement(data);
    if (stoi(data.nim) % 2 == 0)
    {
        insertLast(a, newNode);
    }
    else
    {
        insertFirst(a, newNode);
    }
}

int main()
{
    List studentList = createNewList();
    dataType student1 = {"Yogi", "061", "A1", 88.5, 90.0};
    dataType student2 = {"Aji", "032", "A2", 92.0, 89.5};
    dataType student3 = {"Bahar", "032", "B1", 95.5, 91.0};

    // Insert data
    insertData(studentList, student1);
    insertData(studentList, student2);
    insertData(studentList, student3);

    // Print list
    cout << "List Mahasiswa:" << endl;
    printList(studentList);

    // Find dan print mahasiswa dengan score tertinggi
    address highest = findHighestAssessment(studentList);
    if (highest != nullptr)
    {
        cout << "Nilai Assessment tertinggi: " << highest->data.name
             << " dengan " << highest->data.assessment_score << endl;
    }

    // Remove duplicate
    deleteDuplicate(studentList);
    cout << "Setelah menghapus duplikast:" << endl;
    printList(studentList);

    return 0;
}

// Yogi Hafidh Maulana
// 2211104061
// SE06-02