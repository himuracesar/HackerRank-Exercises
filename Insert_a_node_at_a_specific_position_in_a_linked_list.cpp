

/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
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

SinglyLinkedListNode* InsertNode(SinglyLinkedListNode* pHead, SinglyLinkedListNode* pNode, int data, int position, int currentPosition)
{
    cout << " current Pos:: " << currentPosition;
    if((currentPosition + 1) == position)
    {
        SinglyLinkedListNode* pNewNode = new SinglyLinkedListNode(data);
        pNewNode->next = pNode->next;
        pNode->next = pNewNode;
    }
    else {
        return InsertNode(pHead, pNode->next, data, position, (currentPosition + 1));
    }
    
    return pHead;
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    //cout << "position:: " << position << "data:: " << data;
    
   if(llist != nullptr)
   {
       llist = InsertNode(llist, llist, data, position, 0);
   } 
   
   return llist;
}

