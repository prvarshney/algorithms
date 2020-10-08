#include <iostream>

using namespace std;
typedef long long int BigInt;

int mod = 1e9 + 7;
BigInt power(int a, int x) {
    if(x == 0) return 1;
    if(x == 1) return a;
    BigInt temp = power(a, x / 2);
    temp = (temp * temp) % mod;

    if(x & 1 > 0)   // CHECKING FOR ODD POWER
        return (temp * a) % mod;
    else 
        return temp;
}

BigInt inverse(BigInt val) {
    return power(val, mod - 2) % mod;   // USING FERMAT'S LITTLE THEOREM
}

BigInt nCr(int n, int k) {
    k = min(k, n - k);   // SYMETRIC PROPERTY OF COMBINATIONS
    // COMPUTING NTH FACTORIAL
    BigInt dp[n + 1];
    dp[0] = 1;
    for(int idx = 1; idx <= n ; idx++)
        dp[idx] = (dp[idx - 1] * idx) % mod;

    BigInt res = dp[n];
    res = (res * inverse(dp[n - k])) % mod;
    res = (res * inverse(dp[k])) % mod;
    return res;
}

int main(int argc, char* argv[]) {
    // OPTIMISING IO FROM STDIO
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // TAKING INPUT FROM CONSOLE
    int a, b, n, k;
    scanf("%d %d %d %d", &a, &b, &n, &k);
    // PROCESSING OUTPUT
    BigInt res = 1;
    res = (res * power(a, k)) % mod;
    res = (res * power(b, n - k)) % mod;
    res = (res * nCr(n, n - k)) % mod;
    // DISPLAYING OUTPUT
    cout << res << endl;
    return 0;
}