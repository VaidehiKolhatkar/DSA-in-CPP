//cycle detection in ll - slow and fast pointers. If they meet, then cycle
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

	
	public:
		
	Node* head;
	Node* tail;
	
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
	
	void print()
	{
		Node* temp = head;
		
		while(temp != NULL)
		{
			cout<<temp->data;
			cout<<"->";
			temp = temp->next;
		}
		
		cout<<"null";
		cout<<endl;
	}
	
	bool cycle(Node* head)
	{
		Node* slow = head;
		Node* fast = head;
		
		while(fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
			
			if(slow == fast)
			{
				return true;
			}
		}
		
		return false;
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
	ll.tail->next = ll.head;           //created cycle 
	
	cout<<ll.cycle(ll.head);
	
	return 0;
}
