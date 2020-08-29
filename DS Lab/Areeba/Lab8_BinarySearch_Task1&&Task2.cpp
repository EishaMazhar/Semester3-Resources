#include<iostream>
using namespace std;
bool BinarySearch(int a[],int low,int high,int x)//t1
{
	if(low<=high)
	{
		int mid=(high+low)/2;
		if(x==a[mid])
		{
			return true;
		}
		if(x>a[mid])
		{
			return BinarySearch(a,mid++,high,x);
		}
		else
		{
			return BinarySearch(a,low,mid--,x);
		}
	}
	return false;
}
void Merge(int array1[],int array2[],int size1,int size2)//t2
{
	int i=0;
	int j=1;
	int k=0;
	int array3[size1+size2];
	while(i<size1&&j<size2)
	{
		if(array1[i]<array2[j])
		array3[k++]=array1[i++];
		else
		array3[k++]=array2[j++];
	}
	while(i<size1)
	array3[k++]=array1[i++];
	while(j<size2)
	array3[k++]=array2[j++];
	
	cout<<"After Merge Two Arrays \n";
	for(int t=0;t<size1+size2-1;t++)
	{
		cout<<array3[t]<<"\n";
	}
	int x;
	cout<<"\nEnter the Element to be searched";
	cin>>x;
	bool v=BinarySearch(array3,0,size1+size2,x);
		if(v==true)
	cout<<"\nFound";
	else
	cout<<"\nNot Found";

}
int main()
{
	int a[50];
	int b[50];
	int c[50];
	int d[50];
	for(int i=0;i<=50;i++)
	{
		b[i]=3*i+1;
		c[i]=b[i];
	}
	for(int i=1;i<=50;i++)
	{
	    a[i]=3*i;
	    d[i]=a[i];
	}
	Merge(c,d,51,51);

	return 0;
}
