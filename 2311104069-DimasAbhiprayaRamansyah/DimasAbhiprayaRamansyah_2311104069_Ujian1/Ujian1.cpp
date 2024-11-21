//Dimas Abhipraya Ramansyah
//2311104069

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nama;
    string NIM;
    string kelas;
    float nilaiAsesmen;
    float nilaiPraktikum;
    Node* next;
};

Node* newElement(string nama, string NIM, string kelas, float nilaiAsesmen, float nilaiPraktikum) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->NIM = NIM;
    newNode->kelas = kelas;
    newNode->nilaiAsesmen = nilaiAsesmen;
    newNode->nilaiPraktikum = nilaiPraktikum;
    newNode->next = nullptr;
    return newNode;
}

Node* createNewList() {
    return nullptr;
}

bool isEmpty(Node* head) {
    return head == nullptr;
}

void insertFirst(Node*& head, Node* newNode) {
    if (isEmpty(head)) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertLast(Node*& head, Node* newNode) {
    if (isEmpty(head)) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteFirst(Node*& head) {
    if (!isEmpty(head)) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteLast(Node*& head) {
    if (!isEmpty(head)) {
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }
}

Node* findElement(Node* head, string NIM) {
    Node* current = head;
    while (current != nullptr) {
        if (current->NIM == NIM) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

int length(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << "Nama: " << current->nama << ", NIM: " << current->NIM 
             << ", Kelas: " << current->kelas 
             << ", Nilai Asesmen: " << current->nilaiAsesmen 
             << ", Nilai Praktikum: " << current->nilaiPraktikum << endl;
        current = current->next;
    }
}

int main() {
    Node* head = createNewList();

    insertLast(head, newElement("Daniel", "44326", "SE-2", 75, 80));
    insertLast(head, newElement("Kriting", "44301", "IF-1", 77, 84));
    insertFirst(head, newElement("Udin", "44319", "IF-2", 72, 79));

    cout << "Data Mahasiswa:" << endl;
    printList(head);

    string cariNIM = "44326";
    Node* found = findElement(head, cariNIM);
    if (found != nullptr) {
        cout << "Data ditemukan: " << found->nama << " dengan NIM " << found->NIM << endl;
    } else {
        cout << "Data dengan NIM " << cariNIM << " tidak ditemukan." << endl;
    }

    deleteFirst(head);
    deleteLast(head);

    cout << "Data Mahasiswa setelah penghapusan:" << endl;
    printList(head);

    return 0;
}