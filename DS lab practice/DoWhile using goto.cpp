#include <iostream> 
using namespace std; 
main(){
	int num=1;
	STEP:do{
		if(num==3)
		{
			num=num+1; 
			goto STEP; 
		} 
		cout<<num<<endl; 
		num=num+1; 
	}
	while(num<6);  
}

