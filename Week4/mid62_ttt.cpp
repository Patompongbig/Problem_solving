#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int j = 0; j < m; j++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> group(n + 1, -1);
    bool bipartite = true;

    for (int l = 1; l <= n; l++){
        if (group[l] == -1){
            queue<int> q;
            q.push(l);
            group[l] = 0;

            while (!q.empty()){
                if (bipartite == false){
                    break;
                }
                int front = q.front();
                q.pop();
                for (int p : adj[front]){
                    if (group[p] == -1){
                        group[p] = group[front] ^ 1;
                        q.push(p);
                    }
                    else if (group[p] == group[front]){
                        bipartite = false;
                        cout << p << " " << front;
                        break;
                    }
                }
            }
        }
    }
}