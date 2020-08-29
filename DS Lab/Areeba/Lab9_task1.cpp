#include<bits/stdc++.h>
#include<stack>
using namespace std;
class myNode
{
    public:
    int key;
	string name;
	myNode*lchld;
	myNode*rchld;
      public:
	myNode(int key,string name) {

		this->key = key;
		this->name = name;

	}
string toString() {

		cout<<name<< " has the key " <<key<<endl;
        }
		
};

class BinaryTree 
{
   public:
  myNode*root;
	public:
 	void addNode(int key, string name) 
	 {
		
		myNode* newNode = new myNode(key,name);
		if (root == NULL) 
		{
			root = newNode;
		}
		 else 
		 {
			myNode*focusNode = root;
			myNode *parent;
			while(true) 
			{
				parent = focusNode;
				if (key < focusNode->key) 
				{
					focusNode = focusNode->lchld;
					if (focusNode == NULL) 
					{
						parent->lchld = newNode;
						return;
					}
				}
			else 
			{
					focusNode = focusNode->rchld;
					if (focusNode == NULL)
					{
						parent->rchld = newNode;
						return; 
					}
			}

			}
		}
}
void inOrderTraverseTree(myNode*focusNode)//Recursive 
 {

   if(focusNode!=NULL)
   {
   	 inOrderTraverseTree(focusNode->lchld);
   	 cout<<focusNode->name<<"  ";
   	 inOrderTraverseTree(focusNode->rchld);
   }
}
void preorderTraverseTreeNR(myNode*focusNode) //Recursive
{		
	if (focusNode != NULL) 
	{
		cout<<focusNode->name<<"  ";
		preorderTraverseTreeNR(focusNode->lchld);
		preorderTraverseTreeNR(focusNode->rchld);
	}
}
void postOrderTraverseTree(myNode*focusNode) //Recursive
{
   if(focusNode!=NULL)
   {
   	  postOrderTraverseTree(focusNode->lchld);
   	  postOrderTraverseTree(focusNode->rchld);
   	  cout<<focusNode->name<<"  ";
   }
}

void IterativeInOrderTraverseTreeNR()//Non Recursive 
{
  stack<myNode*> travstack;
  myNode*temp=root;
  while(temp!=NULL||travstack.empty()==false)
  {
  	while(temp!=NULL)
  	{
  		travstack.push(temp);
  		temp=temp->lchld;
	}
	temp=travstack.top();
	travstack.pop();  
	cout<<temp->name<<"  ";
	temp=temp->rchld;
  }
}
void IterativePreorderTraverseTreeNR()// Non Recursive
{
   stack<myNode*>SO;
   myNode*temp=root;
 if(temp!=NULL)
 {
 	SO.push(temp);
 	while(!SO.empty())
 	{
 		temp=SO.top();
 		cout<<temp->name<<"  ";
 		SO.pop();
 		if(temp->rchld!=NULL)
 		SO.push(temp->rchld);
 		if(temp->lchld!=NULL)
 		SO.push(temp->lchld);
	}
 }
}
void IterativePostOrderTraverseTreeNR()
{
   stack<myNode*>SO;
   myNode*temp=root;
   myNode*temp2=root;
   while(temp!=NULL)
   {
   	 for(;temp->lchld!=0;temp=temp->lchld)
   	      SO.push(temp);
   	    while(temp->rchld==0||temp->rchld==temp2)
   	    {
   	    	cout<<temp->name<<"  ";
   	    	temp2=temp;
   	    	if(SO.empty())
   	    	return;
   	    	temp=SO.top();
   	        SO.pop();
	    }
	    SO.push(temp);
	    temp=temp->rchld;
   }
}
};
int main() 
{
   BinaryTree *theTree = new BinaryTree();

	theTree->addNode(50, "Boss");

	theTree->addNode(25, "Vice President");

	theTree->addNode(15, "Office Manager");

	theTree->addNode(30, "Secretary");

	theTree->addNode(75, "Sales Manager");

	theTree->addNode(85, "Salesman 1");

	// Different ways to traverse binary trees
    cout<<"InOrderTraverse Recursive :\n";
	theTree->inOrderTraverseTree(theTree->root);
	cout<<"\nPreOrderTraverse Recursive :\n";
	theTree->preorderTraverseTreeNR(theTree->root);
	cout<<"\nPostOrderTraverse Recursive :\n";
	theTree->postOrderTraverseTree(theTree->root);
	
	cout<<"\n\n";
	cout<<"\nInOrder in Iterative :\n";
 	theTree->IterativeInOrderTraverseTreeNR();
 	cout<<"\nPreOrder in Iterative :\n";
 	theTree->IterativePreorderTraverseTreeNR();
	cout<<"\nPostOrder in Iterative :\n";
 	theTree->IterativePostOrderTraverseTreeNR();

return 0;
}

