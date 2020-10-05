#include <iostream>

using namespace std;
int 
main(int argc, char* argv[]) {
    // OPTIMISING IO FROM STDIO
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // TAKING INPUT FROM CONSOLE
    int num;
    cin >> num;
    // PROCESSING OUTPUT
    for(int factor = 2 ; factor * factor <= num ; factor++) {
        int cnt = 0;
        while(num % factor == 0) {
            cnt += 1;
            num /= factor;
        }

        if(cnt > 0)
            cout << factor << " x " << cnt << endl;
    }

    // TO HANDLE PRIME NUMBERS
    if(num > 1)
        cout << num << " x " << 1 << endl;
    return 0;
}