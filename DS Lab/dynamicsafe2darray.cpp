#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include<cstdlib>

using namespace std;
template<class T>
class dynamicSafe2DArray{
		T **data;
		unsigned int row,col;
	
	public:
		dynamicSafe2DArray():data(0){
			row = 0;
			col = 0;
		}
		dynamicSafe2DArray(unsigned int r,unsigned int c){
			row =r;
			col =c;
			data = new T*[row];
			for(int i=0;i<row;i++){
				data[i] = new T [col];
				memset(data[i],0,sizeof(T)*col);
			}
		}
		dynamicSafe2DArray(const dynamicSafe2DArray& rhs){
			this->row = rhs.row;
			this->col = rhs.col;
			this->data = new T*[row];
			for(int i=0;i<row;i++){
				data[i] = new T[col];
				memcpy(this->data[i],rhs.data[i],sizeof(T)*col);
			}
		}
		~dynamicSafe2DArray(){
			if(data != NULL){
				for(int i=row-1;i>=0;i++){
					if(data[i] != NULL)
						delete data[i];
				}
				delete [] data;
				
			}
			row = 0;
			col = 0;
			data = 0;
		}
		dynamicSafe2DArray& operator =(const dynamicSafe2DArray& rhs){
			if(this == &rhs)
				return *this;
			else{
				if(data != NULL){
				for(int i=row-1;i>=0;i++){
					if(data[i] != NULL)
						delete data[i];
				}
				delete [] data;
				
			}
				this->row = rhs.row;
				this->col = rhs.col;
				this->data = new T*[row];
				for(int i=0;i<row;i++){
				data[i] = new T[col];
				memcpy(this->data[i],rhs.data[i],sizeof(T)*col);
			}
				return *this;
			}
		}
		void resize(int r,int c){
			if(row <= r || col <= c){
				T** temp = new T*[row];
				for(int i=0;i<row;i++){
					data[i] = new T[col];
					memcpy(this.temp[i],data.data[i],sizeof(T)*col);
			}
				delete [] data;
				data = 0;
				this.data = new T*[row];
				for(int i=0;i<row;i++){
					data[i] = new T[col];
					memcpy(this.data[i],temp.data[i],sizeof(T)*col);
			}
			}
		}
		int lengthof(){
			return row*col;
		}
		void fillarray(){
			for(int i=0;i<row;i++)
				for(int j=0;j<col;j++){
				cout<<"ENTER"<<i+j<<"value";
				cin>>data[i][j];
			}
			
		}
		void display(){
			for(int i=0;i<row;i++)
				for(int j=0;j<col;j++){
					cout>>data[i][j];
			}
		}
		T operator ()(unsigned int i,unsigned int j){
			return data[i][j];
		}
		friend istream operator >>(istream& file,dynamicSafe2DArray& rhs){
			file>>rhs.row;
			file>>rhs.col;
			for(int i=0;i<rhs.row;i++)
				for(int j=0;j<rhs.col;j++)
					file>>rhs.data[i][j];
					return file;
		}
		friend ostream operator <<(ostream& file,dynamicSafe2DArray& rhs){
			for(int i=0;i<rhs.row;i++)
				for(int j=0;j<rhs.col;j++)
				file<<rhs.data[i][j];
				return file;
		}
		
};
