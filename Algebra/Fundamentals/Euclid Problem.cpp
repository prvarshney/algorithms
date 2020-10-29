#include <iostream>

using namespace std;
int gcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1, res;
    res = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return res;
}

int 
main(int argc, char* argv[]) {
    // OPTIMISING IO OPERATIONS
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ATTACHING FILES WITH IO
    freopen("inputs.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);
    int a, b;
    while(cin >> a >> b) {
        int x, y, d;
        d = gcd(a, b, x, y);
        printf("%d %d %d\n", x, y, d);
    }
    return 0;
}