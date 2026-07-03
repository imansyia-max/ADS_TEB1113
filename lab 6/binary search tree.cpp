#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};
int main(){
    Node*node1 = new Node();
    Node*node2 = new Node();
    Node*node3 = new Node();
    Node*node4 = new Node();

    //Add value
    node1->data = 20;
    node2->data = 40;
    node3->data = 60;
    node4->data = 80;

    //Connect with left and right poiters
    node1->left = node2;
    node1->right = node3;
    
    node2->left = node4;
    node2->right = NULL;

    node3->left = NULL;
    node3->right = NULL;

    node4->left = NULL;
    node4->right = NULL;

    //Display
    cout<<"Binary Tree"<<endl;
    cout<<"Root Node: "<<node1->data<<endl;
    cout<<"Left Child: "<<node1->left->data<<endl;
    cout<<"Right Child: "<<node1->right->data<<endl;
    cout<<"Left Child of "<<node2->data<<" : "<<node2->left->data<<endl;

    return 0;
}