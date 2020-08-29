#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
//Node class
template <class T>
class Node{
	public:
		T data;
		Node *next;
	
		Node():next(NULL){data=0;}
		
		Node(T d){
			next=NULL;
			data=d;
		}
		Node(T d,Node<T> *n){
			data=d;
			next=n;
		}
		Node(const Node &rhs){
			this->data=rhs.data;
			this->next=rhs->next;}
};
//Linked list class
template<class T>
class List{
		Node<T> *head;
		T size;
		
		deleteList(){
			if(head!=0){
				Node<T> *current=head;
				Node<T> *temp;
				while(current){
					temp=current;
					temp->data=0;
					current=current->next;
				}
				delete temp;
			}
		}
	public:
		List():head(0),size(0){}
		List(const List &rhs)
		{
			
		}
		RemoveLast()
		{
		if(head!=NULL){
				Node<T> *current=head,*sec;
				while(current->next!=NULL){
					sec=current;
					current=current->next;
					
				}
				current->next=NULL;
				free(current->next);
				size--;
				
			}
			
		}
		void InsertAtFront(const T &d){
			Node<T> *node=new Node<T>(d);
			if(head==0){
				head=node;
			}
			else{
				node->next=head;
				head=node;
			}
			size++;
		}
		void InsertAtLast(T d){
			Node<T> *node=new Node<T>(d);
			if(head==NULL){
				head=node;
			}
			else{
				Node<T> *current=head;
				while(current!=0){
					current=current->next;
				}
				current->next=node;
				
			}
			size++;
		}
		void RemoveAtFront(){
			Node<T> *current=head;
			head=head->next;
			current->next=0;
			delete current;
			size--;
		}
		void InsertAtIndex(int ind,T d)
		{
			if(ind<=this->size)
			{
				Node<T> *node=new Node<T>(d);
				Node<T> *current=head;
				for(int i=0;i<ind;i++){current=current->next;}//moving upto index
				
				node->next=current->next;
				current->next=node;	
			}
			else
			{
				cout<<"\nout of bound!";
			}
		}
		int getSize(void){
			return size;
		}
		void Print()
		{
			if(!head){
				cout<<"List Is Empty ; ";
			}
			else{
				Node<T> *current=head;
				while(current)
				{
					cout<<current->data<<" -> ";
					current=current->next;
				}	
				cout<<"NULL";
			}
		}
		void Reverse(){
			Node<T> *current=head;
			Node<T> *prev=NULL,*next=NULL;
			while(current){
				next=current->next;
				current->next=prev;
				prev=current;
				current=next;
			}
			head=prev;
		}
		List<T> &SplitHalf(){
			Node<T> *st1=head,*st2=head,*current=head;
			while(current){
				st1=st1->next;
				st2=st2->next->next;
				current=current->next->next;
			}
			this->head=st1;
			return(*this);
		}
		~List()
		{
			deleteList();
			size=0;
		}
		
};
main()
{
	List<int> L1;
	L1.InsertAtFront(3);
	L1.InsertAtFront(4);
	L1.InsertAtFront(6); 
	L1.InsertAtFront(123);
	L1.InsertAtFront(34); 
	L1.InsertAtFront(5);
	L1.Print();
	cout<<"\n size is : "<<L1.getSize();
	L1.RemoveLast();
	L1.Print();
//	L1.Reverse();
//	cout<<endl<<"Reversed list: \n";
//	L1.Print();
//	L1.SplitHalf();
//	L1.Reverse();
//	L1.RemoveAtFront();
//	cout<<endl<<"Splitted list : \n";
//	L1.Print();
}
