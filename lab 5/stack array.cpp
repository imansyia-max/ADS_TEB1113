#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    string storage[100]; // Array tracking data
    int top;             // Tracking index pointer

public:
    Stack() : top(-1) {}

    void push(string element) {
        if (top >= 99) {
            cout << "Stack Overflow: Maximum threshold hit." << endl;
            return;
        }
        storage[++top] = element; // Increments top and assigns values in one step
    }

    // Streamlined pop logic
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow: No items left to remove." << endl;
            return;
        }
        cout << "\n[Popped] " << storage[top] << " has been removed from the stack." << endl;
        top--; 
    }

    void display() {
        if (top == -1) {
            cout << "The stack is empty." << endl;
            return;
        }

        cout << "--- Stack Elements (Top to Bottom) ---" << endl;
        for (int idx = top; idx >= 0; idx--) {
            cout << " [" << storage[idx] << "]" << endl;
        }
        cout << "--------------------------------------" << endl;
    }
};

int main() {
    Stack s;

    // Standard entries
    s.push("Aimar");
    s.push("Ahmad");
    s.push("Anjana");

    // Print baseline data
    cout << "Displaying initial stack setup:" << endl;
    s.display();

    // Remove latest insertion
    s.pop();

    // Print resulting dataset
    cout << "\nDisplaying updated stack setup:" << endl;
    s.display();

    return 0;
}