#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;
template <typename T>
class BT{
	
	public:
		BT<T> *leftChild,*rightChild;
		T total_time;
		T start_time,duration_time,commercial_time;
		BT(){
			start_time = 0;
			duration_time = 0;
			commercial_time = 0;
			leftChild = NULL;
			rightChild = NULL;
		}
		BT(const T s,const T d,const T c,BT<T> *obj = NULL,BT<T> *obj1 = NULL)
		{
			start_time = s;
			duration_time = d;
			commercial_time = c; 
			leftChild = obj;
			rightChild = obj1;
			total_time=start_time+duration_time+commercial_time;
		}
		
};
template <typename T>
class BST{
	
	protected:
		BT<T> *root,*root2;
		queue<BT<T> *> stdqueue,conflict,nonConflict,tempqueue;
			void inorder(BT<T> *current){
			if(current != NULL){
				inorder(current->leftChild);
				visited(current);
				stdqueue.push(current);
				inorder(current->rightChild);
			}
		}
	
	public:
		BST(){
			root = NULL;
			root2 = NULL;
		}
		void Update(const T s,const T d,const T c){
			root=NULL;
			BT<T> *newChild,*parent,*current;
			current = root2;
			newChild = new BT<T> (s,d,c);
			while(current != NULL){
				parent = current;
				if(s < current->start_time){
					current = current->leftChild;
				}
				else{
					current = current->rightChild;
				}				
			}
			if(root2 == NULL){
				root2 = newChild;
				cout<<"Root : "<<root2->start_time<<endl;
				cout<<root2->start_time<<" "<<root2->duration_time<<" "<<root2->commercial_time<<endl;
			}
			else{
				if(s < parent->start_time){
					parent->leftChild = newChild;
					cout<<"Parent : "<<parent->start_time<<" LeftChild : "<<parent->leftChild->start_time<<endl;
					cout<<parent->leftChild->start_time<<" "<<parent->leftChild->duration_time<<" "<<parent->leftChild->commercial_time<<" "<<endl;
				}
				else{
					parent->rightChild = newChild;
					cout<<"Parent : "<<parent->start_time<<" RightChild : "<<parent->rightChild->start_time<<endl;
					cout<<parent->rightChild->start_time<<" "<<parent->rightChild->duration_time<<" "<<parent->rightChild->commercial_time<<endl;
				}
			}
		}
		
		void Insertion(const T s,const T d,const T c){
			BT<T> *newChild,*parent,*current;
			current = root;
			newChild = new BT<T> (s,d,c);
			while(current != NULL){
				parent = current;
				if(s < current->start_time){
					current = current->leftChild;
				}
				else{
					current = current->rightChild;
				}				
			}
			if(root == NULL){
				root = newChild;
				cout<<root->start_time<<" "<<root->duration_time<<" "<<root->commercial_time<<endl;
			}
			else{
				if(s < parent->start_time){
					parent->leftChild = newChild;
					cout<<parent->leftChild->start_time<<" "<<parent->leftChild->duration_time<<" "<<parent->leftChild->commercial_time<<" "<<endl;
				}
				else{
					parent->rightChild = newChild;
					cout<<parent->rightChild->start_time<<" "<<parent->rightChild->duration_time<<" "<<parent->rightChild->commercial_time<<endl;
				}
			}
		}
		
		virtual void visited(BT<T> *current)
		{
			cout<<current->start_time<<" "<<current->duration_time<<" "<<current->commercial_time<<endl;
		}
		
		void InorderTraversal(){
			cout<<"\nInorder Traversal."<<endl;
			BT<T> *current = root;
			inorder(root);
		}
	
		void search(){
			BT<T> *temp, *parent ,*current=root;
			int d=0;
			d = current->total_time;
			while(!stdqueue.empty()){
				current = stdqueue.front();
				if( current->total_time == d){
					nonConflict.push(current);
					stdqueue.pop();
					current = stdqueue.front();
				}
				tempqueue.push(current);
				stdqueue.pop();
			}
			while(!tempqueue.empty()){
				
				current = tempqueue.front();
				if( current->start_time < d ){
					conflict.push(current);
//					visited(current);
					tempqueue.pop();
//					current = tempqueue.front();
				}
				else{
					current = tempqueue.front();
					nonConflict.push(current);
					tempqueue.pop();
					d = current->total_time;
				}			
			}
		}
		void overlaping(){
			cout<<"\nOverlaping Intervals.\n";
			BT<T> *current; 
			int i=0;
			while(!conflict.empty()){
				i++;
				current = conflict.front();
				cout<<i<<" : ";
				visited(current);
				
				conflict.pop();
			}
		}
		void nonOverlaping(){
			cout<<"\nNonOverlaping Intervals.\n";
			BT<T> *current; 
			while(!nonConflict.empty()){
				current = nonConflict.front();
//				visited(current);
				Update(current->start_time,current->duration_time,current->commercial_time);
				nonConflict.pop();
			}
		}
};

int main(){
	
	int size,size1;
	fstream file,file1;
	file.open("Manager1.txt",ios::in);
	file1.open("Manager2.txt",ios::in);
	file>>size;
	file1>>size1;
	size +=size1;
	int COLS = 3,row=0;
	vector < vector <int> > array;
	vector <int> rowVector(COLS);
	if (file.is_open())
	{
		cout<<"File correctly opened"<<endl;
		while(file.good()){
			array.push_back(rowVector);
			for(int col=0;col<COLS;col++)
			{
				file >> array[row][col];
			}
			row++;
		}
	}
	
	else cout<<"Unable to open file"<< endl;
	file.close();     
	if (file1.is_open()){
		cout << "File correctly opened" << endl;
		while (file1.good()){
			array.push_back(rowVector);
			for (int col=0; col<COLS; col++) {
				file1>>array[row][col];
			}
			row++;
		}
	}
	else cout<< "Unable to open file" << endl;
	file1.close();     
	int start,dur,com;
	BST<int> bst;
	for(int i=0;i<size;i++){
		start=array[i][0];			
		dur=array[i][1];	
		com=array[i][2];
		bst.Insertion(start,dur,com);	
	}
	cout<<endl;
	bst.InorderTraversal();
	bst.search(); 
	bst.overlaping();
	bst.nonOverlaping();
}
