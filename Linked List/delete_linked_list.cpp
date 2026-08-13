//delete the ll: add destructors for node and list class
#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
	
			Node(int data)
			{
				this->data = data;
				next = NULL;
			}
			
			~Node()
			{
				if(next != NULL)
				{
					delete next;
					next = NULL;
				}
			}
};

class List{
	Node* head;
	Node* tail;
	
	public:
		List()
		{
			head = NULL;
			tail = NULL;
		}
		
		~List()
		{
			if(head != NULL)
			{
				delete head;
				head = NULL;
			}
		}
		
	void push_front(int data)
	{
		Node* n = new Node(data);
		
		if(head == NULL)
		{
			head = tail = n;
		}
		else
		{
			n->next = head;
			head = n;
		}
	}
	
	void push_back(int data)
	{
		Node* n = new Node(data);
		
		if(head == NULL)
		{
			head = tail = n;
		}
		else
		{
			tail->next = n;
			tail = n;
		}
	}
	
	void insert(int val, int pos)
	{
		Node* n = new Node(val);
		
		if(pos == 0)
		{
			n->next = head;
			head = n;
		}
		else
		{
			Node* temp = head;
			
			for(int i=0; i<pos-1; i++)
			{
				if(temp == NULL)
				{
					cout<<"invalid position";
				}
				
				temp = temp->next;          //now temp is pointing to pos-1 node
			}
			
			n->next = temp->next;
			temp->next = n;
		}
	}
	
	void print()
	{
		Node* temp = head;
		
		while(temp!=NULL)
		{
			cout<<temp->data;
			cout<<"->";	
			temp = temp->next;
		}	
		
		cout<<"null";
		cout<<endl;
	}
};

int main()
{
	List ll;
	
	ll.push_front(3);
	ll.push_front(2);
	ll.push_front(1);
	
	ll.print();
	
	ll.push_back(5);
	ll.push_back(6);
	
	ll.print();
	
	ll.insert(4,3);
	
	ll.print();
	
	return 0;
}
