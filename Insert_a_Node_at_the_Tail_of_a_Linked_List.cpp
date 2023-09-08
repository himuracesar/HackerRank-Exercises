

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
 
 SinglyLinkedListNode* InsertNode(SinglyLinkedListNode* pHead, SinglyLinkedListNode* pNode, int data)
 {
     if(pNode->next != nullptr)
     {
         return InsertNode(pHead, pNode->next, data);
     }
     else
     {
         SinglyLinkedListNode* pNewNode = new SinglyLinkedListNode(data);
         pNewNode->next = nullptr;
         pNode->next = pNewNode;
     }
     
     return pHead;
 }
 
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    if(head != nullptr)
        return InsertNode(head, head, data);
    else
    {
        head = new SinglyLinkedListNode(data);
        head->next = nullptr;
    }
        
    return head;
}

