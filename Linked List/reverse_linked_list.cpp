//reverse the linked list
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
	
	void reverse()
	{
		Node* prev = NULL;
		Node* curr = head;
		Node* next;
		
		while(curr != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		
		head = prev;
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
	
	cout<<"after reversing"<<endl;
	ll.reverse();
	ll.print();
	
	return 0;
}


