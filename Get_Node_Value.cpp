

/*
 * Complete the 'getNode' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER positionFromTail
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

vector<int> GetDataFromLinkedList(SinglyLinkedListNode* pNode, vector<int> &datas)
{
    datas.push_back(pNode->data);
    
    if(pNode->next != nullptr)
        return GetDataFromLinkedList(pNode->next, datas);
        
    return datas;
}

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    vector<int> d;
    
    if(llist != nullptr)
        d = GetDataFromLinkedList(llist, d);
        
    return d[d.size() - (1 + positionFromTail)];
}

