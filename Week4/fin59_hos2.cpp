#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 100010;

int n, m, H;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input(){
    cin >> n >> m >> H;
    for (int i = 0; i < n; i++){
        deg[i] = 0;
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

vector<int> arr;
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
    int loop = H;

    while(loop--){
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

    int count = 0;
    for (int i = 0; i < n; i++){
        if(discovered[i] == true){
            count++;
        }
    }
    arr.push_back(count);
}

int main(){
    read_input();
    for (int i = 0; i < n; i++){
        init();
        bfs(i);
    }
    cout << *max_element(arr.begin(), arr.end());
}