#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

class Dynamic2D{
	int c;
	int r;
	int **dArr;
	public:
		Dynamic2D(){
			r=0;
			c=0;
			dArr=NULL;
		}
		Dynamic2D(int row,int col){
			r=row;
			c=col;
			dArr=new int*[r];
			for(int i=0;i<r;i++)
			{
				dArr[i]=new int[col];
			}
		}
		~Dynamic2D()
		{
			if (dArr!=NULL)
			{
			for (int i=r-1;i>=0;i--)
				{
					if(dArr[i]!=0)
					delete dArr[i];
					dArr[i]=0;
					}
					delete [] dArr;
				}
			dArr=0;
		}
		//bound check array
		int &operator()(int i,int j){
			if(i<0||i>r-1||j<0||j>c-1){
				cout<<"Boundary Error\n";
				exit(1);
			}
			return dArr[i][j];
		}
		//copy constructor
		Dynamic2D(const Dynamic2D &rhs){
			this->r=rhs.r;
			this->c=rhs.c;
			dArr=new int*[r];
			for(int i=0;i<r;i++){
				dArr[i]=new int[c];
				memcpy(this->dArr[i],rhs.dArr[i],sizeof(int)*c);
			}
		}
		//assignment operator "=" overloading
		Dynamic2D &operator=(const Dynamic2D &rhs){
			if(this==&rhs)return *this;
			for(int i=r;i>=0;i--)
			{
				delete dArr[i];
			}
			delete [] dArr;
			this->r=rhs.r;
			this->c=rhs.c;
			dArr=new int*[r];
			for(int i=0;i<r;i++){
				dArr[i]=new int[c];
				memcpy(this->dArr[i],rhs.dArr[i],sizeof(int)*c);
			}
			return *this;
		}
		
		
		
		
		
};
