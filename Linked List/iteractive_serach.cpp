//iterative search on ll
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
	
	void it_search(int val)
	{
		if(head == NULL)
		{
			cout<<"ll is empty"<<endl;
			return;
		}
		
		//ll with 1 node
		if(head == tail)
		{
			if(head->data == val)
			{
				cout<<"pos is 0"<<endl;
			}
			
			return;
		}
		
		int pos = 0;
		Node* temp = head; 
		
		while(temp != NULL)
		{
			if(temp->data == val)
			{
				cout<<val<<" is at position "<<pos<<endl;
				return;
			}
			
			temp = temp->next;
			pos++;
		}
		
		cout<<val<<" is not in the ll"<<endl;
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
	
	ll.push_front(5);
	ll.push_front(4);
	ll.push_front(3);
	ll.push_front(2);
	ll.push_front(1);
	
	ll.print();
	
	cout<<"search for 3"<<endl;
	ll.it_search(3);
	
	cout<<"search for 8"<<endl;
	ll.it_search(8);
	
	return 0;
}
