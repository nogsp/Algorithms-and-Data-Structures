#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;


int main() {
    ll n, b;
    cin >> n >> b;
    vector<ll> nimber(n+1, 0); 

    for(ll i = 1; i<=n; i++) {
        set<int> reachable;
        for(ll j = 1; j <= i; j*=b) {
            reachable.insert(nimber[i-j]);
        }
        while(reachable.count(nimber[i])) {
            nimber[i]++;
        }    
        cout << "estado " << i << " nimber = " << nimber[i] << endl;
    }
}