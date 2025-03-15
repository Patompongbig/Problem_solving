#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    vector<int> group(n + 1, -1);
    bool bipartite = true;
    int count = 0;

    int bipartite_value = 0;
    map<int, int> day;

    for (int j = 0; j < m; j++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (day[u] == 0){
            day[u] = j+1;
        }
        if (day[v] == 0){
            day[v] = j+1;
        }
    }

    for (int l = 1; l <= n; l++){
        if (group[l] == -1){
            queue<int> q;
            q.push(l);
            group[l] = 0;

            while (!q.empty()){
                int front = q.front();
                q.pop();
                for (int p : adj[front]){
                    if (group[p] == -1){
                        group[p] = group[front] ^ 1;
                        q.push(p);
                        count += 1;
                    }
                    else if (group[p] == group[front]){
                        bipartite = false;
                        bipartite_value = p;
                        break;
                    }
                }
            }
        }
    }
    for (int l = 1; l <= n; l++){
        if (group[l] == -1){
            count += 1;
        }
    }
    cout << day[bipartite_value];
}