// GENERATING THE SERIES OF CATALAN NUMBERS
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    // OPTIMISING THE IO OPERATIONS FROM STDIO
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // GENERATING CATALAN NUMBER SERIES
    // NTH CATALAN NUMBER - C0CN-1 + C1CN-2 + C2CN-3 + ... + CN-1C0, WHERE C0 = C1 = 1
    // ANALYTICAL FORMULA - (1/N+1) * 2NCN
    int n;
    cin >> n;
    int catalan[n + 1];
    catalan[0] = catalan[1] = 1;
    // COMPUTING CATALAN NUMBERS USING BOTTOM-UP APPROACH
    for(int idx = 2; idx <= n ; idx++) {
        catalan[idx] = 0;
        for(int iter = 0; iter < idx ; iter ++) 
            catalan[idx] += catalan[iter] * catalan[idx - 1 - iter];
    }

    // DISPLAYING CATALAN NUMBERS
    for(int idx = 0 ; idx < n ; idx++)
        cout << catalan[idx] << " ";
    cout << endl;
    return 0;
}