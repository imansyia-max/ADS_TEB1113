#include <iostream>
#include <string>

using namespace std;

class Queue {
private:
    string arr[100]; 
    int front;
    int rear;

public:
    Queue() : front(0), rear(0) {}

    void enqueue(string value) {
        if (rear == 100) {
            cout << "Queue Overflow: Cannot add more entries." << endl;
            return;
        }

        if (front == 0) {
            front = 1;
        }

        rear++;
        dataset[rear] = value;
    }

    void dequeue() {
        if (front == 0) {
            cout << "Queue Underflow: Structure is completely empty." << endl;
            return;
        }

        cout << "\n[Ejected] " << dataset[front] << " has been processed." << endl;
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (front == 0) {
            cout << "The queue is currently empty." << endl;
            return;
        }

        cout << "<<<<< Current Lineup (Front to Rear) <<<<<" << endl;
        for (int idx = front; idx <= rear; idx++) {
            cout << "Slot [" << idx << "]: " << dataset[idx] << endl;
        }
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    }
};

int main() {
    Queue customerLine;

    customerLine.enqueue("Aimar");
    customerLine.enqueue("Ahmad");
    customerLine.enqueue("Anjana");

    cout << "Initial execution state:" << endl;
    customerLine.display();

    customerLine.dequeue();

    cout << "\nPost-removal execution state:" << endl;
    customerLine.display();

    return 0;
}