#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<class T>
class BTNode
{
	public:
		T data;
		BTNode<T> *lchild,*rchild;
			BTNode():data(0){}
			BTNode(T d):data(d),lchild(0),rchild(0){}
			BTNode(T d,BTNode<T> *l,BTNode<T> *r)
			{
				data=d;
				lchild=l;
				rchild=r;
			}
			BTNode<T> *getrchild(){
				return rchild;
			}
			BTNode<T> *getlchild(){
				return lchild;
			}
			T getdata(){
				return data;
			}
};
template<class T>
class BST
{
	private:
		BTNode<T> *root,*current;
		deltree(BTNode<T> *ptr)
		{
			if(ptr!=NULL)
			{
				deltree(ptr->lchild);
				deltree(ptr->rchild);
				ptr->lchild=0;
				ptr->rchild=0;
				delete ptr;
			}
		}
		BTNode<T>* pDeleteNode(BTNode<T>* root,T d)
		{
			if(root==NULL)return root;
			if(d<root->data)
			{
				root->lchild=pDeleteNode(root->lchild,d);
			}
			else if(d>root->data)
			{
				root->rchild=pDeleteNode(root->rchild,d);
			}
			else
			{
				if(root->lchild==NULL)
				{
					BTNode<T>* temp=root->rchild;
					delete root;
					return temp;
				}
				else if(root->rchild==NULL)
				{
					BTNode<T>* temp=root->lchild;
					delete root;
					return temp;
				}
				BTNode<T>* temp=minof(root->rchild);
				root->data=temp->data;
				root->rchild=pDeleteNode(root->rchild,temp->data);
			}
			return root;	
		}
		
		BTNode<T>* pvtsearch(BTNode<T>* root,T d)
		{
			if(root==NULL||root->data==d)return root;
			else if(root->data<d){
				return pvtsearch(root->rchild,d);
			}
			else if(root->data>d){
				return pvtsearch(root->lchild,d);
			}
		}
		
		void pvtinorder(BTNode<T>* x)
		{
			if(x!=NULL)
			{
				pvtinorder(x->lchild);
				cout<<x->data<<" ";
				pvtinorder(x->rchild);
			}
		}
		void pvtpost(BTNode<T>* x)
		{
			if(x==NULL)return;
			pvtpre(x->lchild);
			pvtpre(x->rchild);
			cout<<x->data<<" ";
		}
		void pvtpre(BTNode<T>* x)
		{
			if(x==NULL)return;
			cout<<x->data<<" ";
			pvtpre(x->lchild);
			pvtpre(x->rchild);
		}
		bool isbal(BTNode<T>* x)
		{
			int lht,rht;
			if(x==NULL)return 1;
			lht=height(root->lchild);
			rht=height(root->rchild);
			if(isbal(x->lchild) && isbal(x->rchild) && (abs(lht-rht)<=1))return 1;
			return 0;
		}
		BTNode<T>* LCA(BTNode<T>* root,T a1,T a2)
		{
			BTNode<T>* temp=root;
			if(pvtsearch(root,a1)&&pvtsearch(root,a2))
			{
				if(root==NULL)return NULL;
				if(temp->data>a1 && temp->data>a2)return LCA(root->lchild,a1,a2);
				if(temp->data<a1 && temp->data<a2)return LCA(root->rchild,a1,a2);
				return temp;
			}		
		}
		bool isIdent(BTNode<T>* x,BTNode<T>* y)
		{
			if(x==NULL && y==NULL)return 1;
			if(x!=NULL && y!=NULL)
			{
				return (x->data==y->data && (isIdent(x->lchild,y->lchild) && (isIdent(x->rchild,y->rchild))));
			}
			return 0;
		}
	public:
		
		BST():root(NULL),current(NULL){}		//1.default constructor
		//copy constructor bnana hai
		BST(const BST<T> &rhs)					//2.copy constructor
		{
			
		}
		int height(BTNode<T>* temp){
			if(temp==NULL)return 0;
			else
			return 1+max(height(temp->lchild),height(temp->rchild));
		}
		void insert(T d)						//insert function
		{
			current=root;
			BTNode<T> *parent=0;
			while(current!=0)
			{
				parent=current;
				if(d<current->data){
					current=current->lchild;
				}
				else{
					current=current->rchild;
				}
			}
			if(root==0)
			{
				root=new BTNode<T>(d);
			}
			else
			{
				if(d<parent->data)
				{
					parent->lchild=new BTNode<T>(d);
				}
					
				else
				{
					parent->rchild=new BTNode<T>(d);	
				}		
			}
		}
		bool Identicaltree(BST<T> &a,BST<T> &b)
		{
			return isIdent(a.root,b.root);
		}
		void inorder()								//inorder traversal
		{
			pvtinorder(root);
		}
		void postorder()
		{
			pvtpost(root);
		}
		void preorder(){
			pvtpre(root);
		}
		void search(T d)							//search function
		{
			if(!pvtsearch(root,d))cout<<endl<<d<<" not found!";
			else cout<<endl<<d<<" found!";
		}
		bool isbalanced(){
			if(isbal(root)==1){
				cout<<"\nTree is balanced";
			}
			else if(isbal(root)==0)
			cout<<"\nTree is not balanced";
		}
		T minof()									//min function
		{
			BTNode<T> *temp=root;
			BTNode<T> *parent;
			while(temp!=0){
				parent=temp;
				temp=temp->lchild;
			}
			return (parent->data);
		}
		BTNode<T> * minof(BTNode<T> *temp)
		{
				BTNode<T> *current=temp;
				BTNode<T> *parent;
				while(current!=0){
					parent=current;
					current=current->lchild;
				}
				return (parent);
		}
		T maxof()									//max function
		{
			BTNode<T> *temp=root;
			BTNode<T> *parent;
			while(temp!=0){
				parent=temp;
				temp=temp->rchild;
			}
			return (parent->data);
		}
		BTNode<T>* maxof(BTNode<T> *temp)
		{
					BTNode<T> *current=temp;
					BTNode<T> *parent;
					while(current!=0){
						parent=current;
						current=current->rchild;
					}
					return (parent);
		}
		bool isBST(BTNode<T> *Bnode)							//isBST function
		{
			BTNode<T> *current=Bnode;
			if(root==0)return true;
			if(current->data<minof(current->lchild))return false;
			if(current->data>minof(current->rchild))return false;
			if(!isBST(current->lchild)||!isBST(current->rchild))return false;
		}
		
		void LeastCommonAnc(T a1,T a2){
			BTNode<T> *x=LCA(root,a1,a2);
			cout<<"\nAncestor of "<<a1<<" & "<<a2<<" is: "<<x->data<<endl;
		}
		
		void DeleteNode(T d)
		{
			pDeleteNode(root,d);
		}
		
		~BST()
		{
			deltree(root);
		}
	////////***

};
main()
{
	BST<int> b;
	BST<int> c;
	b.insert(30);
	b.insert(50);
	b.insert(20);
	b.insert(25);
	b.insert(13);
//	b.insert(72);     //uncomment to make tree balanced
	b.insert(13);
	b.insert(10);
	cout<<"InOrder: ";
	b.inorder();
	cout<<endl<<"PostOrder: ";
	b.postorder();
	cout<<endl<<"PreOrder: ";
	b.preorder();
	b.isbalanced();
	b.LeastCommonAnc(50,10);
	b.Identicaltree(b,c)?cout<<"\nTrees are identical":cout<<"\nTrees are not identical";
}
