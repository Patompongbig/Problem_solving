#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; i++) {
            cin >> items[i].first >> items[i].second;
        }
        vector<int> dp(31, 0);
        for (auto &item : items) {
            int p = item.first;
            int w = item.second;
            for (int j = 30; j >= w; j--) {
                if (dp[j - w] + p > dp[j]) {
                    dp[j] = dp[j - w] + p;
                }
            }
        }
        int g, total = 0;
        cin >> g;
        while (g--) {
            int mw;
            cin >> mw;
            total += dp[mw];
        }
        cout << total << endl;
    }
    return 0;
}