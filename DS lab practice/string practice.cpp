#include<iostream>
using namespace std;
main()
{
	int i=0,c=1;
	char *a=new char[100];
	cout<<"Input a string : ";
	cin.getline(a,100);
	while(a[i])
	{
		if(a[i]==' ')
			c++;
		i++;
	}
	cout<<c;
}
