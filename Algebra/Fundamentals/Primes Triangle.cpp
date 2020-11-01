#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

#define limit 100000000
bool sieve[limit + 1];
pair<int, int> dp[limit + 1];

int main(int argc, char* argv[]) {
    // OPTIMISING IO OPERATIONS
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // BUILDING SIEVE
    fill_n(sieve, limit, true);
    sieve[0] = sieve[1] = false;
    for(int iter = 2 ; iter * iter <= limit ; iter++)
        if(sieve[iter])
        for(int factor = iter * iter ; factor <= limit ; factor += iter)
            sieve[factor] = false;

    // POPULATING THE DP
    int first = 1, second = 1;
    for(int idx = 0 ; idx <= limit ; idx++) {
        if(sieve[idx]) {
            if(second > first) {
                first += 1;
                second = 1;
            }
            dp[idx].first = first;
            dp[idx].second = second++;
        }
        else
            dp[idx].first = dp[idx].second = -1;
    }
    // ATTACHING IO FILES
    freopen("inputs.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);

    // TAKING INPUT FROM CONSOLE
    int t, n;
    cin >> t;
    while(t --) {
        cin >> n;
        if(sieve[n])
            cout << dp[n].first << " " << dp[n].second << "\n";
        else
            cout << -1 << "\n";
    }
    return 0;
}