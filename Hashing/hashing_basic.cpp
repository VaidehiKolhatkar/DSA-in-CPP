//hashing 
//create array in which linked list will be stored at every index. Every index will store 'head' of its linked list 
//Linked list will have nodes. Each node will store (key,value) pair with type (string,int). 
//So, type of array will be 'Node*' 
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
};

class HashTable{
	int total_size;
	int curr_size;
	Node** table;
	
	public:
		HashTable(int size)
		{
			total_size = size;
			curr_size = 0;
			
			table = new Node*[total_size];
			
			for(int i=0; i<total_size; i++)
			{
				table[i] = NULL;
			}
		}
};

int main()
{
	HashTable ht(6);
	
	return 0;
}
