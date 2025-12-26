#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, length = 1, end = 0;
    cin >> n;
    
    vector<int> value(n);
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    vector<int> dp(n, 1);
    vector<int> prev(n, -1); 
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (value[i] > value[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > length) {
            length = dp[i];
            end = i;
        }
    }

    vector<int> answer;
    for (int i = end; i != -1; i = prev[i]) {
        answer.push_back(value[i]);
    }
    
    reverse(answer.begin(), answer.end());

    cout << length << '\n';
    for (int i = 0; i < length; i++) {
        cout << answer[i] << " ";
    }
}
