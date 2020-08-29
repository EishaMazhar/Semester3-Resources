#include<iostream>
#include<ctime>
using namespace std;
int start=clock();
int fib(int n){
	if(n<2)
	{
		return n;
	}
	else
		return (fib(n-2)+fib(n-1));
}
main()
{
	int x=0;
	cout<<"Enter the no of elements : ";
	cin>>x;
	for(int a=0;a<x;a++)
	{
		cout<<fib(a)<<" ";
	}
	int stop=clock();
	cout<<"\nTime : "<<(stop-start)/double(CLOCKS_PER_SEC)<<endl;
}
