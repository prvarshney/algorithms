#include <iostream>
#include <cmath>

#define limit 10000000
bool sieve[limit];
int dp[limit];

using namespace std;
int main(int argc, char* argv[]) {
    // OPTIMISING IO OPERATIONS
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ATTACHING IO FILES WITH PROGRAM
    freopen("inputs.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);
    // BUILDING SIEVE OF PRIMES
    fill_n(sieve, limit, true);
    for(int iter = 2; iter * iter < limit ; iter ++)
        if(sieve[iter])
            for(int factor = iter * iter ; factor < limit ; factor += iter )
                sieve[factor] = false;

    // BUILDING DP
    fill_n(dp, limit, 0);
    int p, q, t, n;
    for(int x = 1; (p = x * x) < limit ; x++) {
        for(int y = 1; (p + (q = y * y * y * y)) < limit ; y ++) {
            if( sieve[p + q] )
                dp[p + q] = 1;
        }
    }

    // BUILDING PREFIX SUM ARRAY
    for(int iter = 1 ; iter < limit ; iter ++)
        dp[iter] += dp[iter - 1];

    cin >> t;
    while(t --) {
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}