

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
    
void GetNodes(Node* pNode, vector<int>& nodes)
{
	if(pNode != nullptr)
	{
		GetNodes(pNode->left, nodes);
		nodes.push_back(pNode->data);
		GetNodes(pNode->right, nodes);
	}
}

void inOrder(Node *root) {
	vector<int> nodes;
	GetNodes(root, nodes);
	
	for(auto i = 0; i < nodes.size(); i++)
	{
		cout << nodes[i] << " ";
	}
}

