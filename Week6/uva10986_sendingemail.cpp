#include<iostream>
#include<vector>
#include<set>

#define MAX_N 100010
#define INFINITY 1000000000
using namespace std;

int N, n, m, s, t;

void dijkstra(int n, int s, vector<vector<int>>& adj, vector<vector<int>>& length, vector<int>& d){
    bool scanned[MAX_N];
    set<pair<int,int>> node;
    for (int u = 0; u < n; u++) {
        d[u] = INFINITY;
        scanned[u] = false;
    }

    d[s] = 0;
    node.insert({0, s});

    while (!node.empty()) {
        auto pu = *(node.begin());
        node.erase(node.begin());
        int u = pu.second;

        if (scanned[u]) {
            continue;
        }
        scanned[u] = true;

        for (size_t dd = 0; dd < adj[u].size(); dd++) {
            int v = adj[u][dd];
            int weight = length[u][dd];

            if (d[v] > d[u] + weight) {
                node.erase({d[v], v});
                d[v] = d[u] + weight;
                node.insert({d[v], v});
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){

        cin >> n >> m >> s >> t;
        vector<vector<int>> adj(n);
        vector<vector<int>> length(n);
        vector<int> d(n);
        
        for (int j = 0; j < m; j++){
            int u, v, w;
            cin >> u >> v >> w;

            adj[u].push_back(v);
            length[u].push_back(w);

            adj[v].push_back(u);
            length[v].push_back(w);
        }

        dijkstra(n, s, adj, length, d);
        cout << "Case #" << i+1 << ": ";
        if (d[t] == INFINITY){
            cout << "unreachable" << '\n';
        }
        else {
            cout << d[t] << '\n';
        }
    }

}