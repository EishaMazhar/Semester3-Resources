#include<iostream>
using namespace std;
swap(int* a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
main(){
	int n,i,j,flag;
	int *a=new int[20];
	cout<<"Enter the no of elements of your array : ";
	cin>>n;
	
	for(i=0;i<n;i++)cin>>*(a+i); //input
		
	for(i=0;i<n-1;i++){
		flag=0;
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
				flag=1;
			}
		}if (flag==0)break;
	}
	
	for(i=0;i<n;i++)cout<<*(a+i)<<" "; //output
	delete[] a;
}

