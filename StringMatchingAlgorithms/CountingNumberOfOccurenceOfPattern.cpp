#include <iostream>
#include <vector>

using namespace std;
int
main(int argc, char* argv[]) {
    string test, pattern;
    cin >> test >> pattern;

    // CALCULATING THE LENGTH OF TEST & PATTERN STRING 
    int n = test.length(), m = pattern.length();
    // CALCULATING THE PREFIX OF PATTERN STRING
    vector<int> prefix(m);
    prefix[0] = 0;
    int i = 1, j = 0;       // I -> SUFFIXFIX AND J-> PREFIX
    while( i < m) {
        if(pattern[i] == pattern[j] ) {
            prefix[i] = j + 1;
            i += 1;
            j += 1;
        }
        else if(j > 0)
            j = prefix[j - 1];
        else
            prefix[i ++ ] = 0;
    }

    for(int val : prefix)
        cout << val << "\t";
    cout << endl;
    // MATCHING THE TEST STRING WITH THE PATTERN STRING
    // USING TWO POINTER APPROACH, I -> TEST & J -> PATTERN
    i = 0, j = 0;
    int counter = 0;
    while( i < n ) {
        if(test[i] == pattern[j]) {
            i += 1;
            j += 1;
        }
        else if(j > 0)
            j = prefix[j - 1];
        else 
            i += 1;

        // THAT MEANS A PATTERN GOT MATCH HERE IN TEST
        if( j == m) {     
            counter += 1;
            cout << i - m << " - " << i << endl;
            j = prefix[j - 1];
        }
    }

    cout << "Number of Substring Matched : " << counter << endl;
}