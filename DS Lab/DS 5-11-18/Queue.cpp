#include<iostream>
using namespace std;
template<class T>
class Queue{
	int f,r;
	T a[10];
	int size;
	public:
		Queue(){
			f=0;
			r=-1;
			size=0;
		}
		void dequeue(){
			if(size!=0){
				f++;
				size--;
			}
		}	
		void enqueue(T x){
			r++;
			a[r]=x;
			size++;
		}
	
		void display(){
		cout<<endl;
		if(size!=0){
				for(int i=f;i<=size;i++){
				cout<<a[i]<<endl;
			}
			cout<<"\nSize is : "<<size<<endl;
		}
		else cout<<"Queue underflow !";
		}
};
main()
{
	Queue<int> q;
	q.enqueue(8);
	q.enqueue(4);
	q.enqueue(12);
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.dequeue();
	q.display();
}
