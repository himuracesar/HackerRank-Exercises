

/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
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

SinglyLinkedListNode* DelNode(SinglyLinkedListNode* pHead, SinglyLinkedListNode* pNode, int position, int currentPosition)
{
    
    if(position == 0)
    {
        pHead = pNode->next;
    }
    else if((currentPosition + 1) == position)
    {
        SinglyLinkedListNode* _pAuxNode = pNode->next->next;
        delete pNode->next;
        pNode->next = _pAuxNode;
    }
    else {
        return DelNode(pHead, pNode->next, position, currentPosition +1);
    }
    
    return pHead;
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if(llist != nullptr)
    {
        return DelNode(llist, llist, position, 0);
    }
    
    return nullptr;
}

