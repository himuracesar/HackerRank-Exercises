#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sillyGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER n as parameter.
 */

vector<int> getPrimes(int n){
    vector<int> primes;
    int p[n + 1];
    
    for(auto i = 0; i <= n; i++){
        p[i] = 1;
    }
    
    p[0] = 0;
    p[1] = 1;
    
    for(auto i = 2; i <= n; i++){
        if(p[i] == 1){
            primes.push_back(i);
            for(auto j = 2; i * j <= n; j++){
                p[i * j] = 0;
            }
        }
    }
    
    return primes;
}

string sillyGame(int n) {
    vector<int> primes = getPrimes(n);
    
    if(primes.size() % 2 == 0)
        return "Bob";
    else
        return "Alice";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string result = sillyGame(n);

        fout << result << "\n";
    }

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
