#include<iostream>
using namespace std;
void sort(int *a,int n)
{
	for(int g=n/2;g>0;g/=2){
		int j=0;
		for(int i=g;i<n;i++){
			int t=a[i];
			for(j=i; j>=g && a[j-g]>t ; j-=g)
			{
				a[j]=a[j-g];
			}
			a[j]=t;
		}
	}
	
}
void binsearch(int *a,int n,int x)
{
	int l=0,u=n-1,m,flag=0;
	while(l<=u)
	{
		m=(l+u)/2;
		if(x==a[m]){
			cout<<"\nFound!";
			flag=1;
			break;
		}
		else if(x>a[m])l=m+1;
		else u=m-1;
	}
	if(flag==0)cout<<"\nNot found!";
	
}
main(){
	int *a,s,item;
	cout<<"Enter size : ";
	cin>>s;
	a=new int[s];
	cout<<"enter the elements of array :\n";
	for(int i=0;i<s;i++){
		cin>>a[i];
	}
	sort(a,s);
	cout<<"\nEnter element to be searched : ";
	cin>>item;
	binsearch(a,s,item);
	
	
}
