#include <iostream>
#include <string>

using namespace std;

class Element {
public:
    string payload;
    Element* nextAddress;

    Element(string val) : payload(val), nextAddress(nullptr) {}
};

class StudentStack {
private:
    Element* top; 

public:
    StudentStack() : top(nullptr) {}

    void insertElement(string value) {
        Element* newElement = new Element(value);
        newElement->nextAddress = top;
        top = newElement;
    }

    // Re-written pop operation with an added safety check
    void removeElement() {
        if (top == nullptr) {
            cout << "Operation failed: The stack is currently empty." << endl;
            return; // Prevents the program from crashing if called on an empty stack
        }

        Element* temp = top;
        top = top->nextAddress;

        cout << "\n[Log] '" << temp->payload << "' has been removed." << endl;
        delete temp;
    }

    // Re-written display operation
    void printStack() {
        Element* current = top;

        if (current == nullptr) {
            cout << "The stack is empty." << endl;
            return;
        }

        cout << "--- Current Stack Hierarchy (Top to Bottom) ---" << endl;
        while (current != nullptr) {
            cout << "-> " << current->payload << endl;
            current = current->nextAddress;
        }
        cout << "-----------------------------------------------" << endl;
    }
};

int main() {
    StudentStack records;

    // Inserting data
    records.insertElement("Anjana");
    records.insertElement("Ahmad");
    records.insertElement("Aimar");

    // Displaying initial stack
    records.printStack();

    // Removing the top element
    records.removeElement();

    // Displaying stack after removal
    cout << "\nUpdated stack status:" << endl;
    records.printStack();

    return 0;
}