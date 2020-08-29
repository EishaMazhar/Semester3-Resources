/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Class Example for Data Structures & Algorithm                   *
* Dated: August 28, 2018                                                   *
* Version: 1.0                                                             *                                                 
* Problem: Given number of Match Sticks you need to find first natural     *
* number that you can not produce from the given sticks.                   *
****************************************************************************/


#include<iostream>

using namespace std;

int CountMatches ( int num ){
	
	int Segments[10]={6,2,5,5,4,5,6,3,7,6};	
	int sum=0;
	int digit=0;
	if (num==0) return Segments[0];
	while (num > 0) {
	digit = num%10;
    num = num / 10;
    sum=sum+ Segments[digit];
	
    }  
	return sum;
	
}


int main(){
	
    int num =0;
    int count=0;
    
    cin >> num;
    
    for (int i=1; i<INT_MAX; i++)
	{
    	
		count=CountMatches(i); // see how many matches for i
    	//cout << i << "  " << count << endl; 
     	if ( count >= num+1 )  // if matches more than given number for a particular i 
    	{		cout << i << endl; 
    	        break;
        } 
		
	}
   
	return 0;
	
	
}
