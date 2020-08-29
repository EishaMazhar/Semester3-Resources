#include<iostream>
#include<fstream>
#include"dyn_safe_arr_lib.cpp"
using namespace std;

template<typename DTYPE>
dyn_safe_arr<DTYPE>& best_sequence(dyn_safe_arr<DTYPE> &obj1,dyn_safe_arr<DTYPE> &obj2){
	int cnt1 = 0, cnt2 = 0;
	int f1 = obj1.filled(), f2 = obj2.filled();
	for(int i = 0; i < f1; i++){
		if(obj1[i] == '*')
			cnt1++;
	}
	for(int i = 0; i < f2; i++){
		if(obj2[i] == '*')
			cnt2++;
	}
	/* For Debugging
	cout << endl << obj1 << " " << f1 << " , "  << cnt1  << " / ";
	cout << " " << obj2 << " " << f2  << " , "  << cnt2 << " = ";
	*/
	if(f1 == f2){
		//cout << ((cnt1 <= cnt2 ) ? obj1:obj2) << endl;
		return (cnt1 <= cnt2 ) ? obj1:obj2;
	}
	else if(f1 > f2){
		return obj1;
	}
	
	//cout << obj2;
	return obj2;
}

int main(){
	int type = 0;
	istream *inp;
	ostream *out;
	ifstream s("CS201-DS-A1TestCasesWitoutput\\P2\\A1P2IO1.txt");
	ofstream p("CS201-DS-A1TestCasesWitoutput\\P2\\A1P2IO1myOUT.txt");
	
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

	dyn_safe_arr<char> a1;
	dyn_safe_arr<char> a2;
	dyn_safe_arr<char> best(80);
 	
	(*inp) >> a1;
	(*inp) >> a2;
	

	int sequences = a1.filled() - a2.filled();
	
	
	for(int l = 0; l < sequences; l++){
		
		int i = l,j = 0,k = 0;
		dyn_safe_arr<char> temp(80);
		while(a2[j] != '\0' && a1[j] != '\0'){
			if(a1[i] == a2[j]){
				while(a1[i] == a2[j] && a2[j] != '\0'&& a1[i] != '\0'){
					temp[k] = a2[j] ;
					k++;
					j++;
					i++;	
				}
				if(a1[i] == a2[j-1]){
					
					temp[k] = '*';
					k++;
				}
				else if( i + 1 < 80&& a2[j] != a1[i+1]){
					break;
				}
					
					
			}
			i++;
			
			if(i >= 80 || j >= 80)
				break;
		}
		
			best = best_sequence<char>(best,temp);
	}
	(*out) << best;
	
	if(type == 2){
		s.close();
		p.close();
	}
	return 0;
}
