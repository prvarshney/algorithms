// CURIOUS ARRAY - http://codeforces.com/problemset/problem/407/C
#include <iostream>

#define mod 1000000007
#define maxm 110

using namespace std;
typedef long long int BigInt;

int main(int argc, char* argv[]) {
    // OPTIMISING IO FROM STDIO
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // TAKING INPUT FROM CONSOLE
    int n, m;
    cin >> n >> m;
    BigInt arr[n];
    for(int idx = 1 ; idx <= n ; idx++)
        cin >> arr[idx];

    // COMPUTING BINOMIAL COEFFICIENTS USING PASCALS TRIANGLE
    BigInt dp[n + 200][maxm + 10];
    for(int i = 0 ; i < n + 200 ; i++) 
        for(int j = 0 ; j <= min(i, maxm); j++)
            if(j == 0 || i == j)
                dp[i][j] = 1;
            else 
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            
    // READING M QUERY FROM CONSOLE
    BigInt carry[n + 10][maxm + 10];
    fill_n(&carry[0][0], sizeof(carry) / sizeof(BigInt), 0);
    while(m--) {
        int l, r, k;
        cin >> l >> r >> k;
        for(int iter = 0 ; iter <= k ; iter ++) 
            carry[l][iter] = (carry[l][iter] + dp[k][k - iter]) % mod;
        for(int iter = 0 ; iter <= k ; iter ++)
            carry[r + 1][iter] = (carry[r + 1][iter] - dp[r - l + k + 1][k - iter] + mod) % mod;
    }

    for(int i = 1; i <= n ; i++) {
        for(int j  = maxm ; j >= 0 ; j--) {
            carry[i][j] = (carry[i][j] + carry[i - 1][j]) % mod;
            carry[i][j] = (carry[i][j] + carry[i - 1][j + 1]) % mod;
        }
    }

    for(int idx = 1; idx <= n ; idx++)
        cout << (arr[idx] + carry[idx][0] + mod) % mod << " ";
    return 0;
}