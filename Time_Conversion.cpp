#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string hh = s.substr(0,2);
    string mer = s.substr(s.length() - 2, s.length());
    string militaryHour = "";
    //string militaryHour = s.substr(0,s.length() - 2);
    
    int hour = stoi(hh);
    if(mer == "AM")
        if(hour == 12)
            militaryHour = "00" + s.substr(2,s.length() - 4);
        else
            militaryHour = s.substr(0,s.length() - 2);
    else{
        if(hour != 12)
            hour = 12 + hour;
        militaryHour = to_string(hour) + s.substr(2,s.length() - 4);
    }
    
    return militaryHour;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
