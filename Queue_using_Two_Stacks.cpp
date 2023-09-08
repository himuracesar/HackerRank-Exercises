#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int total;
    int cmd;
    int number;
    
    stack<int> front;
    stack<int> rare;
    
    cin >> total;
    for(auto i = 0; i < total; i++)
    {
        cin >> cmd;
        switch(cmd)
        {
            case 1:
                cin >> number;
                rare.push(number);
            break;
            
            case 2:
                if(front.empty())
                {
                    while(!rare.empty())
                    {
                        front.push(rare.top());
                        rare.pop();
                    }
                }
                front.pop();
            break;
            
            case 3:
                if(front.empty())
                {
                    while(!rare.empty())
                    {
                        front.push(rare.top());
                        rare.pop();
                    }
                }
                cout << front.top() << endl;
            break;
        }
    }
    
     
    return 0;
}
