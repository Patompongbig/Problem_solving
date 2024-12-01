#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> num;
    int n, k, t, count = 0, min = 1000000000;

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> t;
        if (t < min){
            min = t;
        }
        num.push_back(t);
    }
    
    min = min * (k + 1);
    for (int value : num){
        value = value * k;
        if (value >= min){
            continue;
        }
        else{
            count += 1;
        }
    }
    cout << count;
    return 0;
}