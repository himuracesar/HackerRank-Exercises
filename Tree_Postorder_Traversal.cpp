

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
            nodes.push_back(pNode->data);
            
            GetNodes(pNode->right, nodes);
            GetNodes(pNode->left, nodes);
        }
    }

    void postOrder(Node *root) {
        vector<int> nodes;
        
        GetNodes(root, nodes);
        
        for(auto inx = 0; inx < nodes.size(); inx++)
        {
            cout << nodes[nodes.size() - (1 + inx)] << " ";
        }
    }

