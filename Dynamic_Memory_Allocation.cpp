#include <iostream>
using namespace std;


class Node {
public:
    int data;      // value of node
    Node* next;    // pointer to next node

    // constructor
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Linked List class
class LinkedList {
public:
    Node* head;   // first node
    Node* tail;   // last node

    // constructor 
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    // insert value at first
    void insertFirst(int num) {
        Node* newNode = new Node(num);

        if (head != NULL) {       // if list not empty
            newNode->next = head;
            head = newNode;
        } else {                  // if list empty
            head = newNode;
            tail = newNode;
        }
    }

    // delete a node 
    void deleteNode(int num) {
        if (head == NULL) {  
            cout << "List is empty, nothing to delete."<<endl;
            return;
        }

        
        if (head->data == num) {
            Node* temp = head;
            head = head->next;
            delete temp;

            if (head == NULL) tail = NULL; // list became empty
            return;
        }

        
        Node* current = head;
        while (current->next != NULL && current->next->data != num) {
            current = current->next;
        }

        // value not found
        if (current->next == NULL) {
            cout << "Value " << num << " not found in list."<<endl;
            return;
        }

        // delete node
        Node* temp = current->next;
        current->next = current->next->next;

        if (temp == tail) {
            tail = current;   
        }
        delete temp;
    }

    // search a value in list
    bool searchNode(int num) {
        Node* temp = head;
        int pos = 1;   // position start from 1

        while (temp != NULL) {
            if (temp->data == num) {
                cout << "Value " << num << " found at position "<<pos<<endl;
                return true;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Value "<<num<<" not found in list."<<endl;
        return false;
    }

    // reverse the list
    void reverseList() {
        Node* prev = NULL;
        Node* current = head;
        Node* nextNode = NULL;

        while (current != NULL) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head=prev;

     
        tail = head;
        while (tail && tail->next != NULL) {
            tail = tail->next;
        }

        cout<<"List reversed!" << endl;
    }

    // print all values
    void printList() {
        if (head == NULL) {
            cout<<"List is empty."<<endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

// main function
int main() {
    LinkedList list;   // object of LinkedList
    int choice, num;

    do {
        cout << "\n--- Menu ---" <<endl;
        cout << "press 1 for Insert at first"<<endl;
        cout << "press 2 for Search a node"<<endl;
        cout << "press 3 for Delete a node"<<endl;
        cout << "press 4 for Reverse the list"<<endl;
        cout << "press 5 for Display the list"<<endl;
        cout << "press 0 for Exit"<<endl;
        cout << "Enter your choice: ";
        cin  >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> num;
            list.insertFirst(num);
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> num;
            if (list.searchNode(num))
                cout << "Node found!"<<endl;
            else
                cout << "Node not found!"<<endl;
            break;

        case 3:
            cout<<"Enter value to delete: ";
            cin >> num;
            list.deleteNode(num);
            break;

        case 4:
            list.reverseList();
            break;

        case 5:
            cout<<"Linked List: ";
            list.printList();
            break;

        case 0:
            cout <<"Program ended successfully!"<<endl;
            break;

        default:
            cout <<"Invalid choice, try again."<<endl;
        }

    } while (choice != 0);

    return 0;
    };
