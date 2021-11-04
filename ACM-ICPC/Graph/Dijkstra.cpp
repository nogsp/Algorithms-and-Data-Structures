#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define inf LLONG_MAX
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<pll>> Grafo;


Grafo grafo;
vector<ll> dist;

void dijkstra(ll origem) {
    priority_queue<pll,vpll,greater<pll>> heap;
    dist.assign(grafo.size(), inf);
    dist[origem] = 0;
    heap.push({0, origem});
    while(!heap.empty()) {
        auto aux = heap.top();
        heap.pop();
        ll p = aux.first;
        ll u = aux.second;
        if(p > dist[u]) {
            continue;
        }
        for(auto [v, w] : grafo[u]) {
            if(dist[v] > p + w){
                dist[v] = p + w;
                heap.push({dist[v], v});
            }
        }
    }
}   

int main() {
    ll n, m;
    cin >> n >> m;
    grafo.assign(n, vector<pll>());
    dist.assign(n, inf);
    while(m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        grafo[u].push_back({v, w});
    }
    dijkstra(0);
    

}