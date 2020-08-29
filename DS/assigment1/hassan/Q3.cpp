#include<iostream>
#include<fstream>

using namespace std;

int main(){
	int type = 0;
	istream *inp;
	ostream *out;
	ifstream s("CS201-DS-A1TestCasesWitoutput\\P3\\A1P3IO5.txt");
	ofstream p("CS201-DS-A1TestCasesWitoutput\\P3\\A1P3IO5myOUT.txt");
	
	while(type==0){
		cout << "Enter type of input : " << endl;
		cout << '\t' << "1- User input : (input from keyboard - output on screen)" << endl;
		cout << '\t' << "2- filing input : (input from file - output on file)" << endl;
		cin >> type;
		if(type==2){
			if(!(s.is_open())){
				cout << "File NOT FOUND " ;
				return 1;
			}
			if(!(p.is_open())){
				cout << "ERROR OPENING OUTPUT FILE  " ;
				return 1;
			}
			inp = &s;
			out = &p;
			break;
		}
		else if(type==1){
			inp = &cin;
			out = &cout;
			break;
		}
		else if(type!=1){
			cout << "INVALID INPUT "<<endl;
		}
	}
	
	
	unsigned int n = 0,t = 0;
	(*inp) >> n;
	if(n < 0 || n > 30000){
		cout << endl << " n out of range. Abort Program" << endl;
		return 1;
	}
	unsigned int *arr = new unsigned int[n];
	for(int i = 0; i < n; i++){
		(*inp) >> arr[i];
		if(arr[i] < 0 || arr[i] > 30000){
			cout << endl << " array input out of range. Abort Program" << endl;
			return 1;
		}
	}	
	(*inp) >> t;
	if(t < 0 || t > 5000){
			cout << endl << " t out of range. Abort Program" << endl;
			return 1;
	}
	
	int *cnt = new int[t];
	unsigned int temp_i = 0, temp_j = 0, temp_k = 0;
	for(int i = 0; i < t; i++){
		cnt[i] = 0;
		(*inp) >> temp_i >> temp_j >> temp_k;
		if(temp_i < 0 || temp_i >= n || temp_j < 0 || temp_j >= n){
			cout << endl << " i or j out of range. Abort Program" << endl;
			return 1;
		}
		for(unsigned int j = temp_i; j <= temp_j; j++){
			if(arr[j] > temp_k){
				cnt[i]++;
			}
		}
	}
	
	cout << endl;
	
	for(int i = 0;i < t; i++){
		(*out) << cnt[i] << endl;
	}
	
	
	if(type == 2){
		s.close();
		p.close();
	}
		

	delete []cnt;
	delete []arr;
	return 0;
}
