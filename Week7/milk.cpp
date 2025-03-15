#include <iostream>
#include <vector>

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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    for (int i = 0; i < Q; i++){
        char w;
        cin >> w;
        if (w == 'q'){
            int n, m;
            cin >> n >> m;
            bool inSameSet = (uf.find(n) == uf.find(m));
            cout << (inSameSet ? "yes" : "no") << '\n';
        }
        else{
            int n, m;
            cin >> n >> m;
            uf.unite(n, m);
        }
    }
}