#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

class DynamicSafeArray{
	private:
		char *Data;
		int Size;
		
	public:
		DynamicSafeArray();
		DynamicSafeArray(int s);
		~DynamicSafeArray();
		void SetSize(int s);
		int GetSize();
		char* GetData();
		friend istream& operator>>(istream &file,DynamicSafeArray &rhs);
		friend void BruteMatch(DynamicSafeArray &DSA1,DynamicSafeArray &DSA2);
};

DynamicSafeArray::DynamicSafeArray():Size(0),Data(NULL){}

DynamicSafeArray::DynamicSafeArray(int s){
	Size=s;
	Data=new char[Size];
	memset(Data,0,sizeof(char)*Size);
}

void DynamicSafeArray::SetSize(int s){
	Size=s;
}

DynamicSafeArray::GetSize(){
	return Size;
}

DynamicSafeArray::~DynamicSafeArray(){
	if(Data!=0){
		delete[] Data;
		Data=NULL;
		Size=0;
	}
}
char *DynamicSafeArray::GetData(){
	return Data;
}

void BruteMatch(DynamicSafeArray &DSA1,DynamicSafeArray &DSA2){
	int i=0;
	char array[DSA1.GetSize()];
		for(int i=0;i<DSA1.GetSize();i++){
			if((DSA1.Data[i]==DSA2.Data[i]) || ( DSA2.Data[i]==0))
				array[i]=DSA1.Data[i];
				
			else{
				if((DSA1.Data[i]==DSA2.Data[i-1]) ||  (DSA2.Data[i]==DSA1.Data[i-1]))
				array[i]=DSA1.Data[i];
				
				else
					array[i]='*';
			}
		}
	while(i<DSA1.Size){
			cout<<array[i]<<" ";
			i++;
		}
}

istream& operator>>(istream &file,DynamicSafeArray &rhs){
	for(int i=0;i<rhs.GetSize();i++){
		file>>rhs.Data[i];
	}
	return (file);
}

int main(){
	int Size1,Size2;
	cout<<"Enter the size of first sequence  ";
	cin>>Size1;
	cout<<"Enter the elements of first sequence\n";
	DynamicSafeArray Obj1(Size1);
	cin>>Obj1;
	cout<<"Enter the size of second sequence  ";
	cin>>Size2;
	cout<<"Enter the elements of second sequence\n";
	DynamicSafeArray Obj2(Size2);
	cin>>Obj2;
	cout<<"Brute Match Sequence:\n";
	BruteMatch(Obj1,Obj2);
	
	return (0);
}
