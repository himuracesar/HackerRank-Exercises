

/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts INTEGER_DOUBLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
 
DoublyLinkedListNode* ReverseLinkedList(DoublyLinkedListNode* pHead, DoublyLinkedListNode *pNode, vector<DoublyLinkedListNode*>& nodes, int currentIndex)
{
    
    //cout << pNode->data << " ";
    cout << "index:: " << currentIndex << endl;
    pNode = nodes[currentIndex];
    
    if(currentIndex == (nodes.size() - 1))
    {
        
        pNode->prev = nullptr;
        pHead = pNode;
    }
    else if(currentIndex == 0)
    {
        pNode->next = nullptr;
        pNode->prev = nodes[currentIndex + 1];
        return pHead;
    }
    else
    {
        pNode->prev = nodes[currentIndex + 1];
    }
    
    currentIndex--;
    pNode->next = nodes[currentIndex];
    
    return ReverseLinkedList(pHead, pNode->next, nodes, currentIndex);
}

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    if(llist != nullptr)
    {
        vector<DoublyLinkedListNode*> nodes;
        
        DoublyLinkedListNode* pNode = llist;
        
        while(pNode != nullptr)
        {   
            nodes.push_back(pNode);
            pNode = pNode->next;
        }
        //Crear lista reversible
        if(nodes.size() > 1)
            return ReverseLinkedList(llist, llist, nodes, nodes.size() - 1);
    }
    
    return llist;
}

