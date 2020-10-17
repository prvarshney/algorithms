// PROBLEM - LASTDIGIT - https://www.spoj.com/problems/LASTDIG/
#include <iostream>

#define mod 10

using namespace std;
typedef long long int BigInt;

int
main(int argc, char* argv[]) {
    // OPTIMISING IO OPERATIONS
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ATTACHING IO WITH FILES
    freopen("inputs.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);
    // TAKING INPUT FROM CONSOLE
    int t;
    BigInt a, b;
    cin >> t;
    while(t--) {
        // WORKING ON EACH TEST CASE
        cin >> a >> b;
        int res = 1;
        while(b) {
            if(b & 1 > 0)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        cout << res << "\n";
    }
    return 0;
}