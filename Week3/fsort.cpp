#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n;
    vector<pair<int,int>> x;
    set<int> same;

    cin >> n;
    for (int i = 0; i < n; i++){
        int y;
        cin >> y;

        if (same.find(y) == same.end()){
            x.push_back({1, y});
            same.insert(y);
        }

        else{
            for (auto& p : x) {
                if (p.second == y){
                    p.first += 1;
                    break;
                }
            }
        }
    }

    sort(x.begin(), x.end(), [](const pair<int, int>&a, const pair<int, int>& b) {
        if (a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    });

    for (auto w : x) {
        cout << w.second << '\n';
    }
}