#include <iostream>
#include <vector>

using namespace std;
int
main(int argc, char* argv[]) {
    string test, pattern;
    cin >> test >> pattern;

    // 0. FINDING THE LENGTH OF TEST & PATTERN
    int n = test.length(), m = pattern.length();
    // 1. GENERATING PREFIX FUNCTION FOR THE PATTERN
    vector<int> prefix(m);
    prefix[0] = 0;
    int i = 1, j = 0;
    while( i < m ) {
        if(pattern.at(i) == pattern.at(j)) {
            prefix[i] = j + 1;
            i += 1;
            j += 1;
        }
        else if(j > 0 )
            j = prefix[j - 1];
        else {
            prefix[i] = 0;
            i += 1;
        }
    } 

    // 2. FINDING THE POSITION WHERE PATTERN EXISTS IN THE TEST STRING
    i = 0, j = 0;
    while( i < n && j < m) {
        if(test.at(i) == pattern.at(j)) {
            i += 1;
            j += 1;
        }
        else if(j > 0)
            j = prefix[j - 1];
        else 
            i += 1;
    }

    if(j == m)
        cout << i - m << endl;
}