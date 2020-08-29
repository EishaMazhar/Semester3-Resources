#include<iostream>
#include<string>
using namespace std;
main(){
	char *a=new char[20];
	char *b=new char[20];
	int i=0,c=0,j,flag=1;
	cout<<"Enter a word : ";
	cin.getline(a,20);
	while(*(a+i)!='\0')i++;
	
	c=i;
	for(j=c-1,i=0;j>=0 && i<c ;j--,i++)*(b+i)=*(a+j);
	
	i=0;
	while(*(b+i)!='\0'&& *(a+i)!='\0')
	{
			if(*(a+i)!=*(b+i)){
				flag=0;
				break;
			}
			else if(*(a+i)==*(b+i))
				i++;
	}
	if(flag==0)
	cout<<"\nnot palindrome! ";
	else
	  cout<<"\npalindrome! ";	  
	delete a,b;
}

