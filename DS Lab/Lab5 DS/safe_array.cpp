#include<iostream>
#include<cstdlib>

using namespace std;
class safe
{
int *p; 
int size;
public:
safe(int s)
{
	try{
	
	p= new int [s];
}
		catch(bad_alloc a)
	{
		cout<<"allocation failure\n";
		exit(EXIT_FAILURE);
		}	
		size=s;
}
~safe()
{
	delete[ ] p;
}

//copy constructore 
safe (const safe &z)
{
	int i ; 
try {
//
	p = new int [z.size];
//	
}

catch (bad_alloc a)
{
	cout<<"allocation failure \n";
	exit(EXIT_FAILURE);
}
for(i=0; i<z.size;i++)
p[i]=z.p[i];
}

void put (int i , int j)
{
	if (i>=0 && i<size)
	p[i]=j;
}
int get (int i)
{
	return p[i];
}
	safe &operator [](int i )
		{
			if (i<0 || i>size-1)
			{
				cout<<"\n Index value of ";
				cout<<i<<" is out of bound .\n";
				exit(1);
			}
			return p[i];
		}
};
int main()
{
	safe num(10);
	for (int i =0; i<10 ; i++)
	num.put(i,i);
	for (int j =9; j>=0; j--)
	cout<<num.get(j);
	cout<<"\n";
	//copy constructor invoke 
	safe copy(num);
	for (int i =0; i <10; i++)
	cout<< copy.get(i);
return 0;
}

