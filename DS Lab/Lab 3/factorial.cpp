#include<iostream>
using namespace std;
int fact(int n)
{
	if(n<=1)
	{
		return n;
	}
	else
	{	
		return n*fact(n-1);	
	}
	
}
main(){
	int i;
	cout<<"enter the no :";
	cin>>i;
	cout<<fact(i);
}
