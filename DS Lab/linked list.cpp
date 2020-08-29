#include <iostream>
#include <cstdlib>


class Node
{
public:
    Node* next;
    int data;
};

using namespace std;

class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList(){
    	this->length = 0;
    this->head = NULL;
    }
    ~LinkedList(){
    	cout << "LIST DELETED";
    }
    void add(int data){
    	Node* node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
    this->length++;
    }
    void print()
    {
    	Node* head = this->head;
    int i = 1;
    while(head){
        cout << i << ": " << head->data << endl;
        head = head->next;
        i++;
    }

    }
};

int main()
{
    LinkedList* list = new LinkedList();
    for (int i = 0; i < 10; ++i)
    {
        list->add(rand() % 100);
    }
    list->print();
    cout << "List Length: " << list->length << endl;
    delete list;
    return 0;
}
