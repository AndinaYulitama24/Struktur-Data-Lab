#include <iostream>
using namespace std;

struct Node { // Struktur Node untuk linked list
    int data;
    Node* next;
};

Node* topNode = nullptr; // Pointer ke elemen teratas stack

void push(int value) { // (menambah elemen ke stack)
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = topNode;
    topNode = newNode;
    cout << "Berhasil push: " << value << endl;
}

void pop() { // (menghapus elemen dari stack)
    if (topNode == nullptr) {
        cout << "Stack kosong! Tidak bisa pop." << endl;
        return;
    }
    Node* temp = topNode;
    int poppedValue = topNode->data;
    topNode = topNode->next;
    delete temp;
    cout << "Berhasil pop: " << poppedValue << endl;
}

bool isEmpty() { // Funsinnya untuk mengecek apakah stack kosong
    return topNode == nullptr;
}

int peek() { // Fungsinya untuk melihat elemen teratas
    if (isEmpty()) {
        cout << "Stack kosong!" << endl;
        return -1;
    }
    return topNode->data;
}

void display() { // Fungsinya untuk menampilkan isi stack
    if (isEmpty()) {
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Isi stack (dari atas ke bawah): ";
    Node* current = topNode;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void clearStack() { // Fungsinya untuk menghapus semua node (
    while (!isEmpty()) {
        pop();
    }
}

int main() {
    cout << "=== IMPLEMENTASI STACK DENGAN LINKED LIST (TANPA CLASS) ===" << endl;

    cout << "\n--- Push 3 angka ---" << endl;
    push(10);
    push(20);
    push(30);

    cout << "\nStack setelah push 3 angka:" << endl;
    display();

    cout << "\n--- Pop 1 angka ---" << endl;
    pop();

    cout << "\nStack setelah pop 1 angka:" << endl;
    display();

    cout << "\nElemen teratas (top): " << peek() << endl;

    clearStack();

    return 0;
}
