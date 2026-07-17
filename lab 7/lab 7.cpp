#include <iostream>
#include <climits> //INT_MAX used as infinity
using namespace std;

//struc node for linked list 
struct Node{
    char vertex; //A, B, C
    int weight; //edge value
    Node* next; //pointer to the next node
    
    Node(char v, int w){
        vertex = v;
        weight = w;
        next = nullptr; //nullptr = pointer not pointing to any object
    }
    //one connection has destination vertex and weight
};

//insert at the end func - for linked list
void insert(Node*& head, char vertex, int weight){
    Node* newNode = new Node(vertex, weight);
    //if list empty 
    if(head == nullptr){
        head = newNode;
        return;
    }
    
    //traverse to last node 
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    
    //insert new node
    temp->next = newNode;
}

//display linked list 
void display(char source, Node* head){ //source = vertex value
   cout<< source << "->";
   
   Node* temp = head;
   while(temp !=nullptr)
   {
       cout<< "("<< temp->vertex<<","<<temp->weight<<")";
       if(temp->next != nullptr){
           cout<<"->";
       }
       temp = temp->next;
   }
   cout<<endl;
}

// Convert vertex letter to array index
int getIndex(char vertex)
{
    switch(vertex)
    {
       case 'A': return 0;
       case 'B': return 1;
       case 'C': return 2;
       case 'D': return 3;
       case 'E': return 4;
       default: return -1;
    }
}

// Convert array index back to vertex letter
char getVertex(int index)
{
    return index + 'A';
}

// Find the unvisited vertex with the smallest distance
int minDistance(int dist[], bool visited[])
{
    int min = INT_MAX;
    int minIndex = -1;

    for(int i = 0; i < 5; i++)
    {
        if(!visited[i] && dist[i] < min)
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Print the shortest path recursively
void printPath(int parent[], int current)
{
    if(parent[current] == -1)
    {
        cout << getVertex(current);
        return;
    }

    printPath(parent, parent[current]);
    cout << " -> " << getVertex(current);
}
        
// Dijkstra's Algorithm
void dijkstra(Node* graph[], char startVertex)
{
    const int SIZE = 5;

    int dist[SIZE];
    bool visited[SIZE];
    int parent[SIZE];

    // Initialize arrays
    for(int i = 0; i < SIZE; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    int start = getIndex(startVertex);
    dist[start] = 0;

    // Repeat for every vertex
    for(int count = 0; count < SIZE - 1; count++)
    {
        int u = minDistance(dist, visited);

        if(u == -1)
            break;

        visited[u] = true;

        // Traverse the linked list
        Node* current = graph[u];

        while(current != nullptr)
        {
            int v = getIndex(current->vertex);
            int weight = current->weight;

            if(!visited[v] &&
               dist[u] != INT_MAX &&
               dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }

            current = current->next;
        }
    }

    // Display result
    cout << "\nShortest Distance from Vertex " << startVertex << "\n\n";

    for(int i = 0; i < SIZE; i++)
    {
        cout << "Vertex " << getVertex(i) << endl;
        cout << "Distance : " << dist[i] << endl;

        cout << "Path : ";
        printPath(parent, i);

        cout << "\n\n";
    }
}

int main(){
    //Head pointers for each vertex
    Node* graph[5];

    for(int i = 0; i < 5; i++)
    {
    graph[i] = nullptr;
    }
    
    //To build grapgh 
    
    //A head 
    //insert(head, next head, edge value)
    insert(graph[0], 'B', 4);
    insert(graph[0], 'C', 8);

    //B head
    insert(graph[1], 'A', 4);
    insert(graph[1], 'E', 6);

    //C head
    insert(graph[2], 'A', 8);
    insert(graph[2], 'D', 2);

    //D head
    insert(graph[3], 'C', 2);
    insert(graph[3], 'E', 10);

    //E head
    insert(graph[4], 'B', 6);
    insert(graph[4], 'D', 10);
    
    //display the graph
    cout<< "Adjacency List Representation\n\n";
    display('A', graph[0]);
    display('B', graph[1]);
    display('C', graph[2]);
    display('D', graph[3]);
    display('E', graph[4]);
    
    cout << "\n------------------------------------\n";
    cout << "Shortest Distance from Vertex A\n\n";

    // Call Dijkstra
    dijkstra(graph, 'A');
    
    return 0;
}