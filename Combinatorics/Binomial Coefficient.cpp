#include <iostream>

using namespace std;
typedef long long int ll;

int mod = 1e9 + 7;
ll power(int a, int x) {
    if(x == 0) return 1;
    if(x == 1) return a;
    ll temp = power(a, x / 2);
    temp = (temp * temp) % mod;

    if(x & 1 > 0)   // CHECKING FOR ODD POWER
        return (temp * a) % mod;
    else 
        return temp;
}

ll inverse(ll val) {
    return power(val, mod - 2) % mod;
}

ll nCr(int n, int k) {
    k = min(k, n - k);   // SYMETRIC PROPERTY OF COMBINATIONS
    // COMPUTING NTH FACTORIAL
    ll dp[n + 1];
    dp[0] = 1;
    for(int idx = 1; idx <= n ; idx++)
        dp[idx] = (dp[idx - 1] * idx) % mod;

    ll res = dp[n];
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
    ll res = 1;
    res = (res * power(a, k)) % mod;
    res = (res * power(b, n - k)) % mod;
    res = (res * nCr(n, n - k)) % mod;
    // DISPLAYING OUTPUT
    cout << res << endl;
    return 0;
}