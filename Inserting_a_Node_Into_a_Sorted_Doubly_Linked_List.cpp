

/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
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
DoublyLinkedListNode* InsertNode(DoublyLinkedListNode* pHead, DoublyLinkedListNode* pPrevNode, DoublyLinkedListNode* pNode, int data)
{
    /**
        2-3-4-null
        1
        1-2-3-null
        4
    */
    cout << "d:: " << data;
    //cout << "data:: " << pNode->data << endl;
    if(pNode == nullptr)
    {
        DoublyLinkedListNode* p = new DoublyLinkedListNode(data);
        p->prev = pPrevNode;
        p->next = pNode;
        
        pPrevNode->next = p;
        
        return pHead;
    }
    else if(pNode->data >= data)
    {
        DoublyLinkedListNode* p = new DoublyLinkedListNode(data);
        p->prev = pPrevNode;
        p->next = pNode;
        
        if(pPrevNode != nullptr)
            pPrevNode->next = p;
            
        pNode->prev = p;
        
        if(pHead == pNode)
            pHead = p;
        
        return pHead;
    }
    
    return InsertNode(pHead, pNode, pNode->next, data);
}

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    if(llist == nullptr)
        llist = new DoublyLinkedListNode(data);
    else
        return InsertNode(llist, nullptr, llist, data);
        
    return llist;
}

