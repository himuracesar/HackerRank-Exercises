

// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
 
bool HasCycle(SinglyLinkedListNode* pNode, vector<SinglyLinkedListNode*>& nodes)
{
    if(pNode != nullptr)
    {
        for(auto i = 0; i < nodes.size(); i++)
        {
            if(nodes[i] == pNode)
                return 1;  
        }
        
        nodes.push_back(pNode);
    }
    else
        return 0;
    
    return HasCycle(pNode->next, nodes);
}

bool has_cycle(SinglyLinkedListNode* head) {
    vector<SinglyLinkedListNode*> nodes;
    
    return HasCycle(head, nodes);
}

