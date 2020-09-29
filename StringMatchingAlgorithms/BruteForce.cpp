#include <iostream>

using namespace std;
int
main(int argc, char* argv[]) {
    string text, pattern;
    cin >> text >> pattern;

    int n = text.length(), m = pattern.length();
    for(int i = 0 ; i < n - m + 1 ; i++) {
        bool flag = true;
        for(int j = 0 ; j < m ; j++) 
            if(text.at(i + j) != pattern.at(j))
                flag = false;

        if(flag) {
            cout << "Found at pos : " << i << endl;
            return 0;
        }
    }

    cout << "Not found" << endl;
    return 0;
}