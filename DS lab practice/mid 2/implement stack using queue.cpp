
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
template<class T>
class Stack{
	queue<int> q;
	public: 
		void push(T d)
		{
			int s=q.size();
			q.push(d);
			for(int i=0;i<s;i++){
				q.push(q.front());
				q.pop();
			}
		}
		T pop()
		{
			cout<<endl;
			if(q.empty()){
				cout<<"empty\n";
			}
			else
			q.pop();
		}
		T top() 
		{ 
    		return (q.empty())? -1 : q.front(); 
		} 
		void display(){
			if(!q.empty()){
			
				for(int i=0;i<q.size();i++){
					cout<<q.front()<<" ";
					q.pop(); 
				}
			}
		}
};
main(){
	
	Stack<int> s;
	s.push(5);
	s.push(12);
	s.push(21);	
	cout<<s.top();
	s.pop();
	cout<<s.top();
	
}
