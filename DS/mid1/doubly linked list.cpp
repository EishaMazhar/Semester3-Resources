#include<iostream>
using namespace std;
template<class t>
class node
{ 
	private :
		t data;
	node<t>* next;
	node<t>* prev;
	public :
		node():data(0),next(0),prev(0)
		{
		}
		node(t& d):data(d),next(0),prev(0)
		{
		}		 
		node(t d,node<t>*n,node<t>*p):data(d),next(n),prev(p)
		{
		}
		node<t>* getnext()
		{
			return next;
		}
		node<t>* getprev()
		{
			return prev;
		}
		
		void setnext(node<t>*n)
		{
			next=n;
		}
		void setprev(node<t>*p)
		{
			prev=p;
		}
		void setdata(t d)
		{
			data=d;
		}
		t getdata() const
		{
			return data;
		} 
		node(const t&d,const node<t>*n=0,const node<t>*p=0)
		{
		}	
};
template<class t>
class DLL
{
	node<t>* head;
	unsigned int size;
void deleteall()
		{
			node<t>  *current=head;
			node<t>  *temp=current;
			while(current!=0)
			{
				current=current->getnext();
				temp->setnext(0);
				temp->setprev(0);
				delete temp;
				temp=current;
			}
			head=0;
		}
	public:
	DLL()
	{
		head=NULL;
		size=0;
	}
	DLL(DLL<t> *rhs)
	{
		head=rhs->head;
	   size=rhs->size;
	}
	void setsize(int size)
	{
		size=size;
	}
//node<t>* getnode(t x)
//{	
//    node<t> *newnode=new node<t>;
//	return(newnode);
//	}	
	void InsertAtHead(t d)
{
	
	node<t> *newnode=new node<t>;
		newnode->setdata(d);
	newnode->setnext(NULL);
	newnode->setprev(NULL);
    if(head==NULL)
    	head=newnode;
	else
	{
		head->setprev(newnode);
		newnode->setnext(head);
		head=newnode;
	}
}
void display()
{
	if(head==NULL)
	cout<<"list is empty";
	else
	{
		node<t> *current=head;
		while(current!=NULL)
		{
		cout<<current->getdata()<<"-->";
	    current=current->getnext();
		}
	}
}
void reverse()
{
	node<t> *current=head;
	if(head==NULL)
	cout<<"empty list no need  reverse"<<endl; 
    	while(current->getnext()!=NULL)
    	{
    		current=current->getnext(); //go tolast node
		}
		
		while(current!=NULL)
		{
			cout<<current->getdata()<<" -->";
			current=current->getprev();
		}
}
void DeleteFirst()
{
	node<t> *temp=new node<t>;
	temp=head;
	head=head->getnext();
	delete(temp);
	head->setprev(NULL);      
}
void DeleteLast()
{
	node<t>  *last=new node<t>;
	node<t> *temp=head;
	while(temp->getnext()!=NULL)
	temp=temp->getnext();
	
	last=temp->getprev();
     last->setnext(NULL);
	delete(temp);
}
~DLL()
{
	deleteall();
}
	DLL<t>& splithalf()
		{
			node<t>*onestep=head;
			node<t>*twostep=head;
			if(size%2!=0)
			{
				while((twostep->getnext()!=0))
				{
					onestep=onestep->getnext();
					twostep=twostep->getnext()->getnext();
				}
				this->setsize((size/2)+1);
			}
			if(size%2==0)
			{
				while((twostep!=0))
				{
					onestep=onestep->getnext();
					twostep=twostep->getnext()->getnext();
				}
				this->setsize((size/2));	
			}
			this->head=onestep;
			return(*this);
		}	
void removeDuplicates() 
{ 
    node<t> *ptr1, *ptr2, *dup; 
    ptr1 = head; 
  
    /* pick elements one by one */
    while (ptr1 != NULL && ptr1->getnext() != NULL) 
    { 
        ptr2 = ptr1; 
  
        /* Compare the picked element with rest of the elements */
        while (ptr2->getnext() != NULL) 
        { 
            /* If duplicate then delete it */
            if (ptr1->getdata() == ptr2->getnext()->getdata()) 
            { 
                /* sequence of steps is important here */
                dup = ptr2->getnext(); 
                ptr2->setnext(ptr2->getnext()->getnext()); 
                delete(dup); 
            size--;
			} 
            else /* This is tricky */
                ptr2 = ptr2->getnext();
        }
        ptr1 = ptr1->getnext(); 
    }
}
};
int main()
{
	DLL<int> d1;
    d1.InsertAtHead(2);
    d1.InsertAtHead(4);
    d1.InsertAtHead(6);
    d1.InsertAtHead(8);
    d1.InsertAtHead(10);
    d1.InsertAtHead(10);
    d1.InsertAtHead(12);

d1.display();
cout<<endl<<"delete last element "<<endl;
d1.DeleteLast();
//    d1.DeleteFirst();
	d1.display();
    cout<<endl<<"reverse "<<endl;
    d1.reverse();
    cout<<endl<<"remove duplicate "<<endl;
	d1.removeDuplicates();
    d1.display();
    
    cout<<endl<<"split half "<<endl;
    d1.splithalf();
    d1.display();
    
cout<<endl<<"delete all elemeent "<<endl;
d1.~DLL();
d1.display();
}
