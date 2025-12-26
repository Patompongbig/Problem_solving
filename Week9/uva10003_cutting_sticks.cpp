#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    while(true){
        int l;
        cin >> l;
        if(l == 0) break;

        int n;
        cin >> n;

        vector<int> cuts(n + 2);
        cuts[0] = 0;
        for (int i = 1; i <= n; i++){
            cin >> cuts[i];
        }
        cuts[n + 1] = l;

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 2; len < n + 2; len++){
            for (int i = 0; i + len < n + 2; i++){
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + (cuts[j] - cuts[i]));
                }
            }
        }

        cout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
    }
    return 0;
}