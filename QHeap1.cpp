#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

void swap(vector<int>& heap, int from, int to){
    int aux = heap[from];
    heap[from] = heap[to];
    heap[to] = aux;
}

void heapifyUp(vector<int>& heap, int index){
    if(heap.size() < 1)
        return;
        
    int parentInx = (index - 1) / 2;
    if(parentInx >= 0 && heap[index] < heap[parentInx]){
        swap(heap, index, parentInx);
        heapifyUp(heap, parentInx);
    }
}

void heapifyDown(vector<int>& heap, int index) {
    if(heap.size() < 1)
        return; 
        
    int child1 = 2 * index + 1;
    int child2 = 2 * index + 2;
    int childStart = -1;
    int childEnd = -1;
    
    child1 = (child1 < heap.size()) ? child1 : -1;
    child2 = (child2 < heap.size()) ? child2 : -1;
    
    if(child1 == -1 && child2 > -1)
        childStart = child2;
    else if(child1 > -1 && child2 == -1)
        childStart = child1;
    else if(child1 > -1 && child2 > -1){
        if(heap[child1] < heap[child2]){
            childStart = child1;
            childEnd = child2;
        } else {
            childStart = child2;
            childEnd = child1;
        }
    }
        
    if(childStart > -1 && heap[index] > heap[childStart]){
        swap(heap, index, childStart);
        heapifyDown(heap, childStart);
    } else if(childEnd >-1 && heap[index] > heap[childEnd]){
        swap(heap, index, childEnd);
        heapifyDown(heap, childEnd);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int cmd;
    int value;
    
    int total;
    cin >> total;
    
    vector<int> minHeap;
    
    for(auto i = 0; i < total; i++)
    {
        cin >> cmd;
        switch (cmd)
        {
            case 1:
            {
                cin >> value;
                
                minHeap.push_back(value);
                heapifyUp(minHeap, minHeap.size() - 1);
            }
            break;
            
            case 2:
            {
                cin >> value;
                
                int index = -1;
                for(auto i = 0; i < minHeap.size(); i++){
                    if(value == minHeap[i]){
                        index = i;
                        break;
                    }
                }
                //cout << "index = " << index << " v = " << value << endl;
                swap(minHeap, index, minHeap.size() - 1);
                minHeap.erase(minHeap.begin() + minHeap.size() - 1);
                heapifyDown(minHeap, index);
            }
            break;
            
            case 3:
                cout << minHeap[0] << endl;
            break;
        }
    }
    
    return 0;
}
