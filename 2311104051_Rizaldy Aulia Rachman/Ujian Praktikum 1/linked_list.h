#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string>
using namespace std;


struct Mahasiswa {
    string name;
    string nim;  
    string class_name;  
    float assessment_score;
    float practical_score;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

struct List {
    Node* head;
};

Node* newElement(Mahasiswa data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    return new_node;
}

List createNewList() {
    List list;
    list.head = nullptr;
    return list;
}

bool isEmpty(List list) {
    return list.head == nullptr;
}

void insertFirst(List& list, Node* node) {
    node->next = list.head;
    list.head = node;
}

void insertLast(List& list, Node* node) {
    if (isEmpty(list)) {
        list.head = node;
    } else {
        Node* temp = list.head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void printList(List list) {
    if (isEmpty(list)) {
        cout << "List kosong." << endl;
        return;
    }

    Node* temp = list.head;
    while (temp != nullptr) {
        cout << "Nama: " << temp->data.name
             << ", NIM: " << temp->data.nim
             << ", Kelas: " << temp->data.class_name
             << ", Nilai Asesmen: " << temp->data.assessment_score
             << ", Nilai Praktikum: " << temp->data.practical_score
             << endl;
        temp = temp->next;
    }
}

Node* findHighestAssessment(List list) {
    if (isEmpty(list)) return nullptr;

    Node* temp = list.head;
    Node* highest = temp;
    while (temp != nullptr) {
        if (temp->data.assessment_score > highest->data.assessment_score) {
            highest = temp;
        }
        temp = temp->next;
    }
    return highest;
}

void removeDuplicates(List& list) {
    if (isEmpty(list)) return;

    Node* current = list.head;
    while (current != nullptr) {
        Node* temp = current;
        while (temp->next != nullptr) {
            if (temp->next->data.nim == current->data.nim) {
                Node* duplicate = temp->next;
                temp->next = duplicate->next;
                delete duplicate;
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

#endif