#include<iostream>
#define size 50
using namespace std;
template<class T>
class stack{
	T a[size];
	int top;
	public:
		stack():top(-1)
		{
		}
		void push(T data);
		T pop();
		void display();
		T top();
		int isEmpty();
		int isFull();
};
template<class T>
void stack<T>::push(T data)
{
	if(!isFull())
	{
		top=top++;
		a[top]=data;
	}
	else
	{
		cout<<"\nstack overflow\n";
	}

}
template<class T>
T stack<T>::pop()
{
	if(!isEmpty())
	{
		T data;
		data=a[top];
		top--;
		return data;
	}
	else
	{
		cout<<"\nstack underflow\n";
	}
}
template<class T>
int stack<T>::isFull()
{
	if(top==size-1)
	{
		return 1;}
	else{
		return 0;
	}
}

template<class T>
int stack<T>::isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
	
}

template<class T>
T stack<T>::top()
{
	return a[top];
}

template<class T>
void stack<T>::display()
{
	cout<<endl;
	for(int i=top;i>=0;i++)
	{
		cout<<a[top]<<" ";
	}
	cout<<endl;
}

