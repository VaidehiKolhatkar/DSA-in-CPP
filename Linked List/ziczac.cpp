//zic-zac list : split the link with split_at_mid, reverse the 2nd half, add 1-1 node from 2 lists
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
	
	void print()
	{
		Node* temp = head;
		
		while(temp != NULL)
		{
			cout<<temp->data<<" -> ";
			temp = temp->next;
		}
		
		cout<<"null"<<endl;
	}
};

Node* split_at_mid(Node* head)
{
	Node* prev = NULL;
	Node* slow;
	Node* fast;
	slow = fast = head;
	
	while(fast != NULL && fast->next != NULL)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	
	if(prev != NULL)
	{
		prev->next = NULL;
	}
	
	return slow;
}

Node* reverse(Node* head)
{
	Node* prev = NULL;
	Node* curr = head;
	Node* next = NULL;
	
	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		
		prev = curr;
		curr = next;
	}
	
	return prev;      //prev is head of reversed list
}

Node* zic_zac(Node* head)
{
	Node* head2 = split_at_mid(head);
	
	Node* head_rev = reverse(head2);      //head od revered list
	
	//merge the lists in zic zac pattern
	Node* left = head;
	Node* right = head_rev;
	
	Node* ln;     //left ka next
	Node* rn;     //right ka next
	Node* tail;
	
	while(left!=NULL && right!=NULL)
	{
		rn = right->next;
		ln = left->next;
		
		left->next = right;
		right->next = ln;
		
		//tail for odd size ll
		tail = right;
		
		right = rn;
		left = ln; 
	}
	
	//if the list is odd
	if(right!=NULL)
	{
		tail->next = right;
	}
	
	return head;
}

int main()
{
	List ll;
	
	ll.push_back(1);
	ll.push_back(2);
	ll.push_back(3);
	ll.push_back(4);
	ll.push_back(5);
	
	ll.print();
	
	ll.head = zic_zac(ll.head);
	
	ll.print();
	
	return 0;
} 
