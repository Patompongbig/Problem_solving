#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int c;
    cin >> c;
    for (int i = 0; i < c; i++){
        int n, h, ta, td;
        cin >> n >> h >> ta >> td;
        vector<int> height;
        for (int j = 0; j < n; j++){
            int value;
            cin >> value;
            height.push_back(value);
        }
        int max_time = ta * n;
        int new_time = 0;
        sort(height.begin(), height.end(), greater<int>());
        for (auto x = height.begin(); x != height.end(); x++){
            if (*x + height.back() < h && x != prev(height.end())){
                new_time += td;
                height.pop_back();
            }
            else{
                new_time += ta;
            }
        }
        if (new_time < max_time){
            max_time = new_time;
        }
        cout << "Case " << i+1 << ": " << max_time << '\n';
    }
}