#include <iostream>
using namespace std;

const int MAXN = 100010;
int parent[MAXN];
int ssize[MAXN];

void initialize(int N) {
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        ssize[i] = 1;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unions(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX != rootY) {
        if (ssize[rootX] < ssize[rootY]) {
            parent[rootX] = rootY;
            ssize[rootY] += ssize[rootX];
        } else {
            parent[rootY] = rootX;
            ssize[rootX] += ssize[rootY];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    initialize(N);

    while (Q--) {
        char command;
        int x, y;
        cin >> command >> x >> y;
        
        if (command == 'c') {
            unions(x - 1, y - 1);
        } else if (command == 'q') {
            if (find(x) == find(y)) {
                cout << "yes" << "\n";
            }
            else {
                cout << "no" << "\n";
            }
        }
    }

    return 0;
}