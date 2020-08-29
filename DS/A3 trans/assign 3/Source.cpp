#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream ip;                 //reading txt file
ofstream op;
int v1[8], v2[8], v3[8];
template<class T>
class Node {
public:
	T key;
	Node<T> *next, *prev;
	Node() {
		next = prev = 0;
	}
	Node(T k, Node<T>* n = 0, Node<T>* p = 0) {
		key = k;
		next = n;
		prev = p;
	}
};
template<class T>
class LinkedList {
private:
	Node<T>* head, *tail;
public:
	LinkedList() {
		head = tail = 0;
	}
	T headfirst() {
		return head->key;
	}

	void first_out() {
		if (!clear()) {

			Node<T> *n = head;
			if (head == tail)
				head = tail = 0;
			else {
				head = head->next;
				head->prev = 0;
			}
			delete n;
		}
	}

	void addtoend(T key) {
		Node<T> *n = new Node<T>(key);
		if (clear())
			head = tail = n;
		else {
			tail->next = n;
			n->prev = tail;
			tail = n;
		}
	}

	bool clear() {
		return (head == 0 && tail == 0);
	}

};

class find_val {
public:
	int t1, t2, t3, t4;

	find_val *left, *right;
};

class BST {
public:
	find_val *root, *parent, *temp, *child;
	LinkedList<find_val*> task;
	BST()
	{
		root = parent = 0;
	}
	void addval(find_val *&temp, int a, int b, int c) {
		if (temp == NULL) {
			temp = new find_val;
			temp->t1 = a;
			temp->t3 = b;
			temp->t4 = c;
			temp->t2 = a + b + c;
			temp->left = temp->right = NULL;
			return;
		}

		if (a==temp->t1) {
			cout << "!!!Number already there!!!\n";
		}

		else if (a < temp->t1) {
			addval(temp->left, a, b, c);
		}

		else if (a > temp->t1) {
			addval(temp->right, a, b, c);
		}
	}

	void i_or(find_val *ptr)
	{
		if (root == NULL)
		{
			cout << "!!Tree is clear!! \n";
			return;
		}
		if (ptr != NULL)
		{
			i_or(ptr->left);
			task.addtoend(ptr);
			i_or(ptr->right);
		}
	}

	void result()                   //output
	{
		op.open("output.txt");
		cout << "\nCompat. Prog. are:\n";
		op << "\nCompat. Prog. are:\n";
		int val = task.headfirst()->t2;
		cout << task.headfirst()->t1 << "  " << task.headfirst()->t3 << "  " << task.headfirst()->t4 << "\n";
		op << task.headfirst()->t1 << "  " << task.headfirst()->t3 << "  " << task.headfirst()->t4 << "\n";

		task.first_out();
		while (!task.clear())
		{
			if (task.headfirst()->t1 >= val) {
				cout << task.headfirst()->t1 << "  " << task.headfirst()->t3 << "  " << task.headfirst()->t4 << "\n";
				op << task.headfirst()->t1 << "  " << task.headfirst()->t3 << "  " << task.headfirst()->t4 << "\n";

				val = task.headfirst()->t2;
			}
			task.first_out();
		}

		op.close();

	}
};

void runBST();
int main()
{
	runBST();
	system("pause");
}


void info_files(){                               //input	
	ip.open("data1.txt");
	ip >> v1[0];
	ip >> v2[0];
	ip >> v3[0];
	ip.close();
	ip.open("data2.txt");
	ip >> v1[1];
	ip >> v2[1];
	ip >> v3[1];
	ip.close();
	ip.open("data3.txt");
	ip >> v1[2];
	ip >> v2[2];
	ip >> v3[2];
	ip.close();
	ip.open("data4.txt");
	ip >> v1[3];
	ip >> v2[3];
	ip >> v3[3];
	ip.close();
	ip.open("data5.txt");
	ip >> v1[3];
	ip >> v2[3];
	ip >> v3[3];
	ip.close();
}
void runBST() {
	BST var;
	info_files();
	for (int l = 0; l < 8; l++)
	{
		var.addval(var.root, v1[l], v2[l], v3[l]);
	}
	var.i_or(var.root);
	var.result();
}

