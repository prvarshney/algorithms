#include <iostream>
#include <vector>

using namespace std;
int 
main(int argc, char* argv[]) {
    string pattern, str;    // STRING PATTERN TO CHECK AND TEST STRING
    cin >> str >> pattern;

    // FINDING THE POSITION WHERE PATTERN MATCHES
    // USING RABIN KARP HASHING ALGORITHM
    // GENERATING PRODUCT OF PRIMES
    const int base = 2;
    const int mod = 1e9 + 7;
    vector<int64_t> p(max( str.length(), pattern.length() ));
    p[0] = 1;
    for(int idx = 1 ; idx < p.size() ; idx++) 
        p[idx ] = ( p[idx - 1] * base ) % mod;

    // GENERATING HASHCODE OF PATTERN
    // hash("abc") = a*p^0 + b*p^2 + c*p^3
    uint64_t hashcode = 0;
    for(int idx = 0 ; idx < pattern.length() ; idx ++) 
        hashcode = (hashcode + (pattern.at(idx) - 'a' + 1) * p[idx]) % mod;

    // GENERATING PREFIX SUM ARRAY OF TEST STRING
    vector<uint64_t> hashstring(str.length() + 1 , 0 );     // INITIALIZING THE PREFIX SUM ARRAY BY 0
    for(int idx = 0 ; idx < hashstring.size() - 1 ; idx++) 
        hashstring[idx + 1] = (hashstring[idx] + (str.at(idx) - 'a' + 1) * p[idx] ) % mod;

    // STRING MATCHING USING ROLLING HASH ALGORITHM
    for(int idx = 0 ; idx + pattern.length() - 1 < str.length() ; idx++ ) {
        int64_t chash = (hashstring[idx + pattern.length()] + mod - hashstring[idx]) % mod;
        if( chash == (hashcode * p[idx]) % mod )
            cout << idx << endl;
    }
}