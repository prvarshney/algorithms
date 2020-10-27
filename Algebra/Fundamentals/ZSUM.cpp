#include <iostream>

#define mod 10000007

using namespace std;
typedef long long int BigInt;

BigInt power(BigInt a, BigInt x) {
    if(x == 0) return 1;
    if(x == 1) return a % mod;

    BigInt temp = power(a, x / 2);
    temp = (temp * temp) % mod;

    if(x & 1 > 0)   // CHECK FOR ODD POWERS
        return (temp * a) % mod;
    else 
        return temp;
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
    BigInt n, k;
    while(true) {
        cin >> n >> k;
        if(n == 0 && k == 0) 
            return 0;

        BigInt res = (power(n, k) + power(n, n)) % mod;
        res = (res + (2 * power(n - 1, k)) % mod) % mod;
        res = (res + (2 * power(n - 1, n - 1)) % mod) % mod;

        cout << res << "\n";
    }
}