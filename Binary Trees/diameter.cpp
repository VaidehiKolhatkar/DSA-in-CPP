//diameter of a binary tree - no. of nodes in the longest path between 2 leaves
// there are 3 cases - 1.diameter which includes root  2.diameter of left subtree  3.diam of right subtree
//so max of these 3 diams will be final diam of tree
// current diam = height(left) + height(right) + 1
//O(n2)
#include<iostream>
#include<vector>
using namespace std;

class Node
{
	public:
		int data;
		Node *right;
		Node *left;
		
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
	if(root == NULL)
		return 0;
	
	int l_ht = height(root->left);
	int r_ht = height(root->right);
	
	int curr_ht = max(l_ht, r_ht) + 1;
	
	return curr_ht;
}

//diameter
int diam(Node* root)
{
	if(root == NULL)
		return 0;
	
	int curr_diam = height(root->left) + height(root->right) + 1;
	
	int l_diam = diam(root->left);
	int r_diam = diam(root->right);
	
	int diam_tree = max(curr_diam, max(l_diam, r_diam) );
	
	return diam_tree;
}

int main()
{
	vector<int> nodes = {1,2,4,9,10,-1,-1,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};	
	
	Node* root = build_tree(nodes);
	
	cout<<"diameter of tree is "<<diam(root);
	
	return 0;
} 
