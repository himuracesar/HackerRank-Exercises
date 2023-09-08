

/*
 * Complete the 'removeDuplicates' function below.
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
 
SinglyLinkedListNode* Remove(SinglyLinkedListNode* pHead, SinglyLinkedListNode* pNode)
{
    if(pNode == nullptr || pNode->next == nullptr)
    {
        return pHead;
    }
    else if(pNode->data == pNode->next->data)
    {
        SinglyLinkedListNode* p = pNode->next->next;
        delete pNode->next;
        pNode->next = p;
        
        return Remove(pHead, pNode);
    }
    
    return Remove(pHead, pNode->next);
}

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    return Remove(llist, llist);
}

