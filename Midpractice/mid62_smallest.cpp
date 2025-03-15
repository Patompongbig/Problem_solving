#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> height;

    for (int i = 0; i < n; i++){
        int value;
        cin >> value;
        height.push_back(value);
    }

    for (int i = 0; i < q; i++){
        int choice;
        cin >> choice;
        if (choice == 1){
            int j;
            cin >> j;
            auto endd = height.begin();
            advance(endd, j);
            int min = *min_element(height.begin(), endd);
            cout << min << '\n';
        }

        if (choice == 2){
            int k, count = 0;
            cin >> k;
            for (auto x : height){
                if (k > x){
                    break;
                }
                count++;
            }
            cout << count << '\n';
        }
    }
}