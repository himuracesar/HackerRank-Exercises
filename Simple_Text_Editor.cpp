#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int total = 0;
    int cmd = 0;
    int val = 0;
    
    stack<string> ops;
    
    cin >> total;
    
    string s = "";
    string sval = "";
    
    ops.push(sval);
    for(auto i = 0; i < total; i++)
    {
        cin >> cmd;
        switch(cmd)
        {
            case 1:
                cin >> sval;
                s += sval;
                ops.push(s);
            break;
            
            case 2:
                cin >> val;
                s.erase(s.begin() + s.length() - val, s.end());
                ops.push(s);
            break;
            
            case 3:
                cin >> val;
                //cout << "PRINT:: " << s << endl;
                cout << s.at(val - 1) << endl;
            break;
            
            case 4: 
                ops.pop();
                if(!ops.empty())
                    s = ops.top();
                else
                    s = "";
            break;
        }
    }
    
    return 0;
}
