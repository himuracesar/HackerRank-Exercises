

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

    Node * insert(Node * root, int data) {
        //std::cout << "data:: " << data << std::endl;
        if(root == nullptr)
        {
            //std::cout << "return root" << std::endl;
            root = new Node(data);
            return root;
        }
        else
        {
            //std::cout << "Node:: " << root->data << std::endl;
            if(root->data > data)
            {
                if(!root->left)
                {
                    root->left = new Node(data);
                }
                else
                {
                    insert(root->left, data);
                }
            }
            else
            {
                if(!root->right)
                {
                    root->right = new Node(data);
                }
                else
                {
                    insert(root->right, data);
                }
            }
        }
        
        return root;
    }

