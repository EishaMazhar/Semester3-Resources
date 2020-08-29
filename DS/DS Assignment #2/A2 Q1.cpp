#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int r,c,cnt;
ofstream file;
string psol;
bool isSafe(char **m,int x,int y,int d_x,int d_y){
	if(x<0||y<0||x>=c||y>=r||m[y][x]=='0'){
		return 1;
	}
	else return 0;
}
void path(char **m,int x,int y,int d_x,int d_y,int pcost)
{
	if(isSafe(m,x,y,d_x,d_y)) return;
	int l=psol.size();
	int cost=1;
	cost+=pcost;
	psol+= '(';
	psol+= (char)('0'+x);
	psol+= ',';
	psol+= (char)('0'+y);
	psol+= ')';
	if(x==d_x && y==d_y)
	{
		cnt++;
		string final;
		final+="path no ";
		final+=(char)('0'+cnt);
		final+="={" + psol + "} Cost=";
		final+=(char)('0'+ cost);
		file<<final<<endl;
	}
	else
	{
		psol+=",";
		m[y][x] = '0';
		path(m,x,y-1,d_x,d_y,cost);
		path(m,x,y+1,d_x,d_y,cost);
		path(m,x-1,y,d_x,d_y,cost);
		path(m,x+1,y,d_x,d_y,cost);
		m[y][x]='1';
	}
		psol.resize(l);
	
}
main(){
	int d_i,d_j;
	cout<<"Enter rows :";
	cin>>r;
	cout<<"Enter columns : ";
	cin>>c;
	
	file.open("A2 Q1.txt");
	char **m;
	m=new char*[r];
	for(int i=0;i<r;i++){
		m[i]=new char[c];
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>m[i][j];
			if(m[i][j]='e')   			 //it will save the destination coordinates
			{
				d_i=i;
				d_j=j;
			}
		}
	}
	m[0][0]='1';
	m[d_i][d_j]='1';
	path(m,0,0,d_i,d_j,0);
	file.close();
}
