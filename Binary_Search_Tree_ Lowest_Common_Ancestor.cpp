

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    void ParseSubTree(Node* pNode, int v1, int v2, vector<Node*>& parents, int level)
    {
        if(pNode != nullptr)
        {
            //cout << "node:: " << pNode->data << " level:: " << level << endl; 
            
            if((pNode->left != nullptr && pNode->left->data == v1) || 
               (pNode->left != nullptr && pNode->left->data == v2))
            {
                parents.push_back(pNode);
            } 
            else if((pNode->right != nullptr && pNode->right->data == v1) || 
               (pNode->right != nullptr && pNode->right->data == v2))
            {
                   parents.push_back(pNode);
            }

            ParseSubTree(pNode->left, v1, v2, parents, level + 1);
            ParseSubTree(pNode->right, v1, v2, parents, level + 1);
        }
    }
  
    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
        if(root == nullptr)
            return root;
        else
        {
            vector<Node*> p;
            
            ParseSubTree(root->left, v1, v2, p, 1);
            
            //cout << " p:: " << p.size() << endl;
            
            if(p.size() == 2)
            {
                if(p[1]->data == v1 || p[1]->data == v2)
                    return p[1];
                else 
                    return p[0];
                
            }
            else if(p.size() == 1)
            {
                return root;
            }
            else if(p.size() == 0)
            {
                ParseSubTree(root->right, v1, v2, p, 1);
            }
            
            if(p.size() == 2)
            {
                if(p[1]->data == v1 || p[1]->data == v2)
                    return p[1];
                else 
                    return p[0];
            }
            else 
            {
                return root;
            }
        }
    }

