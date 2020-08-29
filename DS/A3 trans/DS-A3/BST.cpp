#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>
#include"myQueue.h"
#include"myStack.h"

using namespace std;

class prog_time{
	public:
		int start_time;
		int duration;
		int c_time;
		
		prog_time(){
			start_time=0;duration=0;c_time=0;
		}
		prog_time(int s, int d, int c){
			start_time=s;
			duration=d;
			c_time=c;
		}
		prog_time(prog_time &obj){
			start_time=obj.start_time;duration=obj.duration;c_time=obj.c_time;
		}
		
		bool operator < (prog_time &obj){
			int this_end = this->start_time + this->duration + this->c_time;
			int obj_end = obj.start_time + obj.duration + obj.c_time;
			if((this->start_time < obj.start_time) && (this_end <= obj.start_time)){
				return true;
			}
			return false;
		}
		bool operator >(prog_time &obj){
			int this_end = this->start_time + this->duration + this->c_time;
			int obj_end = obj.start_time + obj.duration + obj.c_time;
			if((this->start_time > obj.start_time) && (this_end > obj.start_time) &&
					this->start_time >= obj_end){
				return true;
			}
			return false;
		}
		bool operator == (prog_time &obj){
			int this_end = this->start_time + this->duration + this->c_time;
			int obj_end = obj.start_time + obj.duration + obj.c_time;
			if(this->start_time == obj.start_time && this_end == obj_end){
				return true;
			}
			return false;
		}
		/*
		bool operator !=(prog_time &obj){
			int this_end = this->start_time + this->duration + this->c_time;
			int obj_end = obj.start_time + obj.duration + obj.c_time;
			if(this->start_time == obj.start_time && this_end == obj_end){
				return false;
			}
			return true;
		}
		*/
		bool operator !=(prog_time &obj){
			int this_end = this->start_time + this->duration + this->c_time;
			int obj_end = obj.start_time + obj.duration + obj.c_time;
			if((this->start_time > obj.start_time) ){
				return true;
			}
			return false;
		}
		prog_time& operator=(prog_time &obj){
			if(&obj==this)
				return obj;
			start_time=obj.start_time;duration=obj.duration;c_time=obj.c_time;
			return obj;
		}
		
		/*
		prog_time operator=(prog_time obj)
			{
				if(obj==*this)
					return obj;
				start_time=obj.start_time;duration=obj.duration;c_time=obj.c_time;
				return obj;
			}
			*/
		friend ostream& operator << (ostream &o, prog_time &obj){
			o << obj.start_time << " " << obj.duration << " " << obj.c_time ;
			return o;
		}
		friend istream& operator >> (istream &i, prog_time &obj){
			i >> obj.start_time >> obj.duration >> obj.start_time ;
			return i;
		}
};

template <typename DTYPE>
class BSTNode{
	public:
		BSTNode<DTYPE> *left,*right;
		DTYPE data;
		
		BSTNode(){
			left=0;
			right=0;
		}
		BSTNode( DTYPE &d, BSTNode<DTYPE> *l = 0, BSTNode<DTYPE> *r = 0){
			this->data = d;
			this->left = l;
			this->right = r;
		}
		friend ostream& operator <<(ostream& o,BSTNode<DTYPE> node){
			o << node.data ;
			return o;
		}
};

template<typename DTYPE>
class BST{
	public:
		BST() {
			root = 0;
		}
		~BST() {
			clear();
		}
		void clear() {
			//clear(root); 
			root = 0;
		}
		bool isEmpty() const {
			return root == 0;
		}
		void preorder() {
			preorder(root); 
		}
		void inorder() {
			inorder(root); 
		}
		void inorder_tofile(ofstream &o){
			inorder_tofile(root,o);
		}
		void postorder() {
			postorder(root); 
		}
		DTYPE* search(const DTYPE& el) const {
			return search(root,el);
		}
		void breadthFirst(); // Figure 6.10
		void iterativePreorder(); // Figure 6.15
		void iterativeInorder(); // Figure 6.17
		void iterativePostorder(); // Figure 6.16
		void MorrisInorder(); // Figure 6.20
		bool insert(DTYPE& el){
			BSTNode<DTYPE> *p = root, *prev = 0;
			while(p != 0){
				prev = p;
				if(el < p->data){
					p = p->left;
					continue;
				}
				else if(el > p->data){
					p = p->right;
					continue;
				}
				return false;
			}
			if(root == 0){
				root = new BSTNode<DTYPE>(el);
				return true;
			}
			else if(el < prev->data){
				prev->left = new BSTNode<DTYPE>(el);;
				return true;
			}
			else if(el > prev->data){
				prev->right= new BSTNode<DTYPE>(el);;
				return true;
			}
			return false;
		}
		bool insert_force(DTYPE& el){
			BSTNode<DTYPE> *p = root, *prev = 0;
			while(p != 0){
				prev = p;
				if(el != p->data){
					p = p->right;
				}
				else{
					p = p->left;
				}
			}
			if(root == 0){
				root = new BSTNode<DTYPE>(el);
				return true;
			}
			else if(el != prev->data){
				prev->right = new BSTNode<DTYPE>(el);
				return true;
			}
			else{
				prev->left= new BSTNode<DTYPE>(el);
				return true;
			}
			return false;
		}  
		void deleteByMerging(BSTNode<DTYPE>*&); // Figure 6.29
		void findAndDeleteByMerging(const DTYPE&); // Figure 6.29
		void deleteByCopying(BSTNode<DTYPE>*&); // Figure 6.32
		void balance(DTYPE*,int,int);
	protected:
		BSTNode<DTYPE>* root;
		void clear(BSTNode<DTYPE>* p);
		DTYPE* search(BSTNode<DTYPE>* p, const DTYPE& el) const{
			while(p != 0){
				if(el == p->data){
					return &p->data;
				}
				else if (el < p->data){
					p = p->left;
				}
				else{
					p = p->right;
				}
			}
			return 0;
		}
		void preorder(BSTNode<DTYPE>* p){
			if(p != 0){
				visit(p);
				preorder(p->left);
				preorder(p->right);
			}
		}
		void inorder(BSTNode<DTYPE>* p){
	
			if(p != 0){
				inorder(p->left);
				visit(p);
			
				inorder(p->right);

			}
			
		}// Figure 6.11
		void inorder_tofile(BSTNode<DTYPE>* p,ofstream &o){
			if(p != 0){
				inorder_tofile(p->left,o);
				o << p->data << endl;
				inorder_tofile(p->right,o);

			}
		}
		void postorder(BSTNode<DTYPE>* p){
			if(p != 0){
				postorder(p->left);
				postorder(p->right);
				visit(p);
			}
		} // Figure 6.11
		virtual void visit(BSTNode<DTYPE>* p) {
			cout << p->data << ' ' << ",";
		}
};

int main(){
	
	queue<prog_time> q;
	
	int type = 0;
	istream *inp;
	ostream *out;
	int test_case = 2; // 1 or 2 // Folder of test case
	int gen=2; // 0-4 First File To Be obtained
	string str_case="case"+ (test_case);
	string dir="test cases\\"+ str_case;
	string temp=dir+"\\manager";
	
	ofstream conflict(dir+"\\myconflict.txt");
	ofstream compatible(dir+"\\mycompatible.txt");
	ofstream o(dir+"\\debug.txt");
	
	while(type==0){
		cout<<"Enter type of input : "<<endl;
		cout<<'\t'<<"1- User input : (input from keyboard - output on screen)"<<endl;
		cout<<'\t'<<"2- filing input : (input from file - output on file)"<<endl;
		cin>>type;
		if(type==2)
		{
			
			int gen = 2;                                      // 0-4
			string ntemp = temp + to_string(gen+1) + ".txt";
			ifstream s(ntemp);
			if(!(s.is_open())){
				cout << temp << " "<< "File NOT FOUND " ;
				return 1;
			}
			inp = &s;
			int inputs = 0;
					
			int progs;
			(*inp) >> progs;
			for(int j = 0; j < progs; j++){
				int s=~0, d=~0, c=~0;
				(*inp) >> s >> d >> c;
				prog_time temp(s,d,c);
				q.push(temp);
			}
			s.close();
			
			for(int i = 0; i < 5 ;i++){
				if(i==gen)
					continue;
				string ntemp = temp + to_string(i+1) + ".txt";
				ifstream s(ntemp);
				if(!(s.is_open())){
					cout << temp << " "<< "File NOT FOUND " ;
					return 1;
				}
				inp = &s;
				int inputs = 0;
					
				int progs;
				(*inp) >> progs;
				for(int j = 0; j < progs; j++){
					int s=~0, d=~0, c=~0;
					(*inp) >> s >> d >> c;
					prog_time temp(s,d,c);
					q.push(temp);
				}
				s.close();
			}
			//q.display_queue();
			
			//out = &p;
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
	
	/*
	string input;
	(*inp) >> input;
	*/
	/*
	int inputs = 0;
	queue<prog_time> q;
	for(int i = 0; i < 2; i++){
		int progs;
		cin >> progs;
		for(int j = 0; j < progs; j++){
			int s, d, c;
			cin >> s >> d >> c;  
			prog_time temp(s,d,c);
			q.push(temp);
		}
	}
	*/
	compatible << "//suppose as per your random called function, file " 
	<< gen << " is read first and then the rest" << endl;
	
	BST<prog_time> tree;
	BST<prog_time> conflict_tree;
	q.sort_except_first();
	//q.display_queue();
	//q.display_queue();
	while(!q.is_empty()){
		prog_time temp(q.peak_end());
		//cout << "-> "<< temp << endl;
		if(!tree.insert(temp)){
			conflict_tree.insert_force(temp);
		}
		q.pop();
	}
	//q.display_queue();
	cout << endl << "Compatible : "; 
	tree.inorder();
	tree.inorder_tofile(compatible);
	cout << endl << "Conflict : "; 
	conflict_tree.inorder() ;
	conflict_tree.inorder_tofile(conflict);
	cout <<endl << "Check Files." << endl;
	return 0;
}
