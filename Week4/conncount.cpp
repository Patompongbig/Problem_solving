#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int MAX_N = 100010;

int n, m;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        deg[i] = 0;
    }

    //undirected graph
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);

        deg[u]++;
        deg[v]++;
    }
}

bool discovered[MAX_N];

void init(){
    for(int i = 0; i < n; i++){
        discovered[i] = false;
    }
}

int layer[MAX_N];

void bfs(int s){
    discovered[s] = true;
    layer[s] = 0;

    list<int> current_layer;
    list<int> next_layer;

    current_layer.push_back(s);

    while(!current_layer.empty()){
        for(auto i = current_layer.begin(); i != current_layer.end(); i++){
            int u = *i;
            for (int d = 0; d < deg[u]; d++){
                int v = adj[u][d];
                if(!discovered[v]){
                    next_layer.push_back(v);
                    discovered[v] = true;
                    layer[v] = layer[u] + 1;
                }
            }
        }
        current_layer = next_layer;
        next_layer.clear();
    }
}

int main(){
    int count = 0;
    read_input();
    init();
    for (int s = 0; s < n; s++){
        if (!discovered[s]){
            count += 1;
            bfs(s);
        }
    }
    cout << count;
}