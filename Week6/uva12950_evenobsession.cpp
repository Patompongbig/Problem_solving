#include<iostream>
#include<vector>
#include<set>
#include<sstream>

#define MAX_N 100010
#define INFINITY 1000000000
using namespace std;

int deg[MAX_N];
bool scanned[MAX_N];
vector<int> adj[MAX_N];
vector<int> length[MAX_N];

set<pair<int,int>> node;

int n,m;

void read_input(int n, int m){
    for(int i = 0; i < n; i++){
        deg[i] = 0;
    }

    for (int i = 0; i < m; i++){
        int u,v,w;
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
}

int d[MAX_N];

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
    while(true){
        string input;
        getline(cin, input);
        if (input.empty()){
            break;
        }

        stringstream ss(input);
        ss >> n;
        cin >> m;
        read_input(n, m);
    }
}