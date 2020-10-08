// CURIOUS ARRAY - http://codeforces.com/problemset/problem/407/C
#include <iostream>

#define mod 1000000007
#define maxn 100100

using namespace std;
typedef long long int BigInt;

BigInt power(int a, int x) {
    if(x == 0) return 1;
    if(x == 1) return a;
    BigInt temp = power(a, x / 2);
    temp = (temp * temp) % mod;
    if(x & 1 > 0)   // CHECK FOR ODD POWER
        return (temp * a) % mod;
    else
        return temp;
}

BigInt inverse(BigInt num) {
    return power(num, mod - 2);
}

BigInt nCr(int n, int r, BigInt factorial[]) {
    r = min(r, n - r);
    BigInt res = factorial[n - r];
    res = (res * factorial[r]) % mod;
    res = inverse(res);
    res = (res * factorial[n]) % mod;
    return res;
}

int main(int argc, char* argv[]) {
    // OPTIMISING IO OPERATIONS FROM STDIO
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // TAKING INPUT FROM CONSOLE
    int n, m;
    cin >> n >> m;
    BigInt arr[n + 1];
    for(int idx = 1 ; idx <= n ; idx++)
        cin >> arr[idx];

    // CALCULATING FACTORIALS
    BigInt factorial[maxn];
    factorial[0] = 1;
    for(int idx = 1; idx < maxn; idx++)
        factorial[idx] = (factorial[idx - 1] * idx) % mod;

    // PERFORMING QUERY OPERATIONS
    while(m--) {
        int l, r, k;
        cin >> l >> r >> k;
        for(int j = l ; j <= r ; j ++) {
            BigInt carry = nCr(j - l + k, k, factorial);
            arr[j] = (arr[j] + carry) % mod;
        }
    }

    // DISPLAYING ARRAY TO CONSOLE
    for(int idx = 1 ; idx <= n; idx++)
        cout << arr[idx] << " ";
    cout << endl;
    return 0;
}