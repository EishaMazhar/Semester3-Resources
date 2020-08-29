#include<iostream>
#include<string.h>
using namespace std;
class Point2D{
	private:
		int *x,*y;
		
	public:
		Point2D();
		Point2D(int x1 , int y1);
		~Point2D();
		int* Getx();
		int* Gety();
		void Print();
};

Point2D::Point2D():x(NULL),y(NULL){}

Point2D::Point2D(int x1, int y1){
	x=new int;
	*x=x1;
	y=new int;
	*y=y1;
}

Point2D::~Point2D(){
	if(x!=0){
		delete x;
		x=0;
	}
	if(y!=0){
		delete y;
		y=0;
	}
}

int* Point2D::Getx(){
	return x;
}

int* Point2D::Gety(){
	return y;
}

void Point2D::Print(){
	cout<<"( "<<*x<<","<<*y<<" )"<<endl;
}

class Dynamic2DArray{
	private:
		char **Data;
		int row,col;
		
	public:
		Dynamic2DArray();
		Dynamic2DArray(int r,int c);
		~Dynamic2DArray();
		friend istream& operator>>(istream &file,Dynamic2DArray &rhs);
		friend ostream& operator<<(ostream &file,Dynamic2DArray &rhs);
		void Set(int r ,int c);
		int GetRow();
		int GetCol();
		char** GetData();
		int FindPath(int i,int j);
};
Dynamic2DArray::Dynamic2DArray():Data(0),row(0),col(0){}

Dynamic2DArray::Dynamic2DArray(int r,int c){
	row=r;
	col=c;
	Data=new char*[row];
	for(int i=0;i<row;i++){
		Data[i]=new char[col];
	}
}

Dynamic2DArray::~Dynamic2DArray(){
	if(Data!=0){
		for(int i=0;i<row;i++){
			if(Data[i]!=0)
				delete[] Data[i];
				Data[i] = 0;
			}
			delete []Data;
		}
		Data=0;
		row=0;
		col=0;
}
	

istream& operator>>(istream &file,Dynamic2DArray &rhs){
	for(int i=0;i<rhs.GetRow();i++)
		for(int j=0;j<rhs.GetCol();j++){
			file>>rhs.Data[i][j];
		}
			
	return(file);
}

ostream& operator<<(ostream &file,Dynamic2DArray &rhs){
	for(int i=0;i<rhs.GetRow();i++){
		for(int j=0;j<rhs.GetCol();j++){
			file<<rhs.Data[i][j]<<" ";
		}
		cout<<endl;
	}
			
	return(file);
}

int Dynamic2DArray::GetRow(){
	return row;
}

int Dynamic2DArray::GetCol(){
	return col;
}

char** Dynamic2DArray::GetData(){
	return Data;
}


int Dynamic2DArray::FindPath(int i,int j){
	
		  if (Data[i][j]=='e'){
					Point2D Point(i,j);
					Point.Print();
					return 0 ;
				}
		  else {
		  	if (Data[i][j]=='s'){
					Point2D Point(i,j);
					Point.Print();
				}
		  	if (j>0){
	   				if (Data[i][j-1] == '-'){
	   					Data[i][j-1] = '!' ;
	   					Point2D Point(i,j-1);
	   					Point.Print();
					   }
				   }
			if (j<col-1){
					if (Data[i][j+1] == '-'){
						Data[i][j+1] = '!' ;
						Point2D Point(i,j+1);
						Point.Print(); 
					}	
				}
			if (i<row-1){
					if (Data[i+1][j] == '-'){
						Data[i+1][j] = '!' ;
						Point2D Point(i+1,j);
						Point.Print();
					}
				}
			if (i>0){
					if(Data[i-1][j] == '-'){
						Data[i-1][j] = '!' ;
						Point2D Point(i-1,j);
						Point.Print();
					}
				}
		    if (j == col-1){
					i++ ;
					j = 0 ;
				}  
				j++ ;
				return FindPath(i,j);
				
		  }		
	}

int main(){
	int r,c;
	cout<<"Enter the row Size of matrix: ";
	cin>>r;
	cout<<"Enter the column Size of matrix: ";
	cin>>c;
	Dynamic2DArray D(r,c);
	cout<<"Enter your maze:\n";
	cin>>D;
	cout<<endl<<endl;
	D.FindPath(0,0);
	cout<<D;
	return(0);
}
