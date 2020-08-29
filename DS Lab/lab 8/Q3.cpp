#include<iostream>
using namespace std;
int main()
{
	char arr[5] = {'e','d','c','b','a'};
	char temp;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++){
				if(arr[i] < arr[j])
					{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
	
		cout<<"Sorted Array: ";
			for(int i=0;i<5;i++)
			cout<<arr[i]<<" ";
	cout<<endl<<"Therefore,\n";
	for(int i=0;i<5;i++)
		{
			cout<<arr[i]<<" < ";
		}
		cout<<"None";
	
}
