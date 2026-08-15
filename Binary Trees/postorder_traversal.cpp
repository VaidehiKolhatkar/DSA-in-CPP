//post-order traversal
#include<iostream>
#include<vector>
using namespace std;

class Node
{
	public:
		int data;
		Node *left;
		Node* right;
		
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
	
	//base case
	if(nodes[idx] == -1)
	{
		return NULL;
	}
	
	Node* curr_node = new Node(nodes[idx]);
	
	curr_node->left = build_tree(nodes);
	curr_node->right = build_tree(nodes);
	
	return curr_node;
}

void postorder(Node* root)
{
	//base case
	if(root == NULL)
	{
		return;
	}
	
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
	
	Node* root = build_tree(nodes);
	
	postorder(root);
	
	return 0;
}
