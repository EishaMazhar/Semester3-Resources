#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include<cstdlib>

using namespace std;
template<class T>
class Node{
	public:
	T data;
	Node<T> *next;
	
		Node():next(NULL){
			data = 0;
		}
		Node(T val):next(NULL){
			data = val;
		}
		Node(T val,Node<T> *n):next(n){
			data = val;
		}
		Node(const Node& rhs){
			this->data = rhs.data;
			this->next = rhs.next;
			
		}
};
template <class T> 
class List { 
	
	private: 
    Node<T> *head;   
    int size;
    
    void deleteList(){
    		if(head != 0){
    			Node<T> *current = head;
    			Node<T> *temp;
    			while(current){
    				cout<<"DELETING  ->"<<current->data<<"\n";
    				temp = current;
    				temp->data = 0;
    				current= current->next;
    				delete temp;
				}
				size=0;
			}
    	
		}
	public: 
   		List(){ 
		   	head = 0; 
			size = 0;
		}
   		List(const List<T> &rhs){
   			size = rhs.size;
   			head = 0;
   			Node<T> *current = rhs.head;
   			Node<T> *newptr,*lastptr;
   			
   			while(current){
   				newptr = new Node<T>(current->data);
   				if(head == 0)
   					head = newptr;
			   	else
			   		lastptr->next = newptr;
			   	lastptr = newptr;
			   	current = current->next;
			}
		}
   		~List(){
   			deleteList();
   			size = 0;
		}     
   		 
   		void insertAtFront( const T &val){
   			Node<T> *node = new Node<T>(val);
   			if(head == NULL){
   				head = node;
			   }
			else{
				node->next = head;
				head = node;
			}
			size++;
		} 
		void insertAtLast(const T& val){
			Node<T> *node = new Node<T>(val);
			if(head == NULL){
   				head = node;
			   }
			else{
				Node<T> *current = head;
				
				while(current != 0){
					current = current->next;
				}
				current->next = node;
			}
			size++;
		}
		void insertAtIndex(int index,T& val){
			if(this->size>= index){
				Node<T> *node = new Node<T>(val);
				Node<T> *current = head;
				for(int i=0;i<index;i++){
					current = current->next;
				}
				node->next = current->next;
				current->next =node;
			}		
		}  
   		void removeAtFront(){
   			if(head != NULL){
   				Node<T> *current = head;
   				head = head->next;
   				current->data = 0;
   				current->next = NULL;
   				delete current;
   				size--;
			   }
		   }
		void removeAtLast(){
			if(head != 0){
				Node<T> *first = head,*second = head->next;
				while(first){
					first = first->next;
					second = second->next;
				}
				first->data = 0;
				second->next = NULL;
				delete first;
				size--;
			}
		}
		void removeAtIndex(int index){
			if(this->size>= index){
				Node<T> *current = head;
				for(int i=0;i<index;i++)
				{
					current = current->next;
					}	
				Node<T> *temp = current->next;
				current->next = temp->next;
				temp->next = NULL;
				temp->data = 0;
				delete temp;
				size--;
			}
		}
   		void print() const{
			if(!head)
				cout<<"LIST IS EMPTY";
			else{
				Node<T> *current = head;
				while(current){
					cout<<current->data<<" ->";
					current = current->next;
				}
			}
		   
		} 
   		int getSize() const{ 
		   	return size;  
		} 
   		List& operator = (const List<T> &rhs){
		    if(this != &rhs){
		    	deleteList();
		    	size = rhs.size;
   				head = 0;
   				Node<T> *current = rhs.head;
   				Node<T> *newptr,*lastptr;
   			
   				while(current){
   					newptr = new Node<T>(current->data);
   					if(head == 0)
   						head = newptr;
			   		else
			   			lastptr->next = newptr;
			   			
			   		lastptr = newptr;
			   		current = current->next;
				}
			}
			return *this;
 		}		
};



int main() 
{ 
  List<int> L1; 
  cout << "The size of the list is: " << L1.getSize() << endl; 
  L1.insertAtFront(123); 
  L1.insertAtFront(456); 
  L1.insertAtFront(789); 
  cout << "The size of the list now is: " << L1.getSize() << endl; 
  L1.print(); 
  L1.removeAtFront(); 
  cout << "The size of the list now is: " << L1.getSize() << endl; 
  return 0; 
} 











 

