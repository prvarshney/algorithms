// PROBLEM - BIGMOD - https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=310&mosmsg=Submission+received+with+ID+25621668
#include <iostream>

using namespace std;
typedef long long int BigInt;

int 
main(int argc, char* argv[]) {
    // OPTIMISING IO OPERATIONS FROM STDIO
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // TIEING STDIO WITH FILES
    freopen("inputs.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);

    // TAKING INPUT FROM CONSOLE
    BigInt b, p, m;
    string strbuff;

    while(cin >> b) {
        cin >> p >> m;
        getline(cin, strbuff);
        // USING BINARY EXPONENTIATION
        BigInt prod = 1;
        while(p) {
            if(p & 1 > 0)
                prod = (prod * b) % m;
            b = (b * b) % m;
            p >>= 1;
        }

        cout << prod << "\n";
    }

    return 0;
}