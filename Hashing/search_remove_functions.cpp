//search, remove 
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
	int t_size;
	int c_size;
	
	int hash_func(string key)
	{
		//summation of square of ascii values of each char in the key. Then, mod it with (size-1)
		long int idx = 0;
		
		for(int i=0; i<key.size(); i++)
		{
			idx +=  (key[i]*key[i]) % t_size;              //can also take mod on every step
		}
		
		idx = idx % t_size;
			
		return idx;
	}
	
	void rehashing()
	{
		Node** old_t = table;
		int old_size = t_size;
		
		t_size = t_size*2;
		c_size = 0;
		
		//create new table
		table = new Node*[t_size];
		
		for(int i=0; i<t_size; i++)
		{
			table[i] = NULL;
		}
		
		//copy ol values
		for(int i=0; i<old_size; i++)
		{
			Node* temp = old_t[i];
			
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
		delete[] old_t;
	}
	
	public:
		HashTable(int t_size, int c_size)
		{
			this->t_size = t_size;
			this->c_size = 0;
			
			//create a new table
			table = new Node*[t_size];
			
			for(int i=0; i<t_size; i++)
			{
				table[i] = NULL;
			}
		}
		
	void insert(string key, int val)
	{
		int idx = hash_func(key);
		
		Node* n = new Node(key, val);
		//Node* head = table[idx];            //initially head is NULL
		
		n->next = table[idx];           //in place of head, we wrote table[idx]. cuz, head will be initially NULL
		table[idx] = n;
		
		c_size++;
		
		double lambda = c_size / (double)t_size;
		
		if(lambda > 1)
		{
			rehashing();
		}
	}
	
	int search(string key)
	{
		int idx = hash_func(key);
		
		Node* temp = table[idx];
		
		while(temp != NULL)
		{
			if(temp->key == key)
			{
				return temp->val;
			}
				temp = temp->next;
		}
		
		return -1;
	}
	
	void remove(string key)
	{
		int idx = hash_func(key);
		
		
		Node* temp = table[idx];
			
		//if key to remove is the head
		if(temp->key == key)
		{
			//remove it
			table[idx] = temp->next;                     //table[idx] is basically head
			return;
		}
			
		while(temp != NULL)
		{
			if(temp->next->key == key)
			{
				temp->next = temp->next->next;
				return;
			}
				
			temp = temp->next;
		}
	}
	
	void print()
	{
		for(int i=0; i<t_size; i++)
		{
			cout<<i<<" - ";
			Node* temp = table[i];	
			
			while(temp != NULL)
			{
				cout<<"("<<temp->key<<","<<temp->val<<")"<<" -> ";
				temp = temp->next;
			}
			
			cout<<endl;
		}	
	}
};

int main()
{
	HashTable ht(5,0);
	
	ht.insert("India",300);
	ht.insert("US",140);
	ht.insert("China",276);
	ht.insert("Japan",200);
	ht.insert("Italy",190);
	
	ht.print();
	cout<<endl;
	
//	cout<<ht.search("India")<<endl;
//	cout<<ht.search("US")<<endl;
//	cout<<ht.search("China")<<endl;
//	cout<<ht.search("Japan")<<endl;
//	cout<<ht.search("Italy")<<endl;

	ht.remove("Japan");
	cout<<"after remove operation"<<endl;
	ht.print();
	
	return 0;
}
