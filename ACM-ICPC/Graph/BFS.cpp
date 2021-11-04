#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> Grafo;

Grafo grafo;
vector<ll> visited;

void BFS(ll origin) {
    queue<ll> q;
    q.push(origin);
    visited[origin] = 1;
    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        for(auto v : grafo[u]) {
            if(visited[v]) continue;
            visited[v] = 1;
            q.push(v);
        }
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
            BFS(i);
        }
    }
    cout<<"This graph has "<<cont<< "components\n";

}