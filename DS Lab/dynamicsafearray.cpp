#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include<cstdlib>

using namespace std;
template<class T>
class dynamicSafeArray{
		T *data;
		unsigned int size;
	
	public:
		dynamicSafeArray():data(0){
			size =0;
		}
		dynamicSafeArray(int s){
			size = s;
			data = new T[size];
			memset(data,0,sizeof(T)*size);
		}
		dynamicSafeArray(const dynamicSafeArray& rhs){
			this.size = rhs.size;
			this.data = new T [size];
			memcpy(this.data,rhs.data,sizeof(T)*size);
		}
		~dynamicSafeArray(){
			if(data != NULL){
				delete [] data;
			}
			size = 0;
			data = 0;
		}
		dynamicSafeArray& operator =(const dynamicSafeArray& rhs){
			if(this == &rhs)
				return *this;
			else{
				delete [] this.data;
				this.size = rhs.size;
				this.data = new T [size];
				memcpy(this.data,rhs.data,sizeof(T)*size);
				return *this;
			}
		}
		void resize(int s){
			if(size <= s){
				T* temp = new T[size];
				memcpy(temp,data,sizeof(T)*size);
				size = s;
				delete [] data;
				data = 0;
				data = new T[size];
				memcpy(data,temp,sizeof(T)*size);
			}
		}
		int sizeoff(){
			return size;
		}
		void fillarray(){
			for(int i=0;i<size;i++){
				cout<<"ENTER"<<i+1<<"value";
				cin>>data[i];
			}
		}
		void display(){
			for(int i=0;i<size;i++){
				cout<<data[i];
			}
		}
		T operator [](unsigned int i){
			if(i<= size)
				return data[i];
			else
				return -1;
		}
		friend istream operator >>(istream& file,dynamicSafeArray& rhs){
			file>>rhs.size;
			for(int i=0;i<rhs.size;i++)
				file>>rhs.data[i];
				return file;
		}
		friend ostream operator <<(ostream& file,dynamicSafeArray& rhs){
			for(int i=0;i<rhs.size;i++)
				file<<rhs.data[i];
				return file;
		}
		
};
