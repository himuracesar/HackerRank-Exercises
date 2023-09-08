

/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root, string s) {
    node* pNode = root;
    
    //cout << "***" << root->left->data << "***  " << s;
    char edge = ' ';
    while(edge != '\0')
    {
        if(pNode != nullptr)
        {
            if(pNode->data == '\0')
            {
                if(s.length() == 0)
                {
                    edge = '\0';
                }
                else
                {
                    edge = s[0];
                    //cout << "*** i = " << edge << endl;
                    s = s.substr(1, s.length());
                }
                
                if(edge == '0')
                    pNode = pNode->left;
                else if(edge == '1')
                    pNode = pNode->right;
            }
            else
            {
                cout << pNode->data;
                pNode = root;
            }
        }   
    }
}

