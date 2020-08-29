#include<iostream>
using namespace std;
template<class T>
class Stack
{
	struct node{
		T data;
		node *next;
	}*top;
	int size;
	public:
		Stack():top(NULL)
		{
			size=0;
		}	
		
		void push(T num){
			node *temp=new node;
			temp->data=num;
			temp->next=NULL;
			if(top==NULL){
				top=temp;
			}
			else{
				temp->next=top;
				top=temp;
			}
			size++;
			
		}
		void pop(){
			node *temp=top;
			if(top==NULL){
				cout<<"Stack is empty\n";
			}
			else{
				top=top->next;
				delete temp;
				size--;
			}
			
		}
		int isEmpty(){
			if(size!=0){
				return 0;
			}
			else return 1;
		}
		void Display(){
			node *temp=top;
			if(isEmpty()==0){
				while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			}
			else
				cout<<"\nEmpty Stack\n";
			
		}
		void getsize(){
			cout<<"\nThe size of stack is : "<<size<<endl;	
		}
};
main(){
	Stack<int> s;
	s.push(5);
	s.push(8);
	s.push(19);
	s.Display();
	s.getsize();
	s.pop();
	s.Display();
	s.getsize();
	s.pop();
	s.Display();
	s.getsize();
	s.pop();
	s.getsize();
	s.Display();
}
