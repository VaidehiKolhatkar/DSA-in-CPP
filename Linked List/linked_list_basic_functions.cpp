//linked list: push_front, push_back, pop_front, pop_back, insert, print
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
	
	void pop_front()
	{
		if(head == NULL)
		{
			cout<<"ll is empty"<<endl;
			return;
		}
		
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	
	void pop_back()
	{
		//empty list
		if(head == NULL)
		{
			cout<<"ll is empty"<<endl;
			return;
		}
		
		//list with 1 node
		if(head == tail)
		{
			delete head;
			head = NULL;
    		tail = NULL;
			return;
		}

		Node* temp = head;
		
		//list with more than 1 node
		while(temp->next != tail)
		{	
			temp = temp->next;	
		}
		
		temp->next = NULL;
		delete tail;
		tail = temp;
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
	
	cout<<"push front 3,2,1"<<endl;
	ll.push_front(3);
	ll.push_front(2);
	ll.push_front(1);
	ll.print();
	cout<<endl;
	
	cout<<"push back 5,6"<<endl;
	ll.push_back(5);
	ll.push_back(6);
	ll.print();
	cout<<endl;

	cout<<"pop front"<<endl;
	ll.pop_front();
	ll.print();
	cout<<endl;
	
	cout<<"pop back"<<endl;
	ll.pop_back();
	ll.print();
	cout<<endl;	
	
	cout<<"insert 4 at position 3"<<endl;
	ll.insert(4,3);
	ll.print();
		
	return 0;
}
