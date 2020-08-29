#include <iostream>
using namespace std;
int example(){    
	static int count=0;    
	count++; 
	return count;   
}
int main(){  
    int x;          	
	for (int i=0; i<3;i++){                
		x=example();    
      }     
      cout<<x<<endl; 
      return 0;
}

