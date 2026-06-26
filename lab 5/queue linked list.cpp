#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string identity;
    Node* nextNode;

    Node(string label) : identity(label), nextNode(nullptr) {}
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(string incomingName) {
        Node* freshNode = new Node(incomingName);

        if (rear == nullptr) {
            front = rear = freshNode;
            return;
        }

        rear->nextNode = freshNode;
        rear = freshNode;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Notice: Cannot dequeue from an empty lineup." << endl;
            return;
        }

        Node* target = front;
        front = front->nextNode;

        cout << "\n[Processed] '" << target->identity << "' has left the queue." << endl;
        delete target;

        // Reset rear pointer if the final item was just removed
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // Revamped display logic
    void display() {
        Node* iterator = front;

        if (iterator == nullptr) {
            cout << "The lineup is currently empty." << endl;
            return;
        }

        cout << "=== Lineup Flow (Front -> Rear) ===" << endl;
        while (iterator != nullptr) {
            cout << "[ " << iterator->identity << " ]";
            if (iterator->nextNode != nullptr) {
                cout << " -> ";
            }
            iterator = iterator->nextNode;
        }
        cout << "\n===================================" << endl;
    }
};

int main() {
    Queue line;

    // Populating the queue
    line.enqueue("Aimar");
    line.enqueue("Ahmad");
    line.enqueue("Anjana");

    // Outputting initial state
    cout << "Initial roster state:" << endl;
    line.display();

    // Advancing the queue
    line.dequeue();

    // Outputting modified state
    cout << "\nUpdated roster state:" << endl;
    line.display();

    return 0;
}