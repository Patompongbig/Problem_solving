#include <iostream>
#include <set>
using namespace std;

int main(){
    int n, m, value;
    set<int> x;

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> value;
        x.insert(value);
    }
    for (int i = 0; i < m; i++){
        cin >> value;
        auto high = x.lower_bound(value);
        auto low = (high == x.begin()) ? x.end() : prev(high);
        int lower = value - *low;
        int higher = *high - value;

        if (high == x.end()){
            cout << *low << '\n';
            continue;
        }
        else if (low == x.end()){
            cout << *high << '\n';
            continue;
        }

        if (lower < 0){
            lower = -lower;
        }

        if (higher < 0){
            higher = -higher;
        }

        if (lower <= higher){
            cout << *low << '\n';
        }
        else{
            cout << *high << '\n';
        }
    }
}