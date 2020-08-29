#include<iostream>
#include<vector>
using namespace std;
main(){
	
	int r,c,a=0;
	
	vector<vector<int> > vec;
	cout<<"Enter no of rows : ";
	cin>>r;
	int b[r];
	for(int i=0;i<r;i++)
	{
		vector<int>t;
		cout<<"Enter row size : ";cin>>c;
		b[i]=c;
		for(int j=0;j<c;j++)
		{
			cin>>a;
			t.push_back(a);
		}
		vec.push_back(t);
		
	}
	cout<<endl<<endl;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<b[i];j++)
		{
			cout<<vec[i][j]<<" ";
		}cout<<endl;
	}
}
