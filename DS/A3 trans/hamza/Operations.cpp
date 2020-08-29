#include "Operations.h"
#include "node.h"

namespace bst
{

	bool Operations::insert(Data *d)
	{
		insert(d, flag);
		return flag;
	}

	void Operations::insert(Data *d, bool flag)
	{
		root = insert(root,d);
	}

	node *Operations::insert(node *temp, Data *x)
	{
		if (temp == nullptr)
		{
			temp = new node(x);
			flag = true;
		}
		else
		{
		//            System.out.println(x.total_time);
		//            if( (x.start_time > temp.data.start_time) && (x.start_time < temp.data.total_time) )
		//            {
		//                //do nothing
		//                System.out.print(x.start_time+" "+x.duration+" "+x.ctime);
		//                System.out.println();
		//            }

			//this is the main logic
			//implement DATA class, use it in node class
		//            then you can use the below logic for comparison..
		//            don't forget to implement a boolean returning insert function so that you know if value was inserted
		//            in the tree or not
			if (x->start_time >= temp->data->total_time)
			{
				flag = true;
				temp->right = insert(temp->right,x);
			}
			else if (x->total_time < temp->data->start_time)
			{
				flag = true;
				temp->left = insert(temp->left,x);
			}
			else
			{
				std::wcout << x->start_time << L" " << x->duration << L" " << x->ctime;
				std::wcout << std::endl;
				flag = false;
			}
		}
		return temp;
	}

	void Operations::inOrder()
	{
		std::wcout << L"Inorder Traversal" << std::endl;
		inOrder(root);
		std::wcout << std::endl;
	}

	void Operations::inOrder(node *temp)
	{
		if (temp != nullptr)
		{
			inOrder(temp->left);
			std::wcout << temp->data->start_time << L" " << temp->data->duration << L" " << temp->data->ctime;
			std::wcout << std::endl;
			inOrder(temp->right);
		}
	}

	void Operations::postOrder()
	{
		std::wcout << L"Postorder Traversal" << std::endl;
		postOrder(root);
		std::wcout << std::endl;
	}

	void Operations::postOrder(node *temp)
	{
		if (temp != nullptr)
		{
			postOrder(temp->left);
			postOrder(temp->right);
			std::wcout << temp->data->start_time << L" " << temp->data->duration << L" " << temp->data->ctime;
		}
	}

	void Operations::preOrder()
	{
		std::wcout << L"Preorder Traversal" << std::endl;
		preOrder(root);
		std::wcout << std::endl;
	}

	void Operations::preOrder(node *temp)
	{
		if (temp != nullptr)
		{
			std::wcout << temp->data->start_time << L" " << temp->data->duration << L" " << temp->data->ctime;
			preOrder(temp->left);
			preOrder(temp->right);
		}
	}
}
