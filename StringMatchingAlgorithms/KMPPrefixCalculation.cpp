#include <iostream>
#include <vector>

using namespace std;
int
main(int argc, char* argv[]) {
    string text, pattern;
    cin >> text >> pattern;

    int n = text.length(), m = pattern.length();
    vector<int> prefix(n);
    prefix[0] = 0;
    int i = 0, j = 1;
    while(j < n) {
        if(text.at(i) == text.at(j)) {
            prefix[j] = i + 1;
            i += 1;
            j += 1;
        }
        else if( i > 0 && text.at(i) != text.at(j))
            i = prefix[i - 1];
        else {
            prefix[j] = 0;
            j += 1;
        }
    }

    for(int val : prefix)
        cout << val << "\t" ;
}