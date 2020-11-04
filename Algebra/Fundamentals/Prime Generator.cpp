#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define limit 100000
bool sieve[limit];

using namespace std;
int main(int argc, char* argv[]) {
    // OPTIMISING IO OPERATIONS
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ATTACHING IO FILES WITH STDIO
    freopen("inputs.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);
    // BUILDING SIEVE
    fill_n(sieve, limit , true);
    for(int iter = 2; iter * iter < limit ; iter++) 
        if(sieve[iter])
        for(int factor = iter * iter ; factor < limit ; factor += iter)
            sieve[factor] = false;

    vector<int> primes;
    for(int idx = 2; idx < limit ; idx++)
        if(sieve[idx])
            primes.push_back(idx);
    
    // TAKING INPUT FROM CONSOLE
    int t, m, n;
    cin >> t;
    while(t --) {
        cin >> m >> n;
        bool sieve[n - m + 1];
        fill_n(sieve, n - m + 1, true);

        for(int idx = 0 ; idx < primes.size() && primes[idx] <= sqrt(n) ; idx++) {
            int prime = primes[idx];
            int base = (m / prime) * prime;
            if(base < m)
                base += prime;
            
            for(int factor = base ; factor <= n ; factor += prime)
                if(factor != prime)
                    sieve[factor - m] = false;
        }

        // PRINTING SEGMENTED SIEVE
        for(int idx = 0 ; idx < n - m + 1 ; idx++) 
            if(sieve[idx] && idx + m != 1 && idx + m != 0)
                cout << idx + m << "\n";

        cout << "\n";
    }
    return 0;
}