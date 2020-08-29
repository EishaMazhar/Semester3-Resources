#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include<cstdlib>

using namespace std;
class Eisha{
	private:
		int *p,s;
	
	public:
		Eisha()
		{
			p=NULL;
			s=0;
		}
		
		Eisha(int x):s(x)
		{
			p=new int[s];
			memset(this->p,0,sizeof(int)*s);
		}
		
		Eisha(const Eisha &e)
		{
			this->s=e.s;
			this->p= new int[s];
			memcpy(this->p,e.p,(sizeof(int)*e.getSize()));
		}
		
		unsigned int getSize() const
		{
			return s;
	    }
	    
		put(){
			cout<<"Enter elements of array : ";
			for(int i=0;i<s;i++)
			cin>>p[i];
		}
		
		get()
		{
			cout<<endl;
			for(int i=0;i<s;i++){
				cout<<*(p+i)<<" ";
			}
		}
		
		~Eisha()
		{
	    	if(p!=0)
	    	{
			
		    	delete [] p;
		    	p=0;
		    	s=0;
		   }
			cout<<"\n\n\tDeleted !";
		}
};
main(){
	
	Eisha e(5);
	Eisha e1(e);
	e.put();
	e.get();
}
