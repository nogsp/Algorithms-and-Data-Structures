#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> Grafo;

Grafo grafo;
vector<ll> visited;

void DFS(ll u) {
    if(visited[u]) return;
    visited[u] = 1;
    for(auto v : grafo[u]) {
        DFS(v);
    }
}


int main() {
    ll n, m;
    cin >> n >> m;
    grafo.assign(n, vector<ll>());
    visited.assign(n, 0);
    while(m--) {
        ll a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    ll cont = 0;
    for(ll i = 0; i < n; i++) {
        if(!visited[i]) {
            cont++;
            DFS(i);
        }
    }
    cout<<"This graph has "<<cont<< "components\n";

}