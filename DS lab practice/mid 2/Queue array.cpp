#include<iostream>
using namespace std;
# define size 5
class Queue{
	int f,r;
	int arr[size];
	int count;
	public:
		Queue(){
			f=r=-1;
		}
		void enqueue(int d)
		{
			if(isfull())
			{
				cout<<"\noverflow!\n";
			}
			else{
				r++;
				arr[r]=d;
				count++;
				if(f==-1)f=0;
			}
				
		}
		int dequeue()
		{
			int d=-1;
			if(isempty()){
				cout<<"empty queue!";
				return (-1);
			}
			else{
				d=arr[f];
				if(f==r){
					f=r=-1;
				}
				else{
					f=(f+1)%size;
				}
				return d;
			}
		}
		
		int isfull(){
			return((r+1)%size==f);
		}
		
		int isempty(){
			return(f==r==-1);
		}
		
		void display(){
			int i=0;
			if(!isempty())
			for(i=f;i<=r;i++){
				cout<<arr[i]<<" ";
			}
			else
			cout<<"\nQueue empty\n";
		}
};
main(){
	Queue q;
	q.enqueue(4);
	q.enqueue(7);
	q.enqueue(5);
	q.dequeue();
	q.dequeue();
	q.enqueue(11);
	q.display();
}
