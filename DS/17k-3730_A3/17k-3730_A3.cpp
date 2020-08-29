#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
ofstream nonover,overlapping;
template <class T>
class BST;
class DATA
{
	public:
	    int start_time;
		int duration;
		int ctime;
		int total_time;
		DATA(int a, int b, int c)
		{
			start_time=a;
			duration=b;
			ctime=c;
			total_time=a+b+c;
		}
};

template <class T>
class BTNode
{
	public:
		DATA *data;
		BTNode<T> *lchild;
		BTNode<T> *rchild;
		
		friend class BST<T>;	
	
		BTNode(){
			lchild = 0;
			rchild = 0;
		}
		
		BTNode(DATA *d, BTNode<T> *obj1=0, BTNode<T> *obj2=0){
			data = d;
			lchild = obj1;
			rchild = obj2;
		}
	
};

template <class T>
class BST{
	protected:
		BTNode<T> *root;
		queue<BTNode<T>*> q,tq;
		queue<BTNode<T>*> conf,nconf;
		void inorder(BTNode<T> *x)
		{
			if(x!=0){
				inorder(x->lchild);
	//			cout<<x->data->start_time<<" "<<x->data->duration<<" "<<x->data->ctime<<endl; 
				q.push(x);
				inorder(x->rchild);
			}
		}
	public:
	
		BST(){
			root = 0;
		}
		
		~BST(){}
		void programs()
		{
			nonover.open("NonConflictingPrograms.txt");
			overlapping.open("ConflictingPrograms.txt");
			BTNode<T> *c,*nc;
	//		cout<<"\nnonconflicting programs:\n";
			nonover<<"\nnonconflicting programs:\n";
			
			while(nconf.empty()==false)
			{
				nc=nconf.front();
	//			cout<<nc->data->start_time<<" "<<nc->data->duration<<" "<<nc->data->ctime<<endl;
				nonover<<nc->data->start_time<<" "<<nc->data->duration<<" "<<nc->data->ctime<<endl;
				nconf.pop();
			}
			
	//		cout<<"\nconflicting programs:\n";
			overlapping<<"\nconflicting programs:\n";
			while(conf.empty()==false)
			{
				c=conf.front();
		//		cout<<c->data->start_time<<" "<<c->data->duration<<" "<<c->data->ctime<<endl;
				overlapping<<c->data->start_time<<" "<<c->data->duration<<" "<<c->data->ctime<<endl;
				conf.pop();
			}
		}
		void insert(DATA *d){
			BTNode<T> *newChild,*current,*parent;
			current=root;
			parent=0;
			newChild = new BTNode<T>(d);
			while(current!=0){
				parent=current;
				if(d->start_time<current->data->start_time){
					current=current->lchild;
				}
				else{
					current=current->rchild;
				}
			}
			if(root==0){
				root=newChild;
	//			cout<<root->data->start_time<<", "<<root->data->duration<<", "<<root->data->ctime<<endl;
			}
			else{
				if(d->start_time<parent->data->start_time){
					parent->lchild=newChild;
	//				cout<<parent->lchild->data->start_time<<", "<<parent->lchild->data->duration<<", "<<parent->lchild->data->ctime<<endl; 
				}
				else{
					parent->rchild=newChild;
	//				cout<<parent->rchild->data->start_time<<", "<<parent->rchild->data->duration<<", "<<parent->rchild->data->ctime<<endl; 
				}
			}
		}
		void distributequeue(){
			BTNode<T> *trav=root,parent,temp;
			int y=trav->data->total_time;
			int x=trav->data->start_time;
		
			while(q.empty()==false)
			{
				trav=q.front();
				if((trav->data->start_time<x && trav->data->total_time>y)||(trav->data->start_time<y && y<=trav->data->total_time)||(x<trav->data->start_time&&y>trav->data->total_time)||(x>trav->data->start_time&&y<trav->data->total_time))
				//trav->data->start_time<y && trav->data->total_time<x)||(trav->data->start_time>y && trav->data->total_time>y
				{
					conf.push(trav);
					q.pop();  
						trav=q.front();
				}
//				if(trav->data->start_time>z && trav->data->total_time<y)
//				{
//					conf.push(trav);tq.pop();           //push into conflict and pop from "tq"
//				}
				else{
					nconf.push(trav);
					q.pop();
					y=trav->data->total_time;
				}
			
			}
		}
		void Inorder(){
			inorder(root);
		}		
};

int main(){
	
//	int size1,size2,size3,size4,size5,total=0;
//	int program[16][3];
//	fstream m1,m2,m3,m4,m5;
//	m1.open("Manager1.txt");
//	m1>>size1;
//	for(int i=0;i<size1;i++){
//		for(int j=0;j<3;j++){
//			m1>>program[i][j];
//			
//		}
//	}
//	m1.close();
//	m2.open("Manager2.txt");
//	m2>>size2;
//	for(int i=0;i<4;i++){
//		for(int j=0;j<3;j++){
//			m2>>program[i][j];
//		}
//	}
//	m2.close();
//	m3.open("Manager3.txt");
//	m3>>size3;
//		for(int i=0;i<2;i++){
//		for(int j=0;j<3;j++){
//			m3>>program[i][j];
//		}
//	}
//	m3.close();
//	
//	m4.open("Manager4.txt");
//	m4>>size4;
//	for(int i=0;i<3;i++){
//		for(int j=0;j<3;j++){
//			m4>>program[i][j];
//		}
//	}
//	m4.close();
//	m5.open("Manager5.txt");
//	m5>>size5;
//	for(int i=0;i<4;i++){
//		for(int j=0;j<3;j++){
//			m5>>program[i][j];
//		}
//	}
//	m5.close();
//	total = size1+size2+size3+size4+size5;
//	
////	cout<<total<<endl;
//
	
	fstream f[5];
	BST<int> obj;
	int a,b,c;

	f[0].open("Manager1.txt");
	f[1].open("Manager2.txt");
	f[2].open("Manager3.txt");
	f[3].open("Manager4.txt");
	f[4].open("Manager5.txt");
	
	for(int i =0;i<5;i++)
	{
		int size;
		f[i]>>size;
		int a,b,c;
		for(int j=0;j<size;j++){
			f[i]>>a>>b>>c;
			DATA *d=new DATA(a,b,c);
			obj.insert(d);
		}
	}
	
	obj.Inorder();
	obj.distributequeue();
	obj.programs();
	cout<<"..k";
}

