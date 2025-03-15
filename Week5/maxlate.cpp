#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first){
        return a.second < b.second; 
    }

    return a.first < b.first; 
}

int main()
{
    int n;
    vector<pair<int, int>> work;

    cin >> n;

    while (n--) {
        int d, c;
        cin >> d >> c;
        work.push_back({d, c}); 
    }
    sort(work.begin(), work.end(), compare); 

    int current = 0;
    int penalty = 0;

    for (auto x : work) {
        current += x.second; 
        int delay = current - x.first;

        if (delay > 10) {
            penalty = max(penalty, (delay - 10) * 1000);
        }
    }
    cout << penalty << '\n';
}