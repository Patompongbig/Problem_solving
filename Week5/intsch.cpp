#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxIntervals(vector<pair<int, int>>& interval) {
    sort(interval.begin(), interval.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    });

    int count = 0;
    int end = -1;

    for (auto& x : interval) {
        if (x.first >= end) { 
            count++;
            end = x.second; 
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> interval(n);

    for (int i = 0; i < n; i++) {
        cin >> interval[i].first >> interval[i].second;
    }

    cout << maxIntervals(interval) << '\n';

    return 0;
}