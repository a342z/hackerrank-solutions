//https://www.hackerrank.com/challenges/time-conversion
//Easy
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    if(s[s.size()-2]=='P')
    {
        if(s.substr(0,2)=="12") return s.substr(0,s.size()-2);
        return to_string(stoi(s.substr(0,2))+12)+s.substr(2,s.size()-4);
    }    
    else
    {
        if( s.substr(0,2)=="12" ) 
            return "00"+s.substr(2,s.size()-4);
        else
        {
            string hours = to_string(stoi(s.substr(0,2))) ; 
            if (hours.size()==1) hours = "0"+hours ;
            return hours+s.substr(2,s.size()-4);
        }
    }
        
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
