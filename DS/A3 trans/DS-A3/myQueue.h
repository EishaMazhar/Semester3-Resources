
using namespace std;
#include<iostream>
#include<cstdlib>
#include<cstring>

#ifndef QUEUE_imp
#define QUEUE_imp
  

template <typename T>
class queue{
	protected:
		T* arr; 
		int size;
		int used;
		int front;
		int end;
	public:
		queue(){
			size = 100;
			arr = new T[size];
			used = 0; front = -1; end = -1;
		}
		T* arr_ret(){
			return this->arr;
		}
		int size_ret(){
			return this->size;
		}
		int used_ret(){
			return this->used;
		}
		int front_ret(){
			return this->front;	
		}
		int end_ret(){
			return this->end;	
		}
	
		
		bool is_empty(){
			return (front == -1 && end == -1) ? true:false;
		}
		T push(T data){
			//cout << endl << "size : " << size << " use : " << used   <<  " front : " << front << " end : " << end << " data : " << data;
			if((end + 1 == front && used==size) || (front == 0 && end == size - 1 && used==size)){
				
				T* temp = new T[size];
				memcpy(temp,arr,size*sizeof(T));
				delete []arr;
				arr = new T[size +  10];
				if(end+1 == front){
					memcpy(arr,temp + front,(size - front)*sizeof(T));
					memcpy(arr + size - front,temp,(front)*sizeof(T));
				}
				else{
					memcpy(arr,temp,size*sizeof(T));
				}
				memset(arr+size,'\0',size+10);
				size += 10;
				
				front = 0;
				end = size - 10;
				arr[end] = data;
				used++;
	
				return arr[end];
			}
			if(front==-1 && end==-1){
				arr[0] = data;
				front = 0;
				end = 0;
				used++;
				return arr[end];
 			}
			if(front==end){
				end  = (end + 1)%size;
				arr[end] = data;
				used++;
				return arr[end];
			}
			if(end+1 != front && end+1 != size - 1){
				arr[(end + 1)%size] = data;
				end  = (end + 1)%size;
				
				used++;
				return arr[end];
			}
			if(front > 0 && end+1 != size - 1){
				arr[(end + 1)%size] = data;
				end  = (end + 1)%size;
				used++;
				return arr[end];
			}
			arr[(end + 1)%size] = data;
			end  = (end + 1)%size;
			used++;
		
			return arr[end];
		}
		T& peak_end(){
			return arr[front];
		}
		T pop(){
			T f = arr[front];
			if(front == -1){
				cout << endl << "QUEUE IS EMPTY." << endl ;
			}
			if(end > 0)
				front++;
			if(front-1==end){
				front = -1;
				end=-1;
			}
			if(front==size)
				front = 0;
			used--;
			return f;
		}
		void display_arr(){
			cout << endl;
			cout << "size :  " << this->size << " used : " << this->used  << " front : " << this->front << " end : " 
				 << this->end  << endl; 
			for(int  i = 0;  i < size; i++){
				cout << i << " <" << arr[i] << " >" << endl;
			}
			cout << endl;
		}
		void display_queue(){
			cout << endl;
			if(front == -1 && end == -1){
				cout << endl << "Empty Queue" << endl; 
				return ;
			}
			if(front < end){
				for(int  i = front;  i <= end; i++){
					cout << i << " <" << arr[i] << " >" << endl;
				}	
			}
			else{
				int k = front;
				for(int  i = 0;  i < used; i++){
					cout << k << " <" << arr[k] << " >" << endl;
					k = (k + 1) % size;  
				}
			}
			cout << endl;
		}
		bool sort_except_first(){
			if(front == -1 && end == -1){
				cout << endl << "Empty Queue" << endl; 
				return false;
			}
			if(front > end){
				cout << endl << "Queue In Circle" << endl;
				return false;
			}
			for(int i = front + 1;i < end; i++){
				for(int j = front + 1; j < end - 1; j++){
					if(arr[j] != arr[j+1]){
						T temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;
					}
				}
			}
		}
		~queue(){
			if(size>0)
			delete []arr;
			size = 0;
		}
};
#endif
