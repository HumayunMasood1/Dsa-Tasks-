#include <iostream>
using namespace std;

struct Node {
    int info;      // Data stored in node
    Node* next;    // Pointer to next node
};

class LinkedStr {
private:
    Node* ptr;     // Pointer to first node (head)

public:

    // Constructor
    LinkedStr() {
        ptr = NULL;
    }

    // Destructor
    ~LinkedStr() {
        Node* temp;
        while (ptr != NULL) {
            temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
    }

    // Create linked structure
    void makeStr(int len) {
        int value;

        for (int i = 0; i < len; i++) {
            cout << "Enter value: ";
            cin >> value;

            Node* newNode = new Node;
            newNode->info = value;
            newNode->next = NULL;

            if (ptr == NULL) {
                ptr = newNode;
            }
            else {
                Node* temp = ptr;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    }

    // Display structure
    void displayStr() {
        if (ptr == NULL) {
            cout << "Structure is empty\n";
            return;
        }

        Node* temp = ptr;

        cout << "Linked Structure: ";

        while (temp != NULL) {
            cout << temp->info << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Remove first element
    void removeFirst() {
        if (ptr == NULL)
            return;

        Node* temp = ptr;
        ptr = ptr->next;
        delete temp;
    }

    // Remove last element
    void removeLast() {

        if (ptr == NULL)
            return;

        if (ptr->next == NULL) {
            delete ptr;
            ptr = NULL;
            return;
        }

        Node* temp = ptr;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    // Remove first element with value k
    void remove(int k) {

        if (ptr == NULL)
            return;

        if (ptr->info == k) {
            Node* temp = ptr;
            ptr = ptr->next;
            delete temp;
            return;
        }

        Node* temp = ptr;

        while (temp->next != NULL && temp->next->info != k) {
            temp = temp->next;
        }

        if (temp->next == NULL)
            return;

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
};


int main() {

    LinkedStr obj;
    int n, k;

    cout << "Enter length of structure: ";
    cin >> n;

    obj.makeStr(n);

    obj.displayStr();

    cout << "\nRemoving first element...\n";
    obj.removeFirst();
    obj.displayStr();

    cout << "\nRemoving last element...\n";
    obj.removeLast();
    obj.displayStr();

    cout << "\nEnter value to remove: ";
    cin >> k;
    obj.remove(k);

    obj.displayStr();

    return 0;
}