#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

class DynamicSafeArray{
	private:
		int *Data;
		int Size;
		
	public:
		DynamicSafeArray();
		DynamicSafeArray(int s);
		~DynamicSafeArray();
		void SetSize(int s);
		int GetSize();
		int* GetData();
		friend istream& operator>>(istream &file,DynamicSafeArray &rhs);
		friend ostream& operator<<(ostream &file,DynamicSafeArray &rhs);
		void Kquery();
};

DynamicSafeArray::DynamicSafeArray():Size(0),Data(NULL){}

DynamicSafeArray::DynamicSafeArray(int s){
	Size=s;
	Data=new int[Size];
	memset(Data,0,sizeof(int)*Size);
}

void DynamicSafeArray::SetSize(int s){
	Size=s;
}

DynamicSafeArray::~DynamicSafeArray(){
	if(Data!=0){
		delete[] Data;
		Data=NULL;
		Size=0;
	}
}
DynamicSafeArray::GetSize(){
	return Size;
}

int *DynamicSafeArray::GetData(){
	return Data;
}

ostream& operator<<(ostream &file,DynamicSafeArray &rhs){
	for(int i=0;i<rhs.GetSize();i++){
		file<<rhs.Data[i];
	}
	return (file);
}

istream& operator>>(istream &file,DynamicSafeArray &rhs){
	for(int i=0;i<rhs.GetSize();i++){
		file>>rhs.Data[i];
	}
	return (file);
}


void DynamicSafeArray::Kquery(){
	int i,j,k,n=0,x;
	cout<<"enter number of queries you want: ";
	cin>>x;
	int array[x];
	
		
	for(int c=0;c<x;c++){
		cin>>i;
		cin>>j;
		cin>>k;
		
		for(int z=i;z<=j;z++)
		{
			if(Data[z]>=k)
			{
				n++;
				
				}
				
		}
		array[c]=n;
				
	}
	for(int c=0;c<x;c++)
	{
		cout<<array[c]<<endl;
	}
}

int main(){
	cout<<"Enter the size of the array: ";
	int s;
	cin>>s;
	DynamicSafeArray DSA(s);
	cout<<"Enter the elements of array: \n";
	cin>>DSA;
	DSA.Kquery();
	return (0);
}
