#include<iostream>
using namespace std;
template<class t>
class node
{ 
	private :
		t data;
	node<t>* next;
	public :
		node():data(0),next(0)
		{
		}
		node(t& d):data(d),next(0)
		{
		}		 
		node(t d,node<t>*n):data(d),next(n)
		{
		}
		node<t>* getnext()
		{
			return next;
		}
		void setnext(node<t>*n)
		{
			next=n;
		}
		void setdata(t d)
		{
			data=d;
		}
		t getdata() const
		{
			return data;
		} 
		node(const t&d,const node<t>*n=0)
		{
		}	
};
template<class t>
class sll
{
	private :
		node<t>*head;
		unsigned int size;
		void deleteall()
		{
			node<t>*current=head;
			node<t>*temp=current;
			while(current!=0)
			{
				current=current->getnext();
				temp->setnext(0);
				delete temp;
				temp=current;
			}
			head=0;
		}
	public :
		sll():head(0),size(0)
		{
		}
		sll(sll<t>*rhs)
		{
			head=rhs->head;
			size=rhs->size;			
		}
		~sll()
		{
			deleteall();
		}
		sll(const sll<t>&rhs)
		{
			
			size=rhs.size;
			head=0;
			node<t>*current=rhs.head;
			node<t>*last,*newnode;
			while(current!=0)
			{
				newnode=new node<t>();
				newnode->setdata(current->getdata());
				if(head==0)
				{
					head=newnode;
				}
				else
				{
					last->setnext(newnode);
				}
					last=newnode;
				    current=current->getnext();
			}	
		}

				void Insert(t d)
		{
		node<t> *temp=new node<t>;
			temp->setdata(d);
			temp->setnext(NULL);
			if(head==NULL)
			{
				head=temp;
			temp->setnext(head);
			}
			else
			{
				
			temp->setnext(head->getnext());
			head->setnext(temp);
				head=temp;
				
			}
			size++;
		}
void add_begin(t value)
{
    if (head == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
     node<t> *temp=new node<t>(value);
    //temp->info = value;
    temp->setnext(head->getnext());  //
    head->setnext(temp);  //last node point to first 
}
	
void display()
{
    node<t> *s;
    if (head== NULL)
    {
        cout<<"List is empty, nothing to display"<<endl;
        return;
    }
    s = head->getnext();
    cout<<"Circular Link List: "<<endl;
    while (s != head)
    {
        cout<<s->getdata()<<"->";
        s = s->getnext();
    }
    cout<<s->getdata()<<endl;
}
void InsertAt(t data)
{
	int pos,count=0;
	cout<<" enter postion at which you want to insert "<<endl;
	cin>>pos;
	
    node<t> *prev=NULL;
    node<t> *current=head;
    node<t> *temp=new node<t>;
    temp->setdata(data);
     current=current->getnext();  //always greater one so it back to point head 
	while(count!=pos)
    {
    	prev=current;
    	current=current->getnext();
    	count++;
	}
	 if(count==pos)
        {   //through temp we add value
        	prev->setnext(temp);
        	temp->setnext(current);  //L value required
        }
        else
            cout<<"\nNot Able to Insert";
    }
    

 node<t>* circular() //convert linkedist into circular linkedlist
{ 
    // declare a node variable start and  
    // assign head node into start node. 
    node<t>* start = head; 
  
    // check that while head->next not equal 
    // to NULL then head points to next node. 
    while (head->getnext() != NULL) 
        head = head->getnext(); 
          
    // if head->next points to NULL then  
    // start assign to the head->next node. 
    head->setnext(start);
    return start; 
} 		
bool isCircular() 
{ 
    // An empty linked list is circular 
    if (head == NULL) 
       return true; 
  
    // Next of head 
     node<t> *Node = head->getnext(); 
  
    // This loop would stope in both cases (1) If 
    // Circular (2) Not circular 
    while (Node != NULL && Node != head) 
       Node = Node->getnext(); 
  
    // If loop stopped because of circular 
    // condition 
    return (Node == head); 
} 
int RemoveAt()
{
	int pos,count=0;
	cout<<" enter postion at which you want to remove "<<endl;
	cin>>pos;
	
    node<t> *prev=NULL;
    node<t> *current=head->getnext();  //only assign head to next value  
	while(count!=pos)
    {
    	prev=current;
    	current=current->getnext();
    	count++;
	}
	 if(count==pos)
        {
	 prev->setnext(current->getnext());
		size--;
		}
        else
            cout<<"\nNot Able to remove";
    }
};


int main()
{
	sll <int> l;
	for(int i=6;0<=i;i--)
	{
		l.Insert(i*10);
	}
	l.add_begin(100);
    l.display();
       l.InsertAt(1000);
       l.RemoveAt();
       l.display();

if(l.isCircular())
cout<<endl<<endl<<"circular list"<<endl;
else
cout<<"not circular list "<<endl;


    l.~sll();
    l.display();
}

