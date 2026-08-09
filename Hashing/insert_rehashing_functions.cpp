//insert, rehashing
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node{
	public:
		string key;
		int val;
		Node* next;
		
		Node(string key, int val)
		{
			this->key = key;
			this->val = val;
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

class HashTable{
	Node** table;
	int total_size;
	int curr_size;
	
	int HashFunc(string key)
	{
		//summation of square of ascii values of each char in the key. Then, mod it with (size-1)
		int idx = 0;
		
		for(int i=0; i<key.size(); i++)
		{
			idx +=  (key[i]*key[i]) % total_size;              //can also take mod on every step
		}
		
		
		return idx;
	}
	
	void rehash()
	{
		Node** old_t = table;
		int old_size = total_size;
		
		total_size = total_size*2;
		
		//create new hash table
		table = new Node*[total_size];
		
		for(int i=0; i<total_size; i++)
		{
			table[i] = NULL;
		}
		
		//copy old values
		for(int i=0; i<old_size; i++)
		{
			Node* temp = old_t[i];          //head will be stored in temp
			
			while(temp != NULL)
			{
				insert(temp->key, temp->val);
				temp = temp->next;
			}
			
			//delete old table linked list
			if(old_t[i] != NULL)
			{
				delete old_t[i];
			}
		}
		
		//delete full old table
		delete[] old_t; 
	}
	
	public:
		HashTable(int size, int curr_size)
		{
			total_size = size;
			this->curr_size = curr_size;
			
			table = new Node*[total_size];
			
			for(int i=0; i<total_size; i++)
			{
				table[i] = NULL;
			}
		}
		
	void insert(string key, int val)
	{
		int idx = HashFunc(key);
		
		//insert new node at idx index
		Node* n = new Node(key, val);
		Node* head = table[idx];
		
		n->next = head;
		head = n;
		
		curr_size++;
		
		double lambda = curr_size / (double)total_size;
		
		if(lambda > 1)
		{
			rehash();
		}
	}
};

int main()
{
	return 0;
}
