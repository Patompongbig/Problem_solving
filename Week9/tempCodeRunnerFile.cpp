#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> value(n);

    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    vector<int> dp(n, 0);

    dp[0] = value[0];
    dp[1] = max(value[0], value[1]);
    dp[2] = max(dp[1], value[2]);

    for (int i = 3; i < n; i++) {
        dp[i] = max({dp[i - 1], dp[i - 2], dp[i - 3] + value[i]});
    }

    cout << dp[n - 1] << endl;

    return 0;
}
