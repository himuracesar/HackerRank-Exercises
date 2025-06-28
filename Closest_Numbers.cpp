#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'closestNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void Merge(vector<int>& left, vector<int>& right, vector<int>& arr){
    int nleft = left.size();
    int nright = right.size();
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < nleft && j < nright){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    while(i < nleft){
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while(j < nright){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int>& arr){
    int n = arr.size();
    if(n < 2)
        return;
        
    int mid = n / 2;
    vector<int> left;
    vector<int> right;
    
    for(auto i = 0; i < mid; i++)
        left.push_back(arr[i]);
    
    for(auto j = mid; j < n; j++)
        right.push_back(arr[j]);
        
    MergeSort(left);
    MergeSort(right);
    Merge(left, right, arr);
}

vector<int> closestNumbers(vector<int> arr) {
    map<int, vector<int>> arrs;
    
    int minNum = INT_MAX;
    
    MergeSort(arr);
    /*for(auto i = 0; i < arr.size(); i++)
        cout << arr[i] << ", ";
    cout << endl;*/
    
    for(auto i = 1; i < arr.size(); i++){
        int diff = abs(arr[i] - arr[i - 1]);
        minNum = min(minNum, diff);
        
        arrs[diff].push_back(arr[i - 1]);
        arrs[diff].push_back(arr[i]);
    }
    
    return arrs[minNum];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = closestNumbers(arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
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
