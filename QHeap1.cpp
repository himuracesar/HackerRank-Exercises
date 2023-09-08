int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int cmd;
    int value;
    
    int total;
    cin >> total;
    
    vector<int> minHeap;
    
    make_heap(minHeap.begin(), minHeap.end());
    
    for(auto i = 0; i < total; i++)
    {
        cin >> cmd;
        switch (cmd)
        {
            case 1:
                cin >> value;
                //cout << "push " << value << endl;
                minHeap.push_back(-1 * value);
                push_heap(minHeap.begin(), minHeap.end());
            break;
            
            case 2:
            {
                cin >> value;
                value *= -1;
                
                /*for(auto i = 0; i < minHeap.size(); i++)
                {
                    cout << minHeap[i] << " | ";
                }*/
                
                queue<int> q;
                q.push(0);
                while(!q.empty())
                {
                    if((minHeap[q.front()]) == value)
                    {
                        minHeap.erase(minHeap.begin() + q.front());
                        //pop_heap(minHeap.begin(), minHeap.end());
                        make_heap(minHeap.begin(), minHeap.end());
                        
                        break;
                    } 
                    else if((minHeap[q.front()]) > value)
                    {
                        int index = 2 * q.front() + 1;
                        if(index < minHeap.size())
                        {
                            q.push(index);//leftChild
                            
                            index++;
                            if(index < minHeap.size())
                                q.push(index);//rightChild
                        }
                    }
                    
                    q.pop();
                }
            }
            break;
            
            case 3:
                //cout << "print ";
                cout << minHeap.front() * -1 << endl;
            break;
        }
    }
    
    return 0;
}