#include<iostream>
using namespace std;
bubbleSort(int arr[],int size)
{
	int count=0;
	for(int i=0;i<size;i++)
		{
			if(arr[i] < arr[i+1])
				{
					
					count++;
				}
				
		}
	if(count== size-1)
		{
			cout<<"Already sorted list!";
		}
	else if(count<size-1)
		{
			cout<<"Sorting: ";
			cout<<"\n";
			int temp;
			
			for(int i=0;i<size;i++)
				for(int j=0;j<size;j++){
					if(arr[i] < arr[j])
					{
						temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					}
				}
			for(int i=0;i<size;i++)
				cout<<arr[i]<<" ";				
		}	
}
int main()
{
	int array[6]={1,4,2,8,3,5};
	for(int i=0;i<=5;i++)
		cout<<array[i]<<" ";
	cout<<endl;	
	bubbleSort(array,6);
}
