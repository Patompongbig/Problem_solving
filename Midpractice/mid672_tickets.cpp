#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 100010;

int n, m, k, s;

vector<int> weight;
vector<int> ticket;
vector<int> adj[MAX_N];
vector<int> success;
int deg[MAX_N];

void read_input(){
    cin >> n >> m >> k >> s;
    for(int i = 0; i < n; i++){
        int w;
        cin >> w;
        deg[i] = 0;
        weight.push_back(w);
    }

    for(int i = 0; i < k; i++){
        int p;
        cin >> p;
        ticket.push_back(p);
    }

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

void bfs(int max_w){
    discovered[0] = true;
    layer[0] = 0;

    list<int> current_layer;
    list<int> next_layer;

    current_layer.push_back(0);
    int loop = s;

    while(loop--){
        for(auto i = current_layer.begin(); i != current_layer.end(); i++){
            int u = *i;
            for (int d = 0; d < deg[u]; d++){
                int v = adj[u][d];
                if(!discovered[v] && weight[v] <= max_w + 1){
                    next_layer.push_back(v);
                    discovered[v] = true;
                    layer[v] = layer[u] + 1;
                }
            }
        }
        current_layer = next_layer;
        next_layer.clear();
    }

    if(discovered[n-1] == true){
        success.push_back(1);
    }
    else{
        success.push_back(0);
    }
}

int main(){
    int lowest = 1000000;
    read_input();
    for (int i = 0; i < k; i++){
        init();
        bfs(i);
        if (success[i] == 1 && ticket[i] <= lowest){
            lowest = ticket[i];
        }
    }
    for (auto x : success){
        cout << x << " ";
    }
    cout << '\n';
    if (lowest == 1000000){
        cout << -1;
    }
    else{
        cout << lowest;
    }
}