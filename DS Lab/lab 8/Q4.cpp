#include<iostream>
using namespace std;
int main()
{
	int arr[5] = {4,5,1,3,2};
	int temp,chg=0;
	cout<<"Array before sort : \n";
	for(int i=0;i<5;i++)
		cout<<arr[i]<<" ";
	
	for(int i=chg;i<5;i++)
		{
			for(int j=chg;j<5;j++)
				{
					if(arr[i] < arr[j])
						{
							temp=arr[i];
							arr[i]=arr[j];
							arr[j]=temp;
						}
				}chg++;	
		}
	cout<<"\n\nDescending order: \n";
	for(int i=0;i<5;i++)
		cout<<arr[i]<<" ";
	
}
