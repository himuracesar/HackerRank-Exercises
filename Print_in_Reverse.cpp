

/*
 * Complete the 'reversePrint' function below.
 *
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

void walkLinkedList(SinglyLinkedListNode* node, vector<int> &numbers)
{
    numbers.push_back(node->data);
    
    if(node->next != nullptr)
    {
        walkLinkedList(node->next, numbers);
    }
    
}

void reversePrint(SinglyLinkedListNode* llist) {
    vector<int> numbers;
    if(llist != nullptr)
    {
        walkLinkedList(llist, numbers);
    }
    
    for(auto inx = 0; inx < numbers.size(); inx++)
    {
        cout << numbers[numbers.size() - (1 + inx)] << endl;
    }
}

