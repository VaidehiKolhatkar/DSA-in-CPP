//height of binary tree
#include<iostream>
#include<vector>
using namespace std;

class Node
{
	public:
		int data;
		Node* right;
		Node* left;
		
		//constructor
		Node(int data)
		{
			this->data = data;
			right = left = NULL;
		}	
};

static int idx = -1;

Node* build_tree(vector<int> nodes)
{
	idx++;
	
	if(nodes[idx] == -1)
		return NULL; 
	
	Node* curr_node = new Node(nodes[idx]);
	
	curr_node->left = build_tree(nodes);
	curr_node->right = build_tree(nodes);	
	
	return curr_node;
}

int height(Node* root)
{
	//base case
	if(root == NULL)
	{
		return 0;
	}
	int r_ht = height(root->right);             // right sub tree height
	int l_ht = height(root->left);
	
	int curr_ht = max(r_ht, l_ht) + 1;
	
	return curr_ht;
}

int main()
{
	//vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
	vector<int> nodes = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
	
	Node* root = build_tree(nodes);
	
	cout<<height(root);
	
	return 0;
}
