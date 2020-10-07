// HACKEREARTH - hackerearth.com/problem/algorithm/binomial-coefficient-1/description/
#include <iostream>

using namespace std;
typedef long long int ll;

ll mod = 1e9 + 7;
ll power(int a, int x) {
    if(x == 0)  return 1;
    if(x == 1) return a;
    ll temp = power(a, x/2) % mod;
    temp = (temp * temp) % mod;
    if(x & 1 > 0)   //  MEANS POWER IS ODD
        return (temp * a) % mod;
    else
        return temp;
}

ll binexpo(int n, int k) {
    k = min(k, n - k);
    ll dp[2][k + 1];
    for(int i = 0 ; i <= n ; i++) {
        for(int j = 0 ; j <= i  && j <= k; j++) {
            if(j == 0 || i == j)
                dp[i % 2][j] = 1;
            else 
                dp[i % 2][j] = (dp[(i - 1) % 2][j - 1] + dp[(i - 1) % 2][j]) % mod;
        }
    }

    return dp[n % 2][k];
}

int main(int argc, char* argv[]) {
    // OPTIMISING IO FROM STDIN
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    // TAKING INPUT FROM STDIN
    int a, b, n, k;
    scanf("%d %d %d %d", &a, &b, &n, &k);
    // PROCESSING OUTPUT
    ll res = power(a, k);
    res = (res * power(b, n - k)) % mod;
    res = (res * binexpo(n, n - k)) % mod;

    cout << res << endl;
    return 0;
}