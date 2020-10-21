#include <iostream>

using namespace std;
typedef long long int BigInt;

BigInt power(BigInt a, BigInt x, BigInt m) {
    if(x == 0) return 1;
    if(x == 1) return a;
    BigInt temp = power(a, x / 2, m);
    temp = (temp * temp) % m;

    if(x & 1 > 0) 
        return (temp * a) % m;
    else
        return temp;
}

int 
main(int argc, char* argv[]) {
    // OPTIMISING IO OPERATIONS
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ATTACHING FILES WITH IO
    // freopen("inputs.txt", "r", stdin);
    // freopen("outputs.txt", "w", stdout);
    // TAKING INPUT FROM CONSOLE
    BigInt x, a, n, c;
    while(true) {
        cin >> x >> a >> n >> c;
        if(x == 0 && a == 0 && n == 0 && c == 0)
            return 0;

        BigInt asf = 0;
        for(int iter = 1 ; iter < n + 1; iter ++) 
            if( iter == n)
                asf = (asf + (x - 1) * power(a, iter, c)) % c;
            else
                asf = (asf - power(a, iter, c) + c) % c;

        cout << asf << "\n";
    }
}