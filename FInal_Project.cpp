#include <iostream>
using namespace std;

// Node class for LinkedList
class Node {
public:
    int val;     
    Node* next;    

    Node(int v) {
        val = v;
        next = NULL;  
    }
};

// LinkedList class
class LinkedList {
public:
    Node* head;   
    Node* tail;   

    LinkedList() {
        head = tail = NULL;
    }

    // Add value at the end of list
    void AddValueAtLast(int v) {
        Node* n = new Node(v);
        if(!head) {       // if list is empty
            head = tail = n;
        } else {         
            tail->next = n;
            tail = n;
        }
    }

    // Add value at specific position
    void AddValueAtRandomPosition(int v,int pos) {
        Node* n = new Node(v);
        if(!head || pos <= 1) {  // insert at head
            n->next = head;
            head = n;
            if(!tail) {
                tail = n;
            }
            return;
        } else {
            Node* temp = head;
            int count = 1;
            while(temp->next && count < pos-1) { // move to position-1
                temp = temp->next;
                count++;
            }
            n->next = temp->next;
            temp->next = n;
            if(!n->next) {   
                tail = n;
            }
        }
    }

    // Print linked list
    void print() {
        Node* temp = head;
        cout << "Linked list: ";
        while(temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Merge function for merge sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid-left+1;
    int n2 = right-mid;
    int L[n1], R[n2];

    for(int i=0; i<n1; i++) {       // copy left part
        L[i] = arr[left+i];
    }

    for(int i=0; i<n2; i++) {       // copy right part
        R[i] = arr[mid+1+i];
    }

    int i=0, j=0, k=left;

    while(i<n1 && j<n2) {           // merge two arrays
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1) { arr[k++] = L[i++]; }  // copy remaining left
    while(j<n2) { arr[k++] = R[j++]; }  // copy remaining right
}

// Merge sort function
void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right)/2;
        mergeSort(arr,left,mid);       // sort left half
        mergeSort(arr,mid+1,right);    // sort right half
        merge(arr,left,mid,right);     // merge
    }
}

// Binary search function
void Binarysearch(int arr[], int n, int key) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid] == key) {
            cout << "Found at index: " << mid << "\n";
            return;
        } else if(arr[mid] < key) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    cout << "Not found\n";
}

// Swap two numbers (used in quick sort)
void swap(int &a,int &b) {
    int t=a;
    a=b;
    b=t;
}

//   quick sort function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   
    int i = low-1;

    for(int j=low; j<high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[high]); 
    return i+1;
}

// Quick sort function
void quickSort(int arr[], int low,int high) {
    if(low < high) {
        int pi = partition(arr,low,high); // pi->partition index
        quickSort(arr,low,pi-1);          // sort left
        quickSort(arr,pi+1,high);         // sort right
    }
}

// Print array
void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    LinkedList list;
    int choice;

    do {
        cout << "1.Create LinkedList\n2.Print LinkedList\n3.Binary Search\n4.Merge Sort \n5.Quick Sort \n0.Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int n, val;
                cout << "How many numbers you want to insert? ";
                cin >> n;
                for(int i=0; i<n; i++) {
                    cout << "Enter number " << i+1 << ": ";
                    cin >> val;
                    list.AddValueAtLast(val);
                }
                break;
            }

            case 2: {
                list.print();   // display linked list
                break;
            }

            case 3: {
                int n,val,arr[100];
                cout << "Array size: "; cin >> n;
                for(int i=0; i<n; i++) {
                    cout << "Number " << i+1 << ": "; cin >> arr[i];
                }

                // sort array before binary search
                for(int i=0; i<n; i++) {
                    for(int j=i+1; j<n; j++) {
                        if(arr[i] > arr[j]) {
                            swap(arr[i],arr[j]);
                        }
                    }
                }

                cout << "Sorted array: "; printArray(arr,n);

                cout << "Enter number to find: "; cin >> val;
                Binarysearch(arr,n,val);
                break;
            }

            case 4: {
                int n, arr[100];
                cout << "Array size: "; cin >> n;
                for(int i=0; i<n; i++) {
                    cout << "Number " << i+1 << ": "; cin >> arr[i];
                }
                mergeSort(arr,0,n-1);
                printArray(arr,n);
                break;
            }

            case 5: {
                int n, arr[100];
                cout << "Array size: "; cin >> n;
                for(int i=0; i<n; i++) {
                    cout << "Number " << i+1 << ": "; cin >> arr[i];
                }
                quickSort(arr,0,n-1);
                printArray(arr,n);
                break;
            }

            case 0: {
                cout << "Program terminated successfully!\n"; 
                break;
            }

            default: {
                cout << "Invalid choice\n"; 
                break;
            }
        }
    } while(choice != 0);

    return 0;
}
