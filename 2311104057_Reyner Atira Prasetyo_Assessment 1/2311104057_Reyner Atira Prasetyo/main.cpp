// Reyner Atira Prasetyo
// SE0702
// 2311104057

#include <iostream>
#include "sll.cpp"

using namespace std;

int main() {
    newList L;
    int N;
    cout << "Enter number of students: ";
    cin >> N;
    L.addStudents(N);
    L.printList();
    L.printHighest();
    cout << "\n Menghapus duplikat... " << endl;
    L.deleteDuplicates();
    cout << "Setelah penghapusan duplikat: " << endl;
    L.printList();
    return 0;
}