#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> state;
vector<int> answer;
vector<vector<int>> adj;

void topo_sort(int n) {
    state.assign(n + 1, 0);
    answer.clear();
    bool cycle = true;

    for (int i = 1; i <= n; ++i) {
        if (state[i] == 0) {
            state[i] = 1;
            vector<int> s;
            s.push_back(i);

            while (!s.empty()) {
                int v = s.back();
                bool step = true;

                for (int u : adj[v]) {
                    if (state[u] == 0) {
                        state[u] = 1;
                        s.push_back(u);
                        step = true;
                    } else if (state[u] == 1) {
                        cycle = true;
                        break;
                    }
                }

                if (!step) {
                    state[v] = 2;
                    answer.push_back(v);
                    s.pop_back();
                }

                if (!cycle) {
                    break;
                }
            }

            if (!cycle) {
                break;
            }
        }
    }

    if (!cycle) {
        cout << "no" << endl;
    } else {
        reverse(answer.begin(), answer.end());
        for (int v : answer) {
            cout << v << endl;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    topo_sort(n);

    return 0;
}