#include<iostream>
using namespace std;
#define size 10
class stack{
	int top;
	int a[size];
	public:
		stack(){
			top=-1;
		}
		int isempty(){
			return(top==-1);
		}
		int isfull(){
			return(top==size-1);
		}
		void push(int n){
			if(isfull()){
				cout<<"\nstack full\n";
				return;
			}
			else{
				top++;
				a[top]=n;
			}
		}
		void pop(){
			if(isempty()){
				cout<<"\nempty stack\n";
				return;
			}
			else{
				int t=a[top];
				top--;
			}
		}
		void display(){
			if(isempty())
				cout<<"\nempty stack\n";
			else
			{
				cout<<endl;
				for(int i=top;i>=0;i--)
				{
					cout<<a[i]<<" ";
				}
			}
			
		}
};
main(){
	stack s;
	s.push(12);
	s.push(23);
	s.push(2);
	s.push(54);
	s.push(3);
	s.pop();
	s.display();
}
