#include<iostream>
#include <stack> 
using namespace std;

int main() {
    
    stack <int> values;   // stack declaration
     
    int size, i, v, choice;
    
    do {
        cout<<endl;
        
        // Menu options
        cout<<"Press 1 for Push an Element"<<endl;
        cout<<"Press 2 for Pop an Element"<<endl;
        cout<<"Press 3 for Display the Top Element"<<endl;
        cout<<"Press 4 for Check if Stack is Empty or Not"<<endl;
        cout<<"Press 5 for Check if the Stack is Full or Not"<<endl;
        cout<<"Press 0 to Exit"<<endl;
        
        cout<<"Please Enter your Choice: ";
        cin>>choice;
     
        switch(choice) {
            case 1:
                cout<<"Enter size of stack you want to enter: ";
                cin>>size;
     
                for(i=0; i<size; i++) {
                    cout<<"Enter "<<i+1<<" value: ";
                    cin>>v;
                    values.push(v);   // pushing values into stack
                }
                break;
                
                
         
            case 2:
                if(values.empty()) {
                    cout<<"Stack is Empty"<<endl;
                } else {
                    cout<<values.top() << " popped from stack"<<endl;
                    values.pop();  // popping element
                }
                break;
          
            case 3:
                if(values.empty()) {
                    cout<<"Stack is Empty!" <<endl;
                } else {
                    cout<<"Top element is " << values.top()<<endl;
                }
                break;
         
            case 4:
                if(values.empty()) {
                    cout<<"Stack is Empty!" <<endl;
                } else {
                    cout<<"Stack is NOT Empty" <<endl;
                }
                break;
         
            case 5:
                if(!values.empty()) {
                    cout<<"Stack is Full!" <<endl;  
                } else {
                    cout<<"Stack is NOT Full" <<endl;
                }
                break;
        }
     
    } while(choice != 0);
    cout<<endl;
     
    // Display remaining elements in stack 
    cout << "The remaining elements in the stack are: ";
    while(!values.empty()) {
        cout<<values.top() << " ";
        values.pop();
    }
    cout<<endl;
    cout<<"\nprogram has been terminated successfully!";
    cout<<endl;
    
    return 0;
}
