#include<iostream>

using namespace std;

void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i];        
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
}
void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		int m = l+(r-l)/2; //same as (l-r)/2
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 
		merge(arr, l, m, r); 
	} 
}
void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		cout<<A[i]<<" "; 
	cout<<"\n"; 
}
int main() 
{ 
	int arr[6] = {12, 11, 13, 5, 6, 7}; 
	cout<<"Given array is \n"; 
	printArray(arr,6); 
	mergeSort(arr,0,6-1); 
	cout<<"\nSorted array is \n"; 
	printArray(arr,6); 
	return 0; 
	
/*	int arr[] = {12, 11, 13, 5, 6, 7}; 
	int arr_size = sizeof(arr)/sizeof(arr[0]);     //segment to be tested 
	*/
} 

