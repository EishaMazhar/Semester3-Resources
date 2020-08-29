#include "BST.h"
#include "Operations.h"
#include "node.h"

namespace bst
{

	void BST::main(std::vector<std::wstring> &args)
	{
		//        Scanner in=new Scanner(System.in);
		std::vector<std::vector<int> >eee={
			std::vector<int> {2, 3, 2},
			std::vector<int> {16, 4, 4},
			std::vector<int> {54, 5, 2},
			std::vector<int> {7, 5, 3},
			std::vector<int> {9, 10, 1},
			std::vector<int> {3, 3, 1},
			std::vector<int> {26, 10, 4},
			std::vector<int> {65, 5, 4}
		};
		Operations *compatible = new Operations();
		Operations *conflicting = new Operations();
		for (int i = 0;i < eee.size();i++)
		{
			Data *data = new Data(eee[i][0],eee[i][1],eee[i][2]);
			if (!compatible->insert(data))
			{
				conflicting->insert(data);
			}

//JAVA TO C++ CONVERTER TODO TASK: A 'delete data' statement was not added since data was passed to a method or constructor. Handle memory management manually.
		}
		std::wcout << L"Compatible Programs" << std::endl;
		compatible->inOrder();
		std::wcout << L"Conflicting Programs" << std::endl;
		conflicting->inOrder();

		//        o.insert(data);
		//        o.inOrder();
		//        o.insert(data1);
		//        o.inOrder();
		//        o.insert(data2);
		//        o.inOrder();
		//        o.insert(data3);
		//        o.inOrder();
		//        o.insert(data4);
		//        o.inOrder();
		//        o.insert(data5);
		//        o.inOrder();
		//        o.insert(data6);
		//        o.inOrder();
		//        o.insert(data7);
		//        o.inOrder();

		//        int choice=0;
		//        while(choice!=7)
		//        {
		//            System.out.println("\n\nChoose any one to continue:\n1.Insert\n2.Delete\n3.Search\n4.Inorder traversal\n5.Preorder traversal\n6.Postorder traversal\n7.Exit");
		//            choice=in.nextInt();
		//            switch(choice)
		//            {
		//                case 1:
		//                {
		//                    System.out.println("Enter value to insert in the tree: ");
		//                    int a=in.nextInt();
		//                    o.insert(a);
		//                    break;
		//                }
		//                case 2:
		//                {
		//                    System.out.println("Enter value to delete from the tree: ");
		//                    int b=in.nextInt();
		//                    o.delete(b);
		//                    break;
		//                }
		//                case 3:
		//                {
		//                    System.out.println("Enter value to search in the tree: ");
		//                    int c=in.nextInt();
		//                    o.search(c);
		//                    break;
		//                }
		//                case 4:
		//                {
		//                    o.inOrder();
		//                    break;
		//                }
		//                case 5:
		//                {
		//                    o.preOrder();
		//                    break;
		//                }
		//                case 6:
		//                {
		//                    o.postOrder();
		//                    break;
		//                }
		//                default:
		//                {
		//                    break;
		//                }
		//            }
		//        }

			delete conflicting;
			delete compatible;
	}
}
main(){
	
}
