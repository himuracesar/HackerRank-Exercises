

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
 
 SinglyLinkedListNode* AssignNode(SinglyLinkedListNode* pOrig, SinglyLinkedListNode* pDest)
 {
     if(pDest == nullptr)
     {
         pDest = pOrig;
     }
     else
     {
         pDest->next = pOrig;
     }
     
     return pDest;
 }
 
SinglyLinkedListNode* Merge(SinglyLinkedListNode* pHead, SinglyLinkedListNode*& pNode, SinglyLinkedListNode* pNode1, SinglyLinkedListNode* pNode2)
 {
    if(pNode1 != nullptr && pNode2 == nullptr)
    {
        cout << "node1:: " << pNode1->data << endl;
        //pNode = AssignNode(pNode, pNode1);
        pNode = pNode1;
        pNode1 = pNode1->next;
    }
    else if(pNode1 == nullptr && pNode2 != nullptr)
    {
        cout << "node2:: " << pNode2->data << endl;
        //pNode = AssignNode(pNode, pNode2);
        pNode = pNode2;
        pNode2 = pNode2->next;
    }
    else if(pNode1 != nullptr && pNode2 != nullptr)
    {
        if(pNode1->data <= pNode2->data)
        {
            cout << "node1+:: " << pNode1->data << endl;
            //pNode = AssignNode(pNode, pNode1);
            pNode = pNode1;
            pNode1 = pNode1->next;
        }
        else
        {
            cout << "node2+:: " << pNode2->data << endl;
            //pNode = AssignNode(pNode, pNode2);
            pNode = pNode2;
            pNode2 = pNode2->next;
        }
    }
    else if(pNode1 == nullptr && pNode2 == nullptr)
    {
        //pNode->next = nullptr;
        return pHead;
    }
    
    if(pHead == nullptr)
    {
        pHead = pNode;
        //cout << "pHead:: " << pHead;
        //return Merge(pHead, pHead, pNode1, pNode2);
    }
        
    cout << "data: " << pNode->data << endl;
     
    return Merge(pHead, pNode->next, pNode1, pNode2);
 }
 
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    /*
        head->node->node->null
    */
    SinglyLinkedListNode* pHead = new SinglyLinkedListNode(0);
    
    return Merge(nullptr, pHead, head1, head2);
}

