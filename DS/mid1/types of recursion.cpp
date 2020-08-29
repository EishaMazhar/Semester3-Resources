#include<iostream>
using namespace std;
void print(int n) // tail recursion
{ 
	if(n<0) return; 
	cout<<" "<< n; 
	print(n-1); 
	
} 
int fact(int n)  // non tail recursion 
{
	if(n==0||n==1)return 1;
	else
	return n*fact(n-1);
	cout<<" "<<n;
}
int fib(int n){  //Excessive recursion (Additive)
	if(n<2)return 1;
	else
		return (fib(n-1)+fib(n-2));
}

main(){
    print(5);
    cout<<endl;
    for(int i=1;i<=6;i++)
    cout<<" "<<fib(i);
    cout<<endl<<" "<<fact(4);
}
