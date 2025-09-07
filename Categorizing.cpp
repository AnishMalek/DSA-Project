#include <iostream>
using namespace std;

// Merge two sorted parts of array
void merge(int arr[], int low, int mid, int high) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    int leftPart[leftSize], rightPart[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftPart[i] = arr[low + i];
    for (int j = 0; j < rightSize; j++)
        rightPart[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    // Merge left and right parts
    while (i < leftSize && j < rightSize) {
        if (leftPart[i] <= rightPart[j]) arr[k++] = leftPart[i++];
        else arr[k++] = rightPart[j++];
    }

    while (i < leftSize) arr[k++] = leftPart[i++];
    while (j < rightSize) arr[k++] = rightPart[j++];
}

// Recursive merge sort
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;  // calculate mid
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Linear search in array
void search(int arr[], int n, int key) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index: " << i << endl;
            found++;
        }
    }
    if (!found) {   	
	cout << "Element not found in the array" << endl;
}
}

// Binary search in sorted array
void Binarysearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;  // calculate mid
        if (arr[mid] == key) {
            cout << "Element found at index: " << mid << endl;
            return;
        } else if (arr[mid] < key) {
        	 low = mid + 1;
		}
        else {
        	high = mid - 1;
		}
		
    }
    cout << "Element not found in the array" << endl;
}

// bubble sort function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
            	swap(arr[i], arr[j]);
			}
        }
    }
}

int main() {
    int choice;
    do {
        cout << "\n---- MENU ----\n";
        cout << "1. Selection Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n, arr[100];
                cout << "Enter number of elements: ";
                cin >> n;
                cout << "Enter " << n << " values: ";
                for (int i = 0; i < n; i++) {
                	cin >> arr[i];
				}

                bubbleSort(arr, n);  // sort array

                cout << "Sorted array: ";
                for (int i = 0; i < n; i++) {
                	cout << arr[i] << " ";
				}
                cout << endl;
                break;
            }
            case 2: {
                int n, arr[100];
                cout << "Enter number of elements: ";
                cin >> n;
                cout << "Enter " << n << " values: ";
                for (int i = 0; i < n; i++) {
                	cin >> arr[i];
				}

                mergeSort(arr, 0, n - 1);  // sort using merge sort

                cout << "Array after merge sort: ";
                for (int i = 0; i < n; i++) {
                	cout << arr[i] << " ";
				}
                cout << endl;
                break;
            }
            case 3: {
                int n, key, arr[100];
                cout << "Enter number of elements: ";
                cin >> n;
                cout << "Enter " << n << " values: ";
                for (int i = 0; i < n; i++) cin >> arr[i];
                cout << "Enter element to search: ";
                cin >> key;
                search(arr, n, key);
                break;
            }
            case 4: {
                int n, key, arr[100];
                cout << "Enter number of elements: ";
                cin >> n;
                cout << "Enter " << n << " values: ";
                for (int i = 0; i < n; i++) {
                	cin >> arr[i];
				}

                bubbleSort(arr, n);  // sort before binary search

                cout << "Sorted array: ";
                for (int i = 0; i < n; i++) {
                	cout << arr[i] << " ";
				}
                cout << endl;

                cout << "Enter element to search: ";
                cin >> key;
                Binarysearch(arr, n, key);
                break;
            }
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
