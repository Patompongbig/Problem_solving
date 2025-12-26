#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<pair<int, int>> car;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int price, eff;
        cin >> price >> eff;
        car.push_back({price, eff});
    }

    sort(car.begin(), car.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    int highest = car[0].first, count = 0;
    for (auto i = 0; i < n - 1; i++){
        if(highest <= car[i+1].first){
            count += 1;
        }
        else{
            highest = car[i + 1].first;
        }
    }

    cout << count;
}