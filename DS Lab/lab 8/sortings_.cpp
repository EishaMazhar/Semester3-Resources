//CopyRights Reserved....
#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;

 void swapXY(int & x,int & y){
	int temp = 0;
	temp = x;
	x =	y;
	y = temp;
}


int bubble_sort(int arr[],int n)
{ int swapCounter=0;
// implement algorithm



	}
	
	ofstream outFile;
	outFile.open("Bubble_sort Output.txt");
	
	for(int i=0;i<n;i++){
		outFile << arr[i] << endl;
	}
	outFile.close();
	return swapCounter;
}
int Insertion_sort(int arr[],int n)
{int swapCounter=0;
// Implement algorithm            }
            
	ofstream outFile;
	outFile.open("Insertion_sort Output.txt");
	
	for(int i=0;i<n;i++){
		outFile << arr[i] << endl;
	}
	outFile.close();
	return swapCounter;
}
int Selection_sort(int arr[], int n)
{ int swapC=0;

//implement Algorithm


	ofstream outFile;
	outFile.open("Selection_sort Output.txt");
	
	for(int i=0;i<n;i++){
		outFile << arr[i] << endl;
	}
	outFile.close();
	return swapC;
}
int main(){
	int size = 0;
	int countShaker = 0;
	double t1,t2;
	
	ifstream inFile;
	inFile.open("Unsorted Data.txt");
	inFile >> size;
	int arr [size];		// For Bubble
	int arr2[size];		// For Insertion		
	int arr3[size];		// For Selection
	
	for(int i=0;i<size;i++)
		inFile >> arr[i];
	inFile.close();
	
	for(int i=0;i<size;i++){
		arr3[i] = arr[i];
		arr2[i] = arr[i];
	}
	       cout<<endl;
		    t1 = clock();
      int B=bubble_sort(arr,size);
      cout<<"\tSwaps in Bubble Sort\t: "<<B<<endl;
        t2 = clock();
        
        cout << "\tBubble sort Time\t: " << (t2 - t1)/CLK_TCK << " 			sec\n";
cout<<endl;
	        t1 = clock();
      int I=Insertion_sort(arr,size);
      cout<<"\tSwaps in Insertion Sort\t: "<<B<<endl;
        t2 = clock();
        
        cout << "\tInsertion sort Time\t: " << (t2 - t1)/CLK_TCK << " 			sec\n";
cout<<endl;
	        t1 = clock();
      int S=Selection_sort(arr,size);
      cout<<"\tSwaps in Selection Sort\t: "<<B<<endl;
        t2 = clock();
        
        cout << "\tSelection sort Time\t: " << (t2 - t1)/ CLK_TCK<< " 			sec\n";
}


    
