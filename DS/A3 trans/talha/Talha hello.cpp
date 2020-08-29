#include<iostream>
#include<fstream>
using namespace std;
class period{
	public:
		int start,ptime,ctime,end;
		period *left,*right;
		period(){
		}
		period(int a,int b,int c):left(0),right(0){
			start	= a;
			ptime = b;
			ctime = c;
			end = a + b + c;
		}
};

class tree
{
	public:
	period *root;
	tree(){
		 root = NULL;
	}
	void inorder(period *current){
		if(current->left!= NULL)
		inorder(current->left);
		
		cout<<current->start<<' '<<current->ptime<<' '<<current->ctime<<endl;
		
		if(current->right!= NULL)
		inorder(current->right);
	}
	
	void push(period *current,period key){
		if(root == NULL){
			root = new period(key.start,key.ptime,key.end);
		}
		else if(key.start <= current->end && key.end <= root->start){//masla
			if(current->left == NULL){
				current->left = new period(key.start,key.ptime,key.end);
			}
			else
				push(current->left,key);
	}
	else if(key.start >= current->end && key.end >= root->start){
		if(current->right == NULL){
				current->right = new period(key.start,key.ptime,key.end);
			}
			else
				push(current->right,key);
	}
	else{
		fstream file;
		file.open("conflict.txt", ios_base::app);
		file<<key.start<<' '<<key.ptime<<' '<<key.ctime<<endl;
		file.close();
			}
	}
};

main()
{
	//conflict file will store the data which is conflicting and the console will show you the data which is campatible and the output will be different because random file  
	tree obj;
	fstream file[5];
	file[0].open("manager1.txt");
	file[1].open("manager2.txt");
	file[2].open("manager3.txt");
	file[3].open("manager4.txt");
	file[4].open("manager5.txt");
	for(int i =0;i<5;i++)
	{
		int c1;
		file[i]>>c1;
		int a,b,c;
		for(int j=0;j<c1;j++){
			file[i]>>a>>b>>c;
			period p(a,b,c);
			obj.push(obj.root,p);
		}
	}	
	obj.inorder(obj.root);
}
