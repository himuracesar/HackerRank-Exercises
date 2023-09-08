

/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
 
 SinglyLinkedListNode* ReverseLinkedList(SinglyLinkedListNode* pHead,  SinglyLinkedListNode* pNode, vector<SinglyLinkedListNode*>& nodes, int currentPosition)
 {
     if(currentPosition == 0)
     {
         pNode->next = nullptr;
     }
     else
     {
         cout << "currentPosition:: " << currentPosition << endl;
         currentPosition--;
         pNode->next = nodes[currentPosition];
        
         return ReverseLinkedList(pHead, pNode->next, nodes, currentPosition);
     } 
     
     return pHead;     
 }

vector<SinglyLinkedListNode*> GetNodes(SinglyLinkedListNode* pNode, vector<SinglyLinkedListNode*>& nodes)
{
    nodes.push_back(pNode);
    
    if(pNode->next != nullptr)
    {
        return GetNodes(pNode->next, nodes);
    }
    
    return nodes;
}

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    if(llist != nullptr)
    {
        //vector<SinglyLinkedListNode*> nodes = GetNodes(llist, nodes);
        //return ReverseLinkedList(llist, llist, nodes, nodes.size() - 1);
        
        vector<SinglyLinkedListNode*> nodes;
        
        SinglyLinkedListNode* pNode = llist;
        while(pNode != nullptr)
        {
            nodes.push_back(pNode);
            pNode = pNode->next;
        }
                
        /*int lengthVector = nodes.size();
        //pNode = nodes[nodes.size() - 1];
        for(auto i = 0; i < lengthVector - 1; i++)
        {
            pNode = nodes[lengthVector - (1 + i)];
            pNode->next = (i == lengthVector - 1) ? nullptr : nodes[lengthVector - (2 + i)];
        }
        
        return nodes[lengthVector - 1];*/
        
        return ReverseLinkedList(nodes[nodes.size() - 1], nodes[nodes.size() - 1], nodes, nodes.size() -1);
    }
    
    return nullptr;
}

