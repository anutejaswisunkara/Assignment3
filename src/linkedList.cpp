#include<iostream>
using namespace std;

// Node class represents an element of a sparse matrix
class Node {
public:
    int row;    // Row index of the element
    int column; // Column index of the element
    int value;  // Value of the element
    Node* next; // Pointer to the next node in the linked list

    // Constructor to initialize a node
    Node(int r, int c, int v) : row(r), column(c), value(v), next(NULL) {}
};

// LinkedList class to represent the sparse matrix as a linked list
class LinkedList {
    Node* head; // Head pointer for the start of the linked list

public:
    // Constructor initializes the linked list as empty
    LinkedList() : head(NULL) {}

    // Method to insert a new element into the linked list
    void insert(int r, int c, int v) {
        Node* newnode = new Node(r, c, v); // Create a new node
        if (head == NULL) { // If list is empty, new node becomes head
            head = newnode;
        } else { // Else, append it to the end of the list
            Node* temp = head;
            while (temp->next != NULL) { // Traverse to the end of the list
                temp = temp->next;
            }
            temp->next = newnode; // Link new node at the end
        }
    }

    // Method to print all elements of the linked list
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "Row " << temp->row << " Column " << temp->column << " Value " << temp->value;
            if (temp->next != NULL)
                cout << " Next node " << "(" << temp->next->row << ", " << temp->next->column << ", " << temp->next->value << ")";
            else
                cout << " Next node NULL";
            cout << endl;
            temp = temp->next; // Move to the next node
        }
    }
};

int main() {
    int m, n;
    cout << "Enter matrix dimensions ";
    cin >> m >> n;

    int mat[m][n]; // 2D array to store the matrix elements
    cout << "Enter matrix elements" << endl;

    LinkedList linkedList; // Creating an instance of LinkedList

    // Reading matrix elements and inserting non-zero elements into the linked list
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            if (mat[i][j] != 0) {
            	linkedList.insert(i, j, mat[i][j]); // Inserting non-zero elements
            }
        }
    }

    // Displaying the sparse matrix representation
    linkedList.printList();
}
