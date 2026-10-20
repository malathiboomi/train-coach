
#include <iostream>
using namespace std;

struct Node {
    int coach;
    Node* next;
};

Node* head = nullptr;

// Add a coach at the beginning
void addBeginning(int value) {
    Node* newNode = new Node;
    newNode->coach = value;
    newNode->next = head;
    head = newNode;

    cout << "Coach added at the beginning!\n";
}

// Add a coach at the end
void addEnd(int value) {
    Node* newNode = new Node;
    newNode->coach = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Coach added at the end!\n";
}

// Remove a coach by coach number
void removeCoach(int value) {
    if (head == nullptr) {
        cout << "Train has no coaches!\n";
        return;
    }

    if (head->coach == value) {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Coach removed successfully!\n";
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr &&
           temp->next->coach != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Coach not found!\n";
    } else {
        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;

        cout << "Coach removed successfully!\n";
    }
}

// Display all coaches
void displayCoaches() {
    if (head == nullptr) {
        cout << "Train has no coaches!\n";
        return;
    }

    Node* temp = head;

    cout << "Train: ";

    while (temp != nullptr) {
        cout << "Coach" << temp->coach << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Main function
int main() {
    int choice, value;

    do {
        cout << "\n===== TRAIN COACHES =====\n";
        cout << "1. Add coach at beginning\n";
        cout << "2. Add coach at end\n";
        cout << "3. Remove a coach\n";
        cout << "4. Display all coaches\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter coach number: ";
                cin >> value;
                addBeginning(value);
                break;

            case 2:
                cout << "Enter coach number: ";
                cin >> value;
                addEnd(value);
                break;

            case 3:
                cout << "Enter coach number to remove: ";
                cin >> value;
                removeCoach(value);
                break;

            case 4:
                displayCoaches();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    // Free remaining nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
