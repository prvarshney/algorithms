#include <iostream>
#include <vector>

using namespace std;
int
main(int argc, char* argv[]) {
    string test, pattern;
    cin >> test >> pattern;

    // 0. FINDING THE LENGTH OF TEST & PATTERN STRING
    int n = test.length(), m = pattern.length();
    // 1. CALCULATING PREFIX FUNCTION ARRAY FOR PATTERN STRING
    vector<int> prefix(m);
    prefix[0] = 0;
    int i = 0, j = 1;
    while(j < m) {
        if(pattern[i] == pattern[j]) {
            prefix[j] = i + 1;
            i += 1;
            j += 1;
        }
        else if( i > 0)
            i = prefix[i - 1];
        else 
            prefix[j ++ ] = 0;
    }

    // 2. MATCHING THE GIVEN TEST STRING WITH THE PATTERN STRING
    i = 0, j = 0;       // USING TWO POINTER APPROACH, I -> TEST & J -> PATTERN
    while( i < n && j < m) {
        if(test[i] == pattern[j]) {
            i += 1;
            j += 1;
        }
        else if(j > 0)
            j = prefix[j - 1];
        else
            i += 1;
    }
    // IF PATTERN CONTAINS IN TEST STRING, THEN J == M
    if(j == m)
        cout << i - m << endl;
}