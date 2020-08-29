/*Safia Baloch: FAST-NUCES*/
#include<iostream>
#include<cstdlib>
using namespace std;

class Node {
public:
   long dData; // data item
	Node *next; // next Node in list

  	Node *previous; // previous Node in list

  Node(long d)
  {
    dData = d;
  }

  void displayNode(){
    cout<<"the data->" <<dData   <<endl;
  }

};
class DoublyNodeedList {
  private:
   Node *first; 

  Node *last; 

  public :
  DoublyNodeedList() {
    first = NULL; 
    last = NULL;
  }

 // insert from front

  void insertFirst(long dd){
    Node *newNode = new Node(dd); 

    if (first==NULL) 
    
//first=newNode;
      last = newNode; 
    else
     
      first->previous = newNode; 
    newNode->next = first;

    first = newNode; 
    //last->next=NULL;
  }
//insert at last "WITH LOGIC ERROR______ please resolve it"
void insertLast(long dd){
    Node *newNode = new Node(dd); 
    if (first==NULL) 
      {
    	last=newNode;
    	newNode->next=NULL;
	  }
    else {
      last->next = newNode; 
      newNode->previous = last; 
    }
    last = newNode;
    	newNode->next=NULL;
  }

// delete from first
 void deleteFirst(){ 
    Node *temp = first;
    if (first->next == NULL) 
      last = NULL; 
    else
    first->next->previous = NULL;
    first = first->next; 
delete temp;
  }

//delete from last


void deleteLast(){ 
    Node *temp = last;
    if (first->next == NULL)
      first = NULL; 
    else
      last->previous->next = NULL;
    last = last->previous; 
    delete temp;
  }

//Delete specific
void delSpecific(int n){
	Node *current=first;
	while(current->next!=NULL){	
		
		if(current->dData==n)
		{
			cout<<"Found node where "<<current->dData<<" exists !\n";
			current->previous->next=current->next;
			current->next->previous=current->previous;
			cout<<"Node deleted!\n\n";
			break;
		}
		current=current->next;
	}
	
}
// display list from first to last

   void displayForward() {
  cout<<"List (first to last): "<<endl;
    Node *current = first; // start at beginning
    while (current != NULL) // until end of list,
    {
      current->displayNode();
      current = current->next; // move to next Node
    }
    cout<<""<<endl;
  }
  // insert After Node->data 
void InsertAfter(long a,long b){
	Node *current=first,*temp=first->next;
	Node *newNode=new Node(b);
	int flag=0;
	while(current->next!=NULL)
	{
		
		if(current->dData==a)
		{
			cout<<current->dData<<endl;
			cout<<"Node found \n";
			current->next=newNode;
			newNode->previous=current;
			newNode->next=temp;
			temp->previous=newNode;
			flag=1;
			break;
		}
		current=current->next;
		temp=temp->next;
	}	
	if(flag==0)
	cout<<"not found";
}
// display list from last to first implement 
 void displayBackward() {
  cout<<"List (Last to first): "<<endl;
    Node *current =last; // start at beginning
    if(current==NULL){
    	cout<<"Empty";
	}
	else{
		 while (current != first->previous) // until end of list,
	    {
	      current->displayNode();
	      current = current->previous; // move to next Node
	    }
    cout<<""<<endl;
  }

	}
   
};
int main()

{
	DoublyNodeedList *list= new DoublyNodeedList();

list->insertFirst(8);

list->insertFirst(888);
	list->displayForward();
	list->insertLast(80);
	list->displayForward();
	list->displayForward();
	//list->deleteKey(0);
//	list->deleteFirst();
//	list->deleteLast();
	list->InsertAfter(888,70);
	list->displayForward();
//		list->InsertAfter(888,70);
	list->displayBackward();
	list->delSpecific(70);
		list->displayBackward();
		list->displayForward();
return 0;
}
