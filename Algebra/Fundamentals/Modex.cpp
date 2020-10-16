// Problem - MODEX - https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=247&page=show_problem&problem=3671
#include <iostream>

using namespace std;
typedef long long int BigInt;

BigInt power(int x, int y, int n) {
    if(y == 0)  return 1;
    if(y == 1)  return x;
    BigInt temp = power(x, y / 2, n);
    temp = (temp * temp) % n;

    if(y & 1 > 0)
        return (temp * x) % n;
    else 
        return temp;
}

int 
main(int argc, char* argv[]) {
    // OPTIMISING IO OPERATIONS
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // LINKING FILES WITH STDIO
    freopen("inputs.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);
    // TAKING INPUT FROM CONSOLE
    int n, x, y, t;
    cin >> t;
    while (t --) {
        cin >> x >> y >> n;
        cout << power(x, y, n) << "\n";
    }
    cin >> t;   // REMOVING BUFFER 0
    return 0;
}