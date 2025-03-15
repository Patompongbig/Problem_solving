#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int MAX_N = 1010;
vector<int> adj[MAX_N];

int main(){
    int n, q;
    cin >> n >> q;

    vector<string> maze(n);
    for(int i = 0; i < n; i++){
        cin >> maze[i];
    }
    for(int i = 0; i < q; i++){
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int r, c, a, b;
        cin >> r >> c >> a >> b;
        r--;
        c--;
        a--;
        b--;
    }

}