//2D Array

//#include<iostream>
//using namespace std;
//
//int main(){
//   
//   int i,j,row,col;
//   
//   cout<<"Enter Number of rows: ";
//   cin>>row;
//   
//   cout<<"Enter Number of Columns: ";
//   cin>>col;
//   
//    cout<<"Enter "<<row*col<<" Values: ";
//   
//    int arr[row][col];
//    
//    //for input
//    for(i=0;i<row;i++){
//    	for(j=0;j<col;j++){
//    		cin>>arr[i][j];
//		}
//		cout<<endl;
//	}
//   
//   //for output
//   for(i=0;i<row;i++){
//    	for(j=0;j<col;j++){
//    		cout<<arr[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//   
//
//   
//return 0;	
//}


//print 4 students roll number and marks using 2D array

#include<iostream>
using namespace std;
int main(){
  
  int i,j,row,col;
  
  cout<<"Enter Number of students (rows): ";
  cin>>row;
  
  cout<<"Enter Subjects (columns): ";
  cin>>col;
  
   cout<<"Enter "<<row*col<<" Marks: ";
   
   int students[row][col];
   
   //for input
    for(i=0;i<row;i++){
    	for(j=0;j<col;j++){
    		cin>>students[i][j];
		}
		
		cout<<endl;
	}
	
	//for output
	 for(i=0;i<row;i++){
	 	cout<<"student "<<i+1<<": ";
    	for(j=0;j<col;j++){
    		cout<<students [i][j]<<" ";
		}
		
		cout<<endl;
	}
	
  
  return 0;
}
