#include<bits/stdc++.h>
#include<ctime>
#include<fstream>
using namespace std;
bool LinSrch(int a[],int nArr,int srch)
{
	int low=0,high=nArr-1;
	while(low<=high)
	{
		if(srch==a[low])
		{
			return true;
		}
		low++;
	}
	return false;
}
int main()
{
	int a[100];
	ofstream outfile;
	outfile.open("MyFile.txt",ios::out);//T2
	srand(time(0));
	for(int i=0;i<100;i++)
	{
		a[i]=(rand()%200-1+1);
	}
	outfile<<"Found Elements Are :\n";
	for(int i=0;i<100;i++)
	{
		if(LinSrch(a,100,i))
		{
			cout<<"\nfound :"<<a[i];//T1
			outfile<<a[i]<<endl;
		}
		else
		{
			cout<<"\nNot Found :"<<a[i];
		}
	}
}
