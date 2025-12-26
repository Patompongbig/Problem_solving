#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> computeLIS(const vector<int>& seq) {
    int n = seq.size();
    vector<int> lis(n, 0);
    vector<int> tail; 
    tail.reserve(n);
    
    for (int i = 0; i < n; i++){
        int x = seq[i];
        
        auto it = lower_bound(tail.begin(), tail.end(), x);
        int pos = it - tail.begin();
        if (it == tail.end()) {
            tail.push_back(x);
        } else {
            *it = x;
        }
        lis[i] = pos + 1;
    }
    return lis;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while (cin >> n) {
        vector<int> seq(n);
        for (int i = 0; i < n; i++){
            cin >> seq[i];
        }
        
        vector<int> lis = computeLIS(seq);
        
        vector<int> revSeq = seq;
        reverse(revSeq.begin(), revSeq.end());
        vector<int> revLIS = computeLIS(revSeq);
        vector<int> lds(n, 0);
        for (int i = 0; i < n; i++){
            lds[i] = revLIS[n - 1 - i];
        }
        
        int maxWavio = 0;
        for (int i = 0; i < n; i++){
            int k = min(lis[i], lds[i]);
            int candidate = 2 * k - 1;
            maxWavio = max(maxWavio, candidate);
        }
        
        cout << maxWavio << "\n";
    }
    
    return 0;
}
