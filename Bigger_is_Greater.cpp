#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string swap(string s, int inx1, int inx2)
{
    char aux = s.at(inx1);
    s[inx1] = s.at(inx2);
    s[inx2] = aux;
    
    return s;
}

int Partition(string* pStr, int start, int end)
{
    int pivot = pStr->at(end);
    int partitionIndex = start;
    for(auto i = start; i < end; i++)
    {
        if(pStr->at(i) <= pivot)
        {
            *pStr = swap(*pStr, i, partitionIndex);
            partitionIndex++;
        }
    }
    
    *pStr = swap(*pStr, partitionIndex, end);
    
    return partitionIndex;
}

void QuickSort(string* pStr, int start, int end)
{
    if(start < end)
    {
        int partitionIndex = Partition(pStr, start, end);
        QuickSort(pStr, start, partitionIndex - 1);
        QuickSort(pStr, partitionIndex + 1, end);
    }
}

/*
 * Complete the 'biggerIsGreater' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING w as parameter.
 */

string biggerIsGreater(string w) {
    int i = w.length() - 2;
    while(i >= 0 && w.at(i) >= w.at(i + 1))
        i--;
        
    if(i == -1)
        return "no answer";
        
    int ceil = i + 1;
    int j = ceil;
    
    while(j < w.length())
    {
        if(w.at(j) > w.at(i) && w.at(j) < w.at(ceil))
            ceil = j;
        
        j++;
    }
    
    w = swap(w, i, ceil);
    
    i++;
    j = w.length() - 1;
    QuickSort(&w, i, j);
    
    return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

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
