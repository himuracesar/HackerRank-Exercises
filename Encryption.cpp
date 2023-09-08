#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
    stringstream ss(s);
    
    string item = "";
    string sNoSpace = "";
    string message = "";
    
    float sqrtL = 0;
    
    while(getline(ss, item, ' '))
        sNoSpace += item;
        
    //cout << "sNoSpace:: " << sNoSpace << endl;
    sqrtL = sqrt(sNoSpace.length());
    
    int row = round(sqrtL);
    int col = ceil(sqrtL);
    //cout << "sqrt:: " << sqrtL << " row:: " << row << " col:: " << col << endl;
    
    int mat[row][col];
    for(auto i = 0; i < col; i++)
        for(auto j = 0; j < row; j++)
            mat[j][i] = -1;
    
    int irow = 0;
    int icol = 0;
    for(auto i = 0; i < sNoSpace.length(); i++)
    {
        mat[irow][icol++] = sNoSpace.at(i);
        
        if(icol == col)
        {
            icol = 0;
            irow++;
        }
    }
    
    for(auto i = 0; i < col; i++)
    {
        for(auto j = 0; j < row; j++)
        {
            if(mat[j][i] > -1)
                message += mat[j][i];
        }
        message += " ";
    }
    
    return message;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
