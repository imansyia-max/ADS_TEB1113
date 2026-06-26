#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next = NULL;

    // Constructor to quickly initialize a node
    Node(string val) {
        name = val;
        next = NULL;
    }
};

// --- 1. DISPLAY LIST ---
void display_list(Node* head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->name << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// --- 2. INSERTION (At the End) ---
void insert_at_end(Node*& head, string name) {
    Node* newNode = new Node(name);
    
    // If list is empty, new node becomes head
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    // Otherwise, traverse to the last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// --- 3. DELETION (By Value/Name) ---
void delete_by_name(Node*& head, string targetName) {
    if (head == NULL) {
        cout << "List is empty, cannot delete." << endl;
        return;
    }

    // Case 1: The node to delete is the head node
    if (head->name == targetName) {
        Node* temp = head;
        head = head->next; // Move head to the next node
        delete temp;       // Free the old head memory
        return;
    }

    // Case 2: The node is somewhere down the line
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL && current->name != targetName) {
        previous = current;
        current = current->next;
    }

    // If the name wasn't found in the list
    if (current == NULL) {
        cout << "Node with name '" << targetName << "' not found." << endl;
        return;
    }

    // Unlink the node and free memory
    previous->next = current->next;
    delete current;
}

int main() {
    // Initialize an empty list
    Node* head = NULL;

    // Testing dynamic insertion
    cout << "--- Inserting Nodes ---" << endl;
    insert_at_end(head, "Aiman");
    insert_at_end(head, "Ahmad");
    insert_at_end(head, "Anjana");
    insert_at_end(head, "Jessy");

    // Displaying the list
    display_list(head);
    cout << endl;

    // Testing deletion of a middle/end node
    cout << "--- Deleting 'Anjana' ---" << endl;
    delete_by_name(head, "Anjana");
    display_list(head);
    cout << endl;

    // Testing deletion of the head node
    cout << "--- Deleting 'Aiman' (Head Node) ---" << endl;
    delete_by_name(head, "Aiman");
    display_list(head);
    cout << endl;

    // Cleanup: Memory deallocation when program ends
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}