#include"dyn_safe_arr_lib.h"

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;

template<typename DTYPE>
dyn_safe_arr<DTYPE>::dyn_safe_arr(){
	arr = NULL;
	size = 0;
}

template<typename DTYPE>
dyn_safe_arr<DTYPE>::dyn_safe_arr(int s){
	if(s <= 0){
		cout << endl << "INVALID SIZE TO DYN_SAFE_ARR" << endl;
		exit(1);
	}
	this->size = s;
	arr = new DTYPE[s];
	memset(this->arr,'\0',s);
	
}
			
template<typename DTYPE>
dyn_safe_arr<DTYPE>::dyn_safe_arr(int s,DTYPE *array){
	if(array == NULL){
		cout << endl << "INVALID ARRAY TO DYN_SAFE_ARR" << endl;
		exit(1);
	}
	this->size = s;
	arr = new DTYPE[s];
	memcpy(arr,array,s);
}
			
		
template<typename DTYPE>
dyn_safe_arr<DTYPE>::dyn_safe_arr(dyn_safe_arr<DTYPE> &obj){
	this->size = obj.size;
	arr = new DTYPE[size];
	memcpy(arr,obj.arr,size);
}
		
template<typename DTYPE>
dyn_safe_arr<DTYPE> dyn_safe_arr<DTYPE>::operator=(dyn_safe_arr<DTYPE> &obj){

	if(this == &obj){
		return obj;	
	}
	if(this->size != 0){
		this->size = 0;
		delete []arr;
	}

	this->size = obj.size;
	arr = new DTYPE[this->size];
	memcpy(arr,obj.arr,size);
	
	return obj;
}
			
template<typename DTYPE> 
DTYPE& dyn_safe_arr<DTYPE>::operator[](int i){
	if(i < 0 || i >= size){
		cout << endl << "INDEX OUT OF BOUND" << endl;
		exit(1);
	}
	return arr[i];
		
}
	
template<typename DTYPE>
dyn_safe_arr<DTYPE>::~dyn_safe_arr(){
	if(size!=0){
		size = 0;
		delete []arr;
	}
}

template<typename DTYPE>
void dyn_safe_arr<DTYPE>::autofill(){
	for(int i = 0; i < size; i++){
		arr[i] = (DTYPE)((int)i + 'a');
	}
}


template<typename DTYPE>
void dyn_safe_arr<DTYPE>::display(){
	for(int i = 0; i < size; i++){
		cout << " " << arr[i]; 
	}	
}

template<typename DTYPE>
 ostream& operator << (ostream &o,dyn_safe_arr<DTYPE> &obj){
	o << obj.arr;
	return o; 
}
	
template<typename DTYPE>
istream& operator >> (istream &i,dyn_safe_arr<DTYPE> &obj){
	if(obj.size == 0 || obj.size < 80){
		delete []obj.arr;
		obj.size = 80;
		obj.arr = new DTYPE[80];
		memset(obj.arr,'\0',80);
	}

	i >> obj.arr;
	
	return i;
}
template<typename DTYPE>
int dyn_safe_arr<DTYPE>::filled(){
	int temp = 0;
	while(this->arr[temp] != '\0'){
		temp++;
	}
	return temp;
}
