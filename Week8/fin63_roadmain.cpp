#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

#define MAX_N 100010
using namespace std;

class UnionFind {
    vector<int> rank, parent;
public:
    UnionFind(int size){
        rank.resize(size, 0);
        parent.resize(size);

        for(int i = 0; i < size; i++){
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] != i){
            parent[i] = find(parent[i]);
        }

        return parent[i];
    }

    void unite (int i, int j) {
        int irep = find(i);
        int jrep = find(j);

        if (irep == jrep){
            return;
        }

        if (rank[irep] < rank[jrep]){
            parent[irep] = jrep;
        }
        else if (rank[jrep] < rank[irep]){
            parent[jrep] = irep;
        }
        else{
            parent[jrep] = irep;
            rank[irep]++;
        }
    }
};

int main(){
    vector<pair<int, vector<pair<int, int>>>> graph;
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++){
        int u, v, w, D;
        cin >> u >> v >> w >> D;
        u--;
        v--;
        vector<pair<int, int>> node = {{u, v}};

        if (D == 1){
            graph.push_back({0, node});
        }
        else{
            graph.push_back({w, node});
        }
    }

    sort(graph.begin(), graph.end());

    UnionFind uf(N);
    int sum = 0;
    for (auto edge : graph){
        for (auto node : edge.second){
            if (uf.find(node.first) != uf.find(node.second)){
                uf.unite(node.first, node.second);
                sum += edge.first;
            }
        }
    }
    cout << sum;

}