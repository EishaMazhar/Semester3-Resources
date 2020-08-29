#include<iostream>
using namespace std;
swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int *a,int l,int h){
	int pivot=a[h];
	int j=(l-1);
	for(int i=l;i<h;i++){
		if(a[i]<=pivot){
			j++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[j+1],&a[h]);
	return (j+1);
	
}
Quick(int *a,int l,int h){
	if(l<h){
		int p=partition(a,l,h);//it will get the partition index
		Quick(a,l,p-1);
		Quick(a,p+1,h);
	}
}
print(int *a,int s){
	for(int i=0;i<s;i++)cout<<a[i]<<" ";
	cout<<endl<<endl;
}
main(){
	int n=6;
	int a[6]={1,10,18,0,5,7};
	cout<<"Original Array:\n";
	print(a,n);
	Quick(a,0,n-1);
	cout<<"Sorted Array:\n";
	print(a,n);
}
