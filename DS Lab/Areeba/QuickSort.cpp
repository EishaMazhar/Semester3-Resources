#include<iostream>
using namespace std;

void Exchange(int*,int*);

int Partition(int data[],int Low,int high)
{
	int Piv=data[high];
	int i=Low-1;
	int static count=0;
    for(int j=Low;j<high;j++)
    {
    	if(data[j]<=Piv)
    	{
    		cout<<"\nComparison Count_Num ="<<++count<<" For Best Sorted Case :";
    		i++;
    		Exchange(&data[i],&data[j]);
		}
	}
	Exchange(&data[i+1],&data[high]);
	return (i+1);
}
void Exchange(int *ptr1,int *ptr2)
{
	int temp=*ptr1;
	*ptr1=*ptr2;
	*ptr2=temp;
}
void QuickSort(int data[],int Low,int high)
{
	if(high>Low)
	{
		
		int Piv=Partition(data,Low,high);
		QuickSort(data,Low,Piv-1);
		QuickSort(data,Piv+1,high);
	}
}
//For UnSorted Array Reverse Order_Worst_Case
void Exchange2(int*,int*);
int Partition2(int data[],int Low,int high)
{
	int Piv=data[high];
	int i=Low-1;
	int static count=0;
    for(int j=Low;j<high;j++)
    {
    	if(data[j]>=Piv)
    	{
    		cout<<"\nComparison Count_Num ="<<++count<<" For UnSorted(Worst_Case)";
    		i++;
    		Exchange2(&data[i],&data[j]);
		}
	}
	Exchange2(&data[i+1],&data[high]);
	return (i+1);
}
void Exchange2(int *ptr1,int *ptr2)
{
	int temp=*ptr1;
	*ptr1=*ptr2;
	*ptr2=temp;
}
void QuickSort2(int data[],int Low,int high)
{
	if(high>Low)
	{
		
		int Piv=Partition2(data,Low,high);
		QuickSort2(data,Low,Piv-1);
		QuickSort2(data,Piv+1,high);
	}
}
void Print(int array[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<"\n"<<array[i];
	}
}
int main()
{
	int size;
	cout<<"Enter the Size of Array \n";
	cin>>size;
	int array[size];
	cout<<"Enter "<<size<<" Elements/Element\n";
	for(int i=0;i<size;i++)
	{
		cin>>array[i];
	}
	cout<<"Given Array Is\n";
	Print(array,size);
	int choice;
	cout<<"\nEnter Your CHoice\n1.NumberOFComparisonFor SortedArray(BeSt_Case)\n2.NumberOfComparisonFOr UnSortedArray(Worst_Case)\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			QuickSort(array,0,size-1);
			cout<<"\n\nSorted Array(BeSt_Case) Is";
				Print(array,size);
			break;
		case 2:
			QuickSort2(array,0,size-1);
			cout<<"\n\nUnSorted Array(Worst_Case) Is";
				Print(array,size);
			break;
		default:
			cout<<"\nPlease Enter the Above Given Number";
			break;
	}
}
