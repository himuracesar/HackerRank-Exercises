#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

vector<double> runningMedian(vector<int> a) {
    vector<double> res;
    
    vector<int> maxHeap;
    make_heap(maxHeap.begin(), maxHeap.end());
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(auto i = 0; i < a.size(); i++)
    {
        if(i == 0)
            minHeap.push(a[i]);
        else 
        {
            if(minHeap.top() < a[i])
            {
                if(minHeap.size() > maxHeap.size())
                {
                    double head = minHeap.top();
                    minHeap.pop();
                    maxHeap.push_back(head);
                    push_heap(maxHeap.begin(), maxHeap.end());
                }
                
                minHeap.push(a[i]);
            }
            else
            {
                if(minHeap.size() < maxHeap.size())
                {
                    double head = maxHeap[0];
                    pop_heap(maxHeap.begin(), maxHeap.end());
                    maxHeap.pop_back();
                    
                    minHeap.push(head);
                }
                maxHeap.push_back(a[i]);
                push_heap(maxHeap.begin(), maxHeap.end());
            }
        }
        
        if(minHeap.size() > 0 && maxHeap.size() > 0 && minHeap.top() < maxHeap[0])
        {
            double tmp = minHeap.top();
            minHeap.pop();
            minHeap.push(maxHeap[0]);
            
            pop_heap(maxHeap.begin(), maxHeap.end());
            maxHeap.pop_back();
            maxHeap.push_back(tmp);
            push_heap(maxHeap.begin(), maxHeap.end());
        }
        
        if(minHeap.size() > maxHeap.size())
        {
            cout << minHeap.top() << endl;
            res.push_back((minHeap.top()));
        }
        else if(minHeap.size() < maxHeap.size())
        {
            cout << maxHeap[0] << endl;
            res.push_back(maxHeap[0]);
        }
        else 
        {
            double avg = (minHeap.top() + maxHeap[0]) / 2.0;
            cout << avg << endl;
            res.push_back(avg);
        }
    }
    
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
