//sum of nodes
#include<iostream>
#include<vector>
using namespace std;

class Node
{
	public:
		int data;
		Node* right;
		Node* left;
		
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
	
	curr_node->right = build_tree(nodes);
	curr_node->left = build_tree(nodes);
	
	return curr_node;
}

int sum = 0;
int Sum(Node* root)
{	
	if(root == NULL)
		return 0;
		
	sum += root->data;
	
	Sum(root->left);
	Sum(root->right);
	
	return sum;
}

int main()
{
	//vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
	vector<int> nodes = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
	
	Node* root = build_tree(nodes);
	
	cout<<Sum(root);
	
	return 0;	
}
