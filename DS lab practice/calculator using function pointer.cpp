#include<iostream>
using namespace std;
float add(void){
	float a,b;
	cout<<"a : ";
	cin>>a;
	cout<<"b : ";
	cin>>b;
	float sum=a+b;
	return sum;
}
float subtract(void){
	float a,b;
	cout<<"a : ";
	cin>>a;
	cout<<"b : ";
	cin>>b;
	float diff=a-b;
	return diff;
}
float multiply(void){
	float a,b;
	cout<<"a : ";
	cin>>a;
	cout<<"b : ";
	cin>>b;
	float pr=a*b;
	return pr;
}
float divide(void){
	float a,b;
	cout<<"numerator : ";
	cin>>a;
	cout<<"denominator : ";
	cin>>b;
	float div=a/b;
	return div;
}
float fact(void){
	int a,fac=1;cout<<"enter no : ";
	cin>>a;
	for(int i=1;i<=a;i++)
		fac=fac*i;
	return fac;
}
main(){
	int n,flag=0;
	float (*p)();
	cout<<"\n\tCalculator ! ";
	while(flag!=1){
		cout<<"\n\nChoose the operation\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Find factorial\n6.Exit\n\n";
		cin>>n;
	switch(n){
		case 1:
			{
				p=add;
				cout<<p();
				break;
			}
		case 2:
			{
				p=subtract;
				cout<<p();
				break;
			}
		case 3:
			{
				p=multiply;
				cout<<p();
				break;
			}
		case 4:
			{
				p=divide;
				cout<<p();
				break;
			}
		case 5:
			{
				p=fact;
				cout<<p();
				break;
			}
		case 6:
			{
				flag=1;
				break;
			}		
		default:
			{
				cout<<"invalid input";		
			}
	}
	
	}
}
