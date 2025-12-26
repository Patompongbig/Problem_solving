#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> point(n);
    vector<int> maxx(n);
    int count_3 = 0;
    int count_2 = 0;
    int max = 0;

    for (int i = 0; i < n; i++){
        cin >> point[i];
    }

    auto itr = point.begin();
    for (int i = n-1; i >= 0; i--){
        if (max < point[i]){
            max = point[i];
        }
        maxx[i] = max;
    }

    for (int i = 0; i < n-1; i++){
        if (point[i]*3 <= maxx[i]){
            count_3++;
        }
        else if (point[i]*2 <= maxx[i]){
            count_2++;
        }
    }
    cout << count_3 << " " << count_2;

}