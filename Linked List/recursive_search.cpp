//recursive search
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
	
	//main function does not have access to 'head' cuz its private of List class, so we need helper
	int rec_helper(int val, Node* temp, int pos)
	{
		//base condition
		if(temp == NULL)
		{
			return -1;
		}
	
		if(temp->data == val)
		{
			return pos;	
		}		
		else
		{
			rec_helper(val, temp->next, pos+1);
		}		
	}
		
	int rec_search(int val)
	{	
		return rec_helper(val,head,0);
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
	cout<<"pos is "<<ll.rec_search(3)<<endl;
	
	cout<<"search for 5"<<endl;
	cout<<"pos is "<<ll.rec_search(5)<<endl;
	
	cout<<"search for 1"<<endl;
	cout<<"pos is "<<ll.rec_search(1)<<endl;
	
	cout<<"search for 8"<<endl;
	cout<<"pos is "<<ll.rec_search(8)<<endl;
	
	return 0;
}
