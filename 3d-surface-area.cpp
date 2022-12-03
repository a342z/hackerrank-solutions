//https://www.hackerrank.com/challenges/3d-surface-area/
//Medium
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'surfaceArea' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY A as parameter.
 */

int surfaceArea(vector<vector<int>> A) {
    int width = A.size();
    int height= A[0].size();
    int topArea = height*width*2 ; 
    int sideArea = 0 ;
    //Calculating Side Area
    for(int i = 0 ; i <width ; i++)
    {   sideArea+=A[i][0];
        for(int j = 1 ; j <height ; j++)
        {
            sideArea+=abs(A[i][j]-A[i][j-1]);
        } 
        sideArea+=A[i][height-1];
    }
    
     //Calculating Front Area
    int frontArea=0;
    for(int j = 0 ; j <height ; j++)
    {   frontArea+=A[j][0];
        for(int i = 1 ; i <width ; i++)
        {
            frontArea+=abs(A[i][j]-A[i-1][j]);
        } 
        frontArea+=A[j][width-1];
    }
    
    return frontArea+sideArea+topArea ; 
    
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int H = stoi(first_multiple_input[0]);

    int W = stoi(first_multiple_input[1]);

    vector<vector<int>> A(H);

    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        string A_row_temp_temp;
        getline(cin, A_row_temp_temp);

        vector<string> A_row_temp = split(rtrim(A_row_temp_temp));

        for (int j = 0; j < W; j++) {
            int A_row_item = stoi(A_row_temp[j]);

            A[i][j] = A_row_item;
        }
    }

    int result = surfaceArea(A);

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