//remove cycle in ll - after detecting cycle, assign slow to head. move slow and fast by 1. when they meet again at some node x, 
//x-1 i.e., prev of that node will be LAST node in ll. So, prev->next=NULL, so we broke the cycle
//special case: if tail connects to head and forms the cycle, their 1st meeting points will be head. So, slow=fast=head.
//so when we check 2nd meet, they are already met, so loop will not run. So, dd extra condition for special case. 
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
};

void remove_cycle(Node* head)
{
	//detect
	Node* slow = head;
	Node* fast = head;
	
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if(slow == fast)
		{
			cout<<"cycle detected"<<endl;
			
			slow = head;
			
			//special case
			if(slow == fast)
			{
				while(fast->next != slow)
				{
					fast = fast->next;
				}
				fast->next = NULL;              //cycle removed
				return;
			}
			//--------------------------------------------------------------------
			
			Node* prev = head;
		
			//find prev of fast
			while(prev->next != fast)
			{
				prev = prev->next;	
			}
			//here, prev is pointing to prev of fast 
		
			while(slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
				prev = prev->next;
			}
		
			//remove the connection
			prev->next = NULL;
		
			cout<<"cycle removed"<<endl;
		}
	}
}

int main()
{
	List ll;
	
	ll.push_front(5);
	ll.push_front(4);
	ll.push_front(3);
	ll.push_front(2);
	ll.push_front(1);
	
	ll.tail->next = ll.head;      //cycle created, special case
	remove_cycle(ll.head);
	ll.print();
	
	cout<<endl;
	
	ll.tail->next = ll.head->next->next;      //cycle created
	remove_cycle(ll.head);
	ll.print();
	
	return 0;
}
