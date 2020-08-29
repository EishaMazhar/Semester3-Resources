#include<iostream>
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
};
template<class T>
class BTree
{
	private:
		BTNode<T> *root;
		BTNode<T> *current;
		
		DeleteTree(BTNode<T> *ptr)
		{
			if(ptr!=NULL)
			{
				DeleteTree(ptr->rchild);
				DeleteTree(ptr->lchild);
				ptr->lchild=0;
				ptr->rchild=0;
				delete ptr;
			}
		}
		
	public:
		BTree():root(0),current(0){}
		BTree(const BTree<T> &rhs);
		BTree &operator=(const BTree<T> &rhs);
		
		void insert(T d)
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
					parent->lchild=new BTNode<T>(d);
				else
					parent->rchild=new BTNode<T>(d);
				
			}
			
		}
		T minof(){
			current=root;
			BTNode<T> *parent=0;
			while(current!=0)
			{
				parent=current;
				current=current->lchild;
			}
			return (parent->data);
		}
		T maxof(){
			BTNode<T> *current=root;
			BTNode<T> *parent=0;
			while(current!=0)
			{
				parent=current;
				current=current->rchild;
			}
			return (parent->data);
		}
		bool isBST(BTNode<T> *BTree)
		{
			BTNode<T> *current=BTree;
			if(root==0)return true;
			if(current->data < minof(current->getlchild()))
			{
				return false;
			}
			if(current->data > maxof(current->getrchild()))
			{
				return false;
			}
			if(!isBST(current->getlchild())||!isBST(current->getrchild()))
			{
				return false;
			}	
		}
		
		~BTree()
		{
			DeleteTree(root);
			cout<<"Deleted";
		}
		
};
int main()
{
	BTree<int> b;

	b.insert(21);
	b.insert(32);
	b.insert(54);
	b.insert(10);
		return 0;
}
