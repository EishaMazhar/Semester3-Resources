#include <iostream>
#include<ctime>
#include <cstdlib> 

using namespace std ;


int binarySearch(int arr[], int start, int end, int x) 
{ 
if (end >= start) 
{ 
		int mid = start + (end - start)/2; 
		if (arr[mid] == x)
		return mid;
		if (arr[mid] > x)
		return binarySearch(arr, start, mid-1, x); 
		return binarySearch(arr, mid+1, end, x); 
} 

return -1; 
} 

int main(void) 
{ 
int arr[150]={0};

arr[0]=1;
int count=1;
for(int i=1;i<100;i++)
{   if(count%2!=0)
	arr[i]=arr[i-1]+2;
    else if(count%2==0)
	arr[i]=arr[i-1]+1;
	
	count++;
    
 } 
for(int i=0;i<100;i++)
{
	cout<<arr[i]<<endl;
 } 

int n = sizeof(arr)/ sizeof(arr[0]); 
int x = rand()%((150 - 1) + 1) + 1; 
int result = binarySearch(arr, 0, n-1, x); 
cout<<"\nRandom element: "<<x<<endl;
(result == -1)? printf("Element is not present in array") 
				: printf("Element is present at index %d", result); 
return 0; 
} 


