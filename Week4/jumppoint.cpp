#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

void bfs(vector<vector<int>> &graph, int start, int goal) {
    queue<int> q;
    vector<bool> visited(graph.size(), false);
    vector<int> distance(graph.size(), -1); // unreach
    
    // bfs
    visited[start] = true;
    distance[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == goal) { // reach or not
            cout << distance[curr] << endl;
            return; // shortest distance
        }

        // neighbor
        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[curr] + 1;
                q.push(neighbor);
            }
        }
    }
    cout << -1 << endl; // unreachable
}

int main() {
    int n, r;
    cin >> n >> r;
    vector<pair<int,int>> coor;
    vector<vector<int>> graph; // adj, nodes that are connected to node graph[?]

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        coor.push_back({a,b});
    }

    coor.push_back({0,0});
    coor.push_back({100,100});

    graph.resize(coor.size());
    for (int j = 0; j < coor.size(); j++) {
        for (int k = j + 1; k < coor.size(); k++) {
            int dx = coor[j].first - coor[k].first;
            int dy = coor[j].second - coor[k].second;
            int sq_distance = dx*dx + dy*dy;
            if (sq_distance <= r*r) { // undirected edge
                graph[j].push_back(k); // add k to list of nodes connected to j
                graph[k].push_back(j);
            }
        }
    }

    int start = coor.size() - 2; // (0,0) at second last elem
    int goal = coor.size() - 1;  // (100,100) last elem
    bfs(graph, start, goal);
    // cout << -1 << endl;
}