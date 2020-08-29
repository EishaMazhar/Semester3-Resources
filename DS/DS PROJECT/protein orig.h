//#include<bits/stdc++.h>
//#include<iostream>
//using namespace std;
//class p_data
//{
//	public:
//	int c;
//	int p_a[2];
//	int p_b[2];
//	int p_t;
//	float b[4];
//	int a_class[2];
//	int b_class[2];
//	int p4_a;
//	int p4_b;
//	int p4_t;
//	
//	p_data()
//	{
//	}
//	p_data(int c1,int pa0,int pa1,int pb0,int pb1,int pt,float g,float h,float i,float j,int ac1,int ac2,int bc1,int bc2,int p4a,int p4b,int p4t){
//	
//			c=c1;
//			
//			p_a[0]=pa0;
//			p_a[1]=pa1;
//			
//			p_b[0]=pb0;
//			p_b[1]=pb1;
//			
//			p_t=pt;
//			
//			b[0]=g;
//			b[1]=h;
//			b[2]=i;
//			b[3]=j;
//			
//			a_class[0]=ac1;
//			a_class[1]=ac2;
//			
//			b_class[0]=bc1;
//			b_class[1]=bc2;
//			
//			p4_a=p4a;
//			p4_b=p4b;
//			p4_t=p4t;
//	}
//	void set(int c1,int pa0,int pa1,int pb0,int pb1,int pt,float g,float h,float i,float j,int ac1,int ac2,int bc1,int bc2,int p4a,int p4b,int p4t)
//	{
//			c=c1;
//			
//			p_a[0]=pa0;
//			p_a[1]=pa1;
//			
//			p_b[0]=pb0;
//			p_b[1]=pb1;
//			
//			p_t=pt;
//			
//			b[0]=g;
//			b[1]=h;
//			b[2]=i;
//			b[3]=j;
//			
//			a_class[0]=ac1;
//			a_class[1]=ac2;
//			
//			b_class[0]=bc1;
//			b_class[1]=bc2;
//			
//			p4_a=p4a;
//			p4_b=p4b;
//			p4_t=p4t;
//	
//	}
//};
//class BTNode
//{
//	public:
//		p_data *data;
//		BTNode *lchild;
//		BTNode *rchild;
//		friend class BST;
//		BTNode()
//		{
//			lchild=0;
//			rchild=0;
//		}
//		BTNode(p_data *d){
//			data = d;
//			lchild=NULL;
//			rchild=NULL;
//		}
////		BTNode(p_data *d,BTNode *obj1=0, BTNode *obj2=0){
////			data = d;
////			lchild = obj1;
////			rchild = obj2;
////		}
//	

//};
//class BST{
//	protected:
//		BTNode *root;
//		
//	public:
//		BST(){}
//			void insert(p_data *d)
//			{
//				BTNode *newChild,*current,*parent;
//				current=root;
//				parent=0;
//				newChild = new BTNode(d);
//				while(current!=0){
//					parent=current;
//					if(d->c < current->data->c){
//						current=current->lchild;
//					}
//					else{
//						current=current->rchild;
//					}
//				}
//				if(root==0){
//					root=newChild;
//				}
//				else
//				{
//					if(d->c < parent->data->c)
//					{
//						parent->lchild=newChild;
//					}
//					else
//					{
//						parent->rchild=newChild;
//					}
//				}
//		}
//		
//	
//};

struct p_data
{
	int c;
	int p_a[2];
	int p_b[2];
	int p_t;
	float b[4];
	int a_class[2];
	int b_class[2];
	int p4_a;
	int p4_b;
	int p4_t;
	
};

// http://prowl.rockefeller.edu/aainfo/chou.htm structural properties of amino acids
struct p_data data[]=
{	
	'A', 142, 139, 83, 79, 66, 0.06, 0.076, 0.035, 0.058, 'H', 'H', 'i', 'i', 0, 0, 0,
	'R', 98, 100, 93, 94, 95, 0.070, 0.106, 0.099, 0.085, 'i', 'H', 'i', 'i', 0, 0, 0,
	'N', 67, 78, 89, 66, 156, 0.161, 0.083, 0.191, 0.091, 'b', 'i', 'i', 'b', 0, 0, 0,
	'D', 101, 106, 54, 66, 146, 0.147, 0.110, 0.179, 0.081, 'I', 'h', 'B', 'b', 0, 0, 0,
	'C', 70, 95, 119, 107, 119, 0.149, 0.050, 0.117, 0.128, 'i', 'i', 'h', 'h', 0, 0, 0,
	'Q', 111, 112, 110, 100, 98, 0.074, 0.098, 0.037, 0.098, 'h', 'h', 'h', 'I', 0, 0, 0,
	'E', 151, 144, 37, 51, 74, 0.056, 0.060, 0.077, 0.064, 'H', 'H', 'B', 'b', 0, 0, 0,
	'G', 57, 64, 75, 87, 156, 0.102, 0.085, 0.190, 0.152, 'B', 'B', 'b', 'i', 0, 0, 0,
	'H', 100, 112, 87, 83, 95, 0.140, 0.047, 0.093, 0.054, 'I', 'h', 'i', 'i', 0, 0, 0,
	'I', 108, 99, 160, 157, 47, 0.043, 0.034, 0.013, 0.056, 'h', 'i', 'H', 'H', 0, 0, 0,
	'L', 121, 130, 130, 117, 59, 0.061, 0.025, 0.036, 0.070, 'H', 'H', 'H', 'h', 0, 0, 0,
	'K', 116, 121, 74, 73, 101, 0.055, 0.115, 0.072, 0.095, 'h', 'h', 'b', 'b', 0, 0, 0,
	'M', 145, 132, 105, 101, 60, 0.068, 0.082, 0.014, 0.055, 'H', 'H', 'h', 'I', 0, 0, 0,
	'F', 113, 111, 138, 123, 60, 0.059, 0.041, 0.065, 0.065, 'h', 'h', 'h', 'h', 0, 0, 0,
	'P', 57, 55, 55, 62, 152, 0.102, 0.301, 0.034, 0.068, 'B', 'B', 'B', 'B', 0, 0, 0,
	'S', 77, 72, 75, 94, 143, 0.120, 0.139, 0.125, 0.106, 'i', 'B', 'B', 'i', 0, 0, 0,
	'T', 83, 78, 119, 133, 96, 0.086, 0.108, 0.065, 0.079, 'i', 'i', 'h', 'h', 0, 0, 0,
	'W', 108, 103, 137,124, 96, 0.077, 0.013, 0.064, 0.167, 'h', 'I', 'h', 'h', 0, 0, 0,
	'Y', 69, 73, 147,131, 114, 0.082, 0.065, 0.114, 0.125, 'b', 'b', 'H', 'h', 0, 0, 0,
	'V', 106, 97, 170, 164, 50, 0.062, 0.048, 0.028, 0.053, 'H', 'i', 'H', 'H', 0, 0, 0,
};




















