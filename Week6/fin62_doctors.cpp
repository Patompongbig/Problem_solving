#include<iostream>
#include<vector>
#include<set>

#define MAX_N 100010
#define INFINITY 1000000000
using namespace std;

int deg[MAX_N];
bool scanned[MAX_N];
vector<int> adj[MAX_N];
vector<int> length[MAX_N];

set<pair<int,int>> node;

int d[MAX_N];
int n, m, l;

void dijkstra(int s){
    for(int u = 0; u < n; u++){
        d[u] = INFINITY;
        scanned[u] = false;
    }

    d[s] = 0;
    node.insert(make_pair(0,s));

    while(!node.empty()){
        auto pu = *(node.begin());
        node.erase(node.begin());
        int u = pu.second;
        if(scanned[u]){
            continue;
        } 

        scanned[u] = true;
        for(int dd = 0; dd < deg[u]; dd++){
            int v = adj[u][dd];
            if(d[v] > d[u] + length[u][dd]){
                d[v] = d[u] + length[u][dd];
                node.insert(make_pair(d[v], v));
            }
        }
    }
}

int main(){
    cin >> n >> m >> l;
    
    int patience[100010];

    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        patience[i] = num;
    }

    for(int i = 0; i < n; i++){
        deg[i] = 0;
    }
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        adj[u].push_back(v);
        length[u].push_back(w);

        adj[v].push_back(u);
        length[v].push_back(w);

        deg[u]++;
        deg[v]++;
    }
    dijkstra(0);

    int sum = 0;
    for (int i = 1; i < n; i++){
        int pat_cost, car_cost;
        pat_cost = patience[i] * d[i];
        car_cost = l * d[i];
        sum += min(pat_cost, car_cost);
    }

    cout << sum << '\n';

}