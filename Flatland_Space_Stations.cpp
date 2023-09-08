#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

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
        
    for(auto i = mid; i < n; i++)
        right.push_back(arr[i]);
        
    MergeSort(left);
    MergeSort(right);
    Merge(left, right, arr);
}

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {
    MergeSort(c);
    
    /*for(auto i = 0; i < c.size(); i++)
        cout << c[i] << endl;*/
    
    int maxDistance = 0;
    for(auto i = 0; i < n; i++){
        int start = 0;
        int end = c.size() - 1;
        int mid = 0;
        int minDistance = INT_MAX;
        
        while(start <= end){
            mid = (start + end) / 2;
            if(i == c[mid]){
                minDistance = 0;
                break;
            }
                
            if(i < c[mid]){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
            
            minDistance = min(minDistance, abs(c[mid] - i));
        }
        
        maxDistance = max(minDistance, maxDistance);
    }
        
    return maxDistance;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = flatlandSpaceStations(n, c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
