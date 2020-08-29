#pragma once

#include <iostream>

//JAVA TO C++ CONVERTER NOTE: Forward class declarations:
#include"node.h"
//#include"Data.h"

namespace bst
{

	/**
	 *
	 * @author Hamza
	 */
	class Operations
	{
	public:
		node *root;
		bool flag = false;
		virtual ~Operations()
		{
			delete root;
		}

		virtual bool insert(Data *d);
		virtual void insert(Data *d, bool flag);
	private:
		node *insert(node *temp, Data *x);
	public:
		virtual void inOrder();
	private:
		void inOrder(node *temp);
	public:
		virtual void postOrder();
	private:
		void postOrder(node *temp);
	public:
		virtual void preOrder();
	private:
		void preOrder(node *temp);
		public:
	//    void search(int key)
	//    {
	//        search(root,key);
	//    }
	//    void search(node temp,int key)
	//    {
	//        if(temp==null)
	//        {
	//            cout<<key<<" is not in the tree";
	//            return;
	//        }
	//        else
	//        {
	//            if(temp.data==key)
	//            {
	//                cout<<key<<" found at "+temp.hashCode();
	//            }
	//            else if(key<temp.data)
	//            {
	//                search(temp.left,key);
	//            }
	//            else if(key>temp.data)
	//            {
	//                search(temp.right,key);
	//            }
	//        }
	////    }
	//    void delete(int key)
	//    {
	//        root=delete(root,key);
	//    }
	//    node delete(node temp,int key)
	//    {
	//        if(temp==null)
	//        {
	//            System.out.println("Data not found");
	//        }
	//        else
	//        {
	//            if(temp.data==key)
	//            {
	//                if(temp.left==null&&temp.right==null)
	//                {
	//                    return null;
	//                }
	//                else if(temp.left==null)
	//                {
	//                    return temp.right;
	//                }
	//                else if(temp.right==null)
	//                {
	//                    return temp.left;
	//                }
	//                else if(temp.left!=null && temp.right!=null)
	//                {
	//                    System.out.println("It has two children"); //code needs fixing here 
	//                    temp.data=getSuccessor(temp.right);
	//                    temp.right=delete(temp.right,temp.data);
	//                }
	//            }
	//            else if(key<temp.data)
	//            {
	//                temp.left=delete(temp.left,key);
	//            }
	//            else if(key>temp.data)
	//            {
	//                temp.right=delete(temp.right,key);
	//            }
	//        }
	//        return temp;
	//    }
	//    int getSuccessor(node temp)
	//    {
	//        while(temp.left!=null)
	//        {
	//            temp=temp.left;
	//        }
	//        return temp.data;
	//    }
	};

}
