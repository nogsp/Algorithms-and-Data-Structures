#include <bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;


int is_prime[20000000];
vector<int> primes;
void sieve(int n) {
    memset(is_prime, 1, sizeof(is_prime));
    
    for(int p = 3; p * p <= n; p += 2) {
        if(is_prime[p]) {
            for(int np = p * 2; np <= n; np += p) {
                is_prime[np] = false;
            }
        }
    }
    primes.assign(1, 2);
    for(int i = 3; i <= n; i+=2) 
        if(is_prime[i])
            primes.push_back(i);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    sieve(100);
    for(auto p : primes) {
        cout << p << endl;
    }
    if(is_prime[23]) cout << "YES" << endl;
    else cout << "NO" << endl;

    if(is_prime[24]) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0; 
}
