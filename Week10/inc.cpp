#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, max_streak, tmp = 0, max_num, streak_now;
    vector<vector<int>> streak;
    vector<int> current;
    vector<int> track;

    cin >> n;
    for (int i = 0; i < n; i++){
        int value;
        cin >> value;

        if(i == 0){
            max_streak = 1;
            max_num = value;
            streak_now = 1;
            streak.push_back({value});
            current = streak[i];
        }

        else{
            if (value > max_num){
                tmp = max_num;
                max_num = value;
                streak_now++;
                current.push_back(value);
                streak.push_back(current);
            }
            else{

            }
        }

        if (streak_now > max_streak){
            max_streak = streak_now;
        }
    }
}