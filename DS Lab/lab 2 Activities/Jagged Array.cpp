#include<iostream>
#include<cstdlib>
using namespace std;
main()
{
	//srand(5);
	int i,j,r,c;
	cout<<"Enter the no of row : ";
	cin>>r;
	
	int **a=new int*[r];
	int *b=new int[r];
	for(i=0;i<r;i++)
	{
		cout<<"enter columns in row "<<i+1<<" : ";cin>>c; //input of no of columns
		
		a[i]=new int[c]; //DMA columns
		b[i]=c;           //storing no of columns for each row in array
		for(j=0;j<c;j++) //input
		{
			//a[i][j]=rand()%10;
			cin>>a[i][j];
		}
		cout<<endl;	
	}
	
	for(i=0;i<r;i++)
	{
		{
		for(j=0;j<b[i];j++)  //it will iterate upto respective no of columns
		cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}		
}
