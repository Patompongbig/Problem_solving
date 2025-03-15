#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, l, count = 0;
    cin >> n >> l;
    vector<pair<int, int>> house;

    for (int i = 0; i < n; i++){
        int s, t;
        cin >> s >> t;
        house.push_back({s, t});
    }

    int start = 0;
    for(auto h : house){
        if(start == 0 || start < h.second - l){
            start = h.first;
            count++;
        }
    }
    cout << count;
}