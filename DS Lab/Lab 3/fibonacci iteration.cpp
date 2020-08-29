#include<iostream>
#include<ctime>
using namespace std;
int start=clock();
main(){
	int i,n,x=0,y=1,nxt=0;
	cout<<"Enter no of terms : ";
	cin>>n;
	for(i=1;i<=n;i++){
		if(i==1){
			cout<<x<<" ";
			continue;
		}
		if(i==2){
			cout<<y<<" ";
			continue;
		}
		nxt=x+y;
		x=y;
		y=nxt;
		cout<<nxt<<" ";
	}
	int stop=clock();
	cout<<"\nTime : "<<(stop-start)/double(CLOCKS_PER_SEC)<<endl;
}
