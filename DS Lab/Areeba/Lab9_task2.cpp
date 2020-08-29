#include<iostream>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
class Node {
   public:
 int key;
	string name;

	Node *lchld;
	Node *rchld;
public:
	Node(int key, string name) {

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
  Node *root;
	public:
 	void addNode(int key, string name) 
	 {
		// Create a new Node and initialize it
		Node *newNode = new Node(key, name);
		// If there is no root this becomes root
		if (root == NULL) 
		{
			root = newNode;
		}
		 else 
		 {
			// Set root as the Node we will start
			// with as we traverse the tree
			Node *focusNode = root;
			// Future parent for our new Node
			Node *parent;
			while (true) 
			{
				// root is the top parent so we start
				// there
				parent = focusNode;
				// Check if the new node should go on
				// the left side of the parent node
				if (key < focusNode->key) 
				{
				// Switch focus to the left child
					focusNode = focusNode->lchld;
				// If the left child has no children
					if (focusNode == NULL) 
					{
				// then place the new node on the left of it
						parent->lchld = newNode;
						return; // All Done
					}
				}
			else 
			{ // If we get here put the node on the right
					focusNode = focusNode->rchld;
				// If the right child has no children
					if (focusNode == NULL) {
				// then place the new node on the right of it
						parent->rchld = newNode;
						return; // All Done
					}
			}

			}
		}
}
void inOrderTraverseTree(Node *focusNode)//Recursive 
 {

   if(focusNode!=NULL)
   {
   	 inOrderTraverseTree(focusNode->lchld);
   	 cout<<focusNode->name<<"  ";
   	 inOrderTraverseTree(focusNode->rchld);
   }
}
bool BFS(int New)    // Searching With Key Number Not with Name...........
{
	queue<Node*>Q;
	Node *temp=root;
	if(temp!=NULL)
	{
		Q.push(temp);
		while(!Q.empty())
		{
			temp=Q.front();
			if(New==temp->key)
			{
				cout<<"\n"<<temp->name<<"  ";
				return true;
			}
			Q.pop();
			if(temp->lchld!=NULL)
			Q.push(temp->lchld);
			if(temp->rchld!=NULL)
			Q.push(temp->rchld);
		}
	}
	return false;
}
bool DFS(int New)   // Searching with Key Number Not Name..........
{
	stack<Node*>SO;
	Node *temp=root;
	if(temp!=NULL)
	{
		SO.push(temp);
		while(!SO.empty())
		{
			temp=SO.top();
			if(New==temp->key)
			{cout<<"\n"<<temp->name<<"  ";
			  return true;
			}
			SO.pop();
			if(temp->lchld!=NULL)
			SO.push(temp->lchld);
			if(temp->rchld!=NULL)
			SO.push(temp->rchld);
		}
	}
	return false;
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
    cout<<"InOrderTraverse Recursive :\n";
	theTree->inOrderTraverseTree(theTree->root);
    cout<<"\n\nBFS :";
    bool b=theTree->BFS(50);
        if(b==true)
        cout<<" Found";
        else
        cout<<"\nNot Found";
    cout<<"\nDFS :";
	bool d=theTree->DFS(25);
      if(d==true)
      cout<<" Found";
      else
      cout<<"\nNot Found";
return 0;
}
