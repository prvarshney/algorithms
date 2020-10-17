// PROBLEM - LEADING AND TRAILING - https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1970
#include <iostream>
#include <cmath>

#define mod 1000

using namespace std;
typedef long long int BigInt;

int main(int argc, char* argv[]) {
    // OPTIMISING IO OPERATIONS
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ATTACHING IO TO FILES
    freopen("inputs.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);
    // TAKING INPUT FROM CONSOLE
    BigInt t, n, k;
    cin >> t;
    while(t --) {
        cin >> n >> k;
        // CALCULATING LEADING BITS
        double power = k * log10(n);
        int leading = pow(10, power - floor(power)) * 100;
        // CALCULATING n ^ k
        BigInt trailing = 1;
        while(k) {
            if(k & 1 > 0) 
                trailing = (trailing * n % mod) % mod;
            n %= mod;
            n = (n * n) % mod;
            k >>= 1;
        }
        // CALCULATING TRAILING BITS 
        trailing %= 1000;
        // DISPLAYING RESULT
        printf("%03d...%03d\n", leading, trailing);
    }
    return 0;
}