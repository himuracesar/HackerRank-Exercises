

// Complete the compare_lists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2){
    if(head1 == nullptr && head2 == nullptr)
        return 1;
    else if(head1 == nullptr || head2 == nullptr)
        return 0;
    else
    {
        if(head1->data == head2->data)
        {
            if(head1->next != nullptr && head2 != nullptr)
                return compare_lists(head1->next, head2->next);
            else if(head1->next == nullptr && head2->next == nullptr)
                return 1;
        }
        else
        {
            return 0;    
        }
    }

    return 0;
}

