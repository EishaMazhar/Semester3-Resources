#include<iostream>
using namespace std;
class Point2D
{
	private:
		int *x;
		int *y;
	public:
		Point2D()
		{
			x=new int;
			*x=0;
			y=new int;
			*y=0;
			cout<<"Default Constructor : "<<endl<<*x<<endl<<*y;
		}	
		Point2D(int a,int b)
		{
			x=new int;
			*x=a;
			y=new int;
			*y=b;
			cout<<"\nParameterized Constructor : "<<endl<<*x<<endl<<*y;
		}	
		~Point2D()
		{
			if(*x!=0){
				delete x;
				x=0;
			}
			if(*y!=0){
				delete y;
				y=0;
			}	
			cout<<"\nDestructor : "<<endl<<x<<endl<<y;
		}
		int getx()
		{
			return *x;
		}
		int gety()
		{
			return *y;
		}
		Point2D &operator=(const Point2D &rhs)
		{
			if(this==&rhs){
				cout<<endl<<*x<<endl<<*y;
				return (*this);
			}
			else
			{
				if(*x!=0)
				{
					delete x;
					*x=0;
					x=new int;
					this->x=rhs.x;
				}
				if(*y!=0)
				{
					delete y;
					*y=0;
					y=new int;
					this->y=rhs.y;
				}
				cout<<endl<<*x<<endl<<*y;
				return (*this);
			}
		}
		
		Point2D(const Point2D &rhs)
		{
			x=new int;
			this->x=rhs.x;
			y=new int;
			this->y=rhs.y;	
			cout<<"copy Constructor : "<<endl<<*x<<endl<<*y;
		}
};

main()
{
	Point2D ob(3,2);
	Point2D ob2=ob;
	Point2D ob3(ob);
}

