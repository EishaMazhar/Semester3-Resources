#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
 class DSA{
 	private:
 		int s;
 		int *d;
 		
 	public:
 		DSA()
		{
 			s=100;
 			d=new int[100];
 			memset(this->d,0,sizeof(int)*s);
		}
		DSA(int a){
			s=a;
			d=new int[s];
			memset(this->d,0,sizeof(int)*s);
		}
 };
 int main(){
 	DSA a;
 	DSA b(10);
 }
