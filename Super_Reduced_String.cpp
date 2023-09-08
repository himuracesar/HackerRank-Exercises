#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string reduceString(string s){
    string strReduced;
    
    for(auto i = 0; i < s.length(); i++){
        if(i+1 < s.length() && s[i] == s[i+1])
            i++;
        else
            strReduced += s[i];
    }
    
    return strReduced;
}

string superReducedString(string s) {
    string strReduced = "";
    
    while(strReduced != s){
        strReduced = s;
        s = reduceString(strReduced);
    }
    
    if(strReduced == "")
        return "Empty String";
    else
        return strReduced;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
