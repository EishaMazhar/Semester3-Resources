#include<iostream>
using namespace std;
int getMax(int *a,int n){
	int m=a[0],mI=0;
	for(int i=1;i<n;i++){
		if(m<a[i])
		{
			m=a[i];
			mI=i;
		}
	}
	return mI;
}
sort(int *a,int n){
	int max,t;
	if(n>1){
		max=getMax(a,n);
		t=a[n-1];
		a[n-1]=a[max];
		a[max]=t;
		sort(a,n-1);
	}	
}
main(){
	int *a =new int[20];
	int n,i,j;
	
	cout<<"Enter no of elements :";cin>>n;
	
	cout<<"\nEnter the elements of array : \n";
	for(i=0;i<n;i++)cin>>*(a+i);
	
	sort (a,n);
	
	for(i=0;i<n;i++)cout<<*(a+i)<<" ";
	delete a;
}
