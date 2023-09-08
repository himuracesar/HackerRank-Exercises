

/*
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

    void GetNodes(Node* pNode, int index, map<int, int>& m, map<int, int>& maux, char left_right, int level)
    {
        if(pNode != nullptr)
        {
            //cout << "data:: " << pNode->data << " - level:: " << level << endl;
            if(left_right == 'l')
            {
                //cout << "l_data:: " << index << endl;
                if(index < 0)
                {
                    if(m[index] == 0)
                    {
                        m[index] = pNode->data;
                        //cout << ".:insert:." << endl;
                    }
                }
                else if(index > 0)
                {
                    //if(maux[index] == 0)
                    //{
                        maux[index] = pNode->data;
                        //cout << ".:insert aux:." << endl;
                    //}
                }
                
                GetNodes(pNode->left, index - 1, m, maux, left_right, level + 1);
                GetNodes(pNode->right, index + 1, m, maux, left_right, level + 1);
            }
            else if(left_right == 'r')
            {
                //cout << "r_data:: " << index << endl;
                if(index > 0)
                {
                    if(m[index] == 0)
                    {
                        m[index] = pNode->data;
                        //cout << ".:insert:." << endl;
                    }
                }
                else if(index < 0)
                {
                    //if(maux[index] == 0)
                    //{
                        maux[index] = pNode->data;
                        //cout << ".:insert aux:." << endl;
                    //}
                }
                
                GetNodes(pNode->right, index + 1, m, maux, left_right, level + 1);
                GetNodes(pNode->left, index - 1, m, maux, left_right, level + 1);
            }
        }
        else
            return;
    }
    

    void topView(Node * root) {
        /**
            node, 
       */ 
       
       if(root != nullptr)
       {
            map<int, int> nodes;
            map<int, int> nodes_aux;
            
            GetNodes(root->left, -1, nodes, nodes_aux, 'l', 1);
            GetNodes(root->right, 1, nodes, nodes_aux, 'r', 1);
            
            nodes[0] = root->data;
            
            for(auto inx = nodes_aux.begin(); inx != nodes_aux.end(); inx++)
            {
                if(nodes[inx->first] == 0)
                        nodes[inx->first] = inx->second;
            }
            
            for(auto i = nodes.begin(); i != nodes.end(); i++)
            {
                cout << i->second << " ";
            }
       }
    }

