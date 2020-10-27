#include <iostream>

using namespace std;
typedef long long int BigInt;

BigInt 
GCD(BigInt a, BigInt b) {
    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int
main(int argc, char* argv[]) {
    // OPTIMISING IO OPERATIONS
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ATTACHING IO FILES
    freopen("inputs.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);
    // TAKING INPUT FROM CONSOLE
    BigInt t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        BigInt prod = a * b;
        BigInt gcd = GCD(a, b);
        cout << gcd << " " << prod / gcd << "\n";
    }
    return 0;
}