#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    while (true){
        int n, d, r;
        vector<int> morning;
        vector<int> evening;

        cin >> n >> d >> r;
        if (n == 0 && d == 0 && r == 0){
            break;
        }

        for (int i = 0; i < n; i++){
            int hour;
            cin >> hour;
            morning.push_back(hour);
        }
        for (int i = 0; i < n; i++){
            int hour;
            cin >> hour;
            evening.push_back(hour);
        }
        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end(), greater<int>());
        int count = 0;
        for(int i = 0; i < n; i++){
            if(morning[i] + evening[i] > d){
                count += (morning[i] + evening[i] - d) * r;
            }
        }
        cout << count << '\n';
    }

}