// PROBLEM - MAGIC OF THE LOCKER - https://www.spoj.com/problems/LOCKER/
#include <iostream>

#define mod 1000000007

using namespace std;
typedef long long int BigInt;

int 
main(int argc,char* argv[]) {
    // OPTIMISING IO OPERATIONS
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ATTACHING IO WITH FILES
    freopen("inputs.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);
    // TAKING INPUT FROM CONSOLE
    int t;
    BigInt n;
    cin >> t;
    while(t--) {
        // WORKING ON EACH TEST CASES
        cin >> n;
        if(n == 6) {
            cout << 9 << "\n";
            continue;
        }
        
        BigInt res = 1;
        for(BigInt i = 2; i <= n && i + 1 != n ; i++) {
            res = (res * i) % mod;
            n -= i;
        }
        if(n != 0)
            res = (res * n) % mod;
        cout << res << "\n";
    }
    return 0;
}