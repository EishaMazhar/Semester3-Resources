#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
template<class T>
class Node{
	
	public:
		T data;
		Node<T> *next;
		Node(){
			data=0;
			next=NULL;
		}
		Node(T d):data(d){
			next=NULL;
		}
};
template<class T>
class SLL{
	Node<T> *head;
	T size;
	deleteSLL(){
		if(head!=NULL){
			Node<T> *current=head,*temp;
			while(current){
				temp=current;
				current=current->next;
				temp->data=0;
				delete temp;
			}
			
		}
		size=0;
	}
	public:
		SLL(){
			head=NULL;
			size=0;
		}
		~SLL(){
			deleteSLL();
		}
		void InsertAtfront(T d)
		{
			Node<T> *node=new Node<T>(d);
			if(head==NULL){
				head=node;
			}
			else{
				node->next=head;
				head=node;
			}
			size++;
		}
		void InsertAtSpecific(T d){
			Node<T> *node=new Node<T>(d);
			 //??????
		}
		int SumOfAllTerms(){
			int s;
			Node<T> *current=head;
			if(!current){
				return 0;
			}
			else{
				while(current){
					s=s+current->data;
					current=current->next;
				}
				return s;
			}
		}
		void Display(){
			Node<T> *current=head;
			while(current){
				cout<<current->data<<" . ";
				current=current->next;
			}
		}
		void FindLargestNo(){
			Node<T> *current=head,*temp=head;
			while(temp){
				if(current->data<temp->data)
				{
					current->data=temp->data;
				}
				temp=temp->next;
			}
			cout<<endl<<"The largest no is : "<<current->data;
		}
		void FindSmallestNo(){
			Node<T> *current=head,*temp=head;
			while(temp){
				if(current->data>temp->data)
				{
					current->data=temp->data;
				}
				temp=temp->next;
			}
			cout<<endl<<"The smallest no is : "<<current->data;
		}
};
int SplitAndSum(int n){
	static int sum=0;
	if(n==0)
	return sum;
	
	else{
		sum=sum+n%10;
		n=n/10;
		SplitAndSum(n);
	}
	
}
main()
{
	SLL<int> l1;
	l1.InsertAtfront(77);
	l1.InsertAtfront(4);
	l1.InsertAtfront(18);
	l1.InsertAtfront(9);
	l1.Display();	
	int sum=l1.SumOfAllTerms();	
	cout<<endl<<"Sum of all terms : "<<sum;
	l1.FindLargestNo();
	l1.FindSmallestNo();
	///Recursion Practice   
	cout<<"\nSplit And Sum : ";
	int s=SplitAndSum(4567);   //  to find 4+5+6+7=22
	cout<<s<<endl;
	
	
}
