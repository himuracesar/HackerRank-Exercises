#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'largestRectangle' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY h as parameter.
 */
 
 void FillStack(stack<pair<int, int>> &o, stack<pair<int, int>>& d)
 {
    while(!o.empty())
    {
        pair<int, int> paux = o.top();
        paux.second = paux.second + 1;
        d.push(paux);
        
        o.pop();
    }
 }

long largestRectangle(vector<int> h) {
    stack<pair<int, int>> areas;
    stack<pair<int, int>> aux;
    int lh = 0;
    int lb = 0;
    for(auto inx = 0; inx < h.size(); inx++)
    {
        if(h[inx] > lh)
        {
            if(areas.empty())
            {
                pair<int, int> p(h[inx], 1);
                areas.push(p);
                
                lh = h[inx];
                lb = 1;
            }
            else
            {
                bool found = false;
                while(!found)
                {
                    pair<int, int> p = areas.top();
                    aux.push(p);
                    areas.pop();
                    if(p.first == lh && p.second == lb)
                    {
                        found = true;
                        pair<int, int> _p(h[inx], 1);
                        areas.push(_p);
                        lh = _p.first;
                        lb = _p.second;
                        
                        FillStack(aux, areas);
                    }
                }
            }
        }
        else 
        {
            bool found = false;
            while(!found)
            {
                pair<int,int> p = areas.top();
                if(p.first >= h[inx])
                {
                    pair<int,int> a(h[inx], p.second + 1);
                    areas.push(a);
                    found = true;
                    
                    lh = a.first;
                    lb = a.second;
                    
                    FillStack(aux, areas);
                }
                else
                {
                    aux.push(p);
                    areas.pop();
                }
            }
        }
    }
    
    long maxArea = 0;
    while(!areas.empty())
    {
        pair<int,int> p = areas.top();
        cout << "h:: " << p.first << " b:: " << p.second << endl;
        long a = p.first * p.second;
        maxArea = max(maxArea, a);
        areas.pop();
    }
    
    return maxArea;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
