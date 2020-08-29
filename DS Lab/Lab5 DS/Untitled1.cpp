/*Safia Baloch: FAST-NUCES*/
#include<iostream>
#include<cstdlib>

using namespace std;
class safe {
	
		int size;
		double *p;
	public:
		
		safe(int s){
			

			p= new double[s];
			size=s;
			}
			
			//copy constructor ++++++++++++++++++++
			safe (const safe &w)
				{
				int i;
				p= new double[w.size];
			
				for(i=0; i<w.size;i++)
				if (i>=0 && i<size)
				
						//copy elements++++++++++++++	
				p[i]= w.p[i];

				for( i=0; i<w.size;i++)	
				cout<<"elements in copy constructor "<<p[i]<<endl;
				}
				
				void  put(int i, int j)
			{
				if (i>=0 && i<size)
				p[i]=j;
				
			}
			int get(int i)
			{
				return p[i];
			}
			
			//copy Assignment operator+++++++++ 
			safe &operator = (const safe &w)
			{
				double *p1 = new double[w.size];  			// allocate new space
				cout<<"copy assignment elements"<<endl;
				for(int i=0; i<w.size;i++) 					// copy elements
				if (i>=0 && i<size)
				p1[i]= w.p[i];
				delete [] p;								//dealocate old space
				size=w.size;
				for(int i=0; i<w.size;i++) 					// copy elements
				//cout<<"elements in assignment operator  "<<p1[i]<<endl;
			
				return *this;				// return self reference 
			}

					//Overloading operator +++++++++++++			
			 double &operator[](int i ) const
			{
				cout<< "we are in subscript operators\n"<<endl;
				
		
			if (i<0 || i>size )
			{ 
			cout<<"index value is out of bound "<<endl;
			exit (1);
			}
		return p[i];			
		}
				//Destructor +++++++++++++++++
		~safe(){
			cout<<"called destructor "<<endl;
			delete [] p;
			
		}
};

int main()
{
	safe v(4); // calling constructor 
	cout<<"elements in first object"<<endl;
	
	for(int i=0; i<2; i++)
 	v.put(i,i*2);
 	cout<<"elements in Before assignment object"<<endl;
	//for(int i=0; i<2; i++)
	//cout<<"...v"<<v.get(i)<<endl;
	safe v2(v); // copy constructor 

	//v2= safe(3); // copy assignment

	
	cout<<"elements after assignment object with overloading operator"<<endl;
	for(int i=0; i<6; i++)
	cout<<v[i]<<endl;
	
	
return 0;
}   
