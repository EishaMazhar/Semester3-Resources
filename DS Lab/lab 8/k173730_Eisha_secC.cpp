/*Safia Baloch: FAST-NUCES*/ 
//sorting Algorithms; Eisha ; 17k-3730 ; Sec C

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


int bubble_sort(int arr[],int n){
int swapCounter=0;

for(int i=1;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(arr[j]>arr[j+1])
			swapXY(arr[j],arr[j+1]);
			swapCounter++;
	}
	ofstream outFile;
	outFile.open("Bubble_sort Output.txt");
	
	for(int i=0;i<n;i++){
		outFile << arr[i] << endl;
	}
	outFile.close();
	return swapCounter;
}
int Insertion_sort(int arr[],int n){
int temp;
int swapCounter=0;
for(int i=1;i<n;i++){
	temp=arr[i];
	int j=i-1;
	while(j>=0 && arr[j]>temp){
		arr[j+1]=arr[j];
		j--;
		swapCounter++;
	}
	arr[j+1]=temp;
}
            
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
	for(int i=1;i<n;i++){
		int temp=i;
		for(int j=i+1;j<n;j++){
			if(arr[temp]>arr[j])
				swapXY(arr[temp],arr[j]);
		}
	}



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
      int I=Insertion_sort(arr2,size);
      cout<<"\tSwaps in Insertion Sort\t: "<<I<<endl;
        t2 = clock();
        
        cout << "\tInsertion sort Time\t: " << (t2 - t1)/CLK_TCK << " 			sec\n";
cout<<endl;
	        t1 = clock();
      int S=Selection_sort(arr3,size);
      cout<<"\tSwaps in Selection Sort\t: "<<S<<endl;
        t2 = clock();
        
        cout << "\tSelection sort Time\t: " << (t2 - t1)/ CLK_TCK<< " 			sec\n";
}


    

