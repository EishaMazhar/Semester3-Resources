using namespace std;
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#ifndef STACK_imp
#define STACK_imp

template<typename DTYPE>
class stack{
	protected:
		unsigned int size;
		unsigned int used;
		DTYPE *TOP;
		DTYPE *arr;
	public:
		stack(){
			used = 0;
			size = 10;
			TOP = NULL;
			arr = new DTYPE[size];
			for(int i = 0; i < size;i++){
				arr[i] = 0;
			}
		
		}
		
		DTYPE push(DTYPE d){
			if(arr == NULL){
				arr = new DTYPE[10];
				arr[0] = d;
			
				TOP = &arr[0];
				used++;
				return arr[0];
			}
			
			if(used==size){
				/*
				cout << "BEFORE ALLOT" <<endl;
				this->display_array();
				*/
				DTYPE* temp = new DTYPE[size];
				memcpy(temp,arr,size*sizeof(DTYPE));
				arr = new DTYPE[size +  10];
				memcpy(arr,temp,size*sizeof(DTYPE));
				memset(arr+size,'\0',size+10);
				size += 10; 
				/*
				cout <<"AFTER ALLOT " <<endl;
				this->display_array();
				*/
			}
			
 			//cout << used << "size : "<< size <<endl;
			arr[used] = d;
			TOP = &arr[used];
			used++;
			
		}
		
		DTYPE pop(){
			DTYPE temp = arr[used-1];
			used--;
			arr[used] = 0;
			TOP = &arr[used-1];
			return temp;
		}
		bool display_stack(){
			cout << endl << "STACK : " <<endl;
			for(int i = used-1; i >= 0;i--){
				cout << endl << setw(3) << arr[i];
			}
			cout << endl;
		}
		bool display_array(){
			cout << endl << "ARRAY : " <<endl;
			for(int i = size-1; i >= 0;i--){
				cout << endl  << "#" << i  << " "<< setw(3) << arr[i];
			}
			cout << endl;
		}
		DTYPE peak(){
			return (*TOP);
		}
		DTYPE ret_size(){
			return this->size;
		}
		~stack(){
			if(arr)
			delete []arr;
		}
	
};



#endif 
