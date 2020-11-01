#include <iostream>
#include <algorithm>
#include <cmath>

#define limit 1000000
int sieve[limit];
int dp[limit];

using namespace std;
int isValid(int num) {
    // DOESNT CONTAINS ZERO BIT AND ALL ITS TRUNCATED
    // VALUES ARE PRIME AS WELL
    int temp = num;
    while(temp) {
        int bit = temp % 10;
        temp /= 10;
        if(bit == 0)
            return false;
    }

    int length = log10(num);
    int mult = pow(10, length);
    while(mult > 1) {
        if(sieve[num % mult] == 0)
            return false;
        mult /= 10;
    }
    return true;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // BUILDING SIEVE OF PRIMES
    fill_n(sieve, limit, 1);
    sieve[0] = sieve[1] = 0;
    for(int iter = 2 ; iter * iter < limit ; iter++) 
        if(sieve[iter])
        for(int factor = iter * iter ; factor < limit ; factor += iter)
            sieve[factor] = 0;

    // BUILDING PREFIX ARRAY
    for(int iter = 0; iter < limit ; iter ++) {
        if(sieve[iter]) {
            if( isValid(iter) )     // TRUE FOR THOSE NUMBERS FOR WHICH NEEDS TO AFRAID
                dp[iter] = dp[iter - 1] + 1;
            else
                dp[iter] = dp[iter - 1];
        }
        else 
            dp[iter] = dp[iter - 1];
    }
    // ATTACHING IO FILES
    freopen("inputs.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);

    // TAKING INPUT FROM CONSOLE
    int t, n;
    cin >> t;
    while(t --) {
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}