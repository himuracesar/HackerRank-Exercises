#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'appendAndDelete' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 *  3. INTEGER k
 */

string appendAndDelete(string s, string t, int k) {
    int ns = s.length();
    int nt = t.length();
    
    if(ns + nt <= k)
        return "Yes";
    
    int numOp = ns - nt;
    numOp = (numOp < 0) ? 0 : numOp;
    
    int lastInx = min(ns, nt);
    int opnoconf = 0;
    int len = ns - numOp;
    
    for(auto i = 1; i <= lastInx; i++){
        if(s.at(lastInx - i) != t.at(lastInx - i))
        {
            numOp += opnoconf + 1;
            len = len - opnoconf - 1;
            opnoconf = 0;
            
            if(numOp > k)
                return "No";
        }
        else
        {
            opnoconf++;
        }
    }
    
    numOp += (nt - len);
    if(numOp == k || ( numOp < k && (k - numOp) % 2 == 0))
        return "Yes";
    else
        return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = appendAndDelete(s, t, k);

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
