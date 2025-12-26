#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string rna;
    cin >> rna;

    int n = rna.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    auto pair = [](char a, char b) {
        return ( (a == 'A' && b == 'U') || (a == 'U' && b == 'A') ||
                 (a == 'C' && b == 'G') || (a == 'G' && b == 'C') );
    };

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (j - i < 5) {
                dp[i][j] = 0;
            } 
            else {
                int max_val = dp[i + 1][j];
                for (int k = i + 5; k <= j; k++) {
                    if (pair(rna[i], rna[k])) {
                        int current = 1;
                        if (i + 1 < k - 1)
                            current += dp[i + 1][k - 1];

                        if (k + 1 < j)
                            current += dp[k + 1][j];

                        if (current > max_val) {
                            max_val = current;
                        }
                    }
                }
                dp[i][j] = max_val;
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}