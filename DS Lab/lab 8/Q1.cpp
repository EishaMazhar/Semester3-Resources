#include<iostream>
using namespace std;
class bubbleSort{
	public:
		bubbleSort(int arr[],int size){
				int temp;
				for(int i=0;i<size;i++)
					for(int j=0;j<size;j++)
					{
						if(arr[i] < arr[j])
						{
							temp = arr[i];
							arr[i] = arr[j];
							arr[j] = temp;
						}			
					}
			cout<<"Sorted List : \n";
				for(int i=0;i<size;i++)
					cout<<arr[i]<<" ";}
};
int main()
{
	int array[5] = {5,8,3,2,1};
	bubbleSort s(array,5);	
}
