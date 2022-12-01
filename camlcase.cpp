//https://www.hackerrank.com/challenges/camelcase/problem
//Easy
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'camelcase' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int camelcase(string s) {
    int w = 0 ; 
    for(auto c:s)
    {
        if(c >='A' && c<= 'Z') w++ ; 
    }
    
    return w+1 ; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
