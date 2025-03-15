#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void dfs(int v, vector<vector<int>> &adj, vector<int> &state, vector<int> &answer){
    state[v] = 1;
    for (int u : adj[v]){
        if (state[u] == 0){
            dfs(u, adj, state, answer);
        }
    }
    answer.push_back(v + 1);
}

int main(){
    while (true){
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0){
            break;
        }
        vector<vector<int>> adj(n);
        vector<int> state(n, 0);
        vector<int> answer;
        map<int, int> sum;

        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            adj[a-1].push_back(b-1);
            sum[b-1]++;
        }

        for(int i = 0; i < n; i++){
            if(state[i] == 0){
                dfs(i, adj, state, answer);
            }
        }

        reverse(answer.begin(), answer.end());

        for (int x : answer){
            cout << x << " ";
        }
        cout << '\n';
    }
}