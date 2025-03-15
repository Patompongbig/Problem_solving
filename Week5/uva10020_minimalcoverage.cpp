#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int test;
    cin >> test;

    for (int i = 0; i < test; i++){
        cout << '\n';

        int M, count = 0;
        vector<pair<int, int>> segment;
        vector<pair<int, int>> answer;
        cin >> M;

        while (true){
            int l, r;
            cin >> l >> r;
            if (l == 0 && r == 0){
                break;
            }
            segment.push_back({l, r});
        }
        sort(segment.begin(), segment.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if (a.first == b.first){
                return a.second > b.second;
            }
            return a.first < b.first;
        });

        int start = 0;
        pair<int, int> tmp = {-1000, -1000};

        for (auto s : segment){
            if (s.first > start && tmp.second > start){
                answer.push_back(tmp);
                start = tmp.second;
                count++;
                if (start >= M){
                    break;
                }
            }
            if (s.first <= start && s.second > start){
                if (s.second > tmp.second){
                    tmp = s;
                    if (s == segment.back()){
                        answer.push_back(tmp);
                        start = tmp.second;
                        count++;
                    }
                }
            }
        }
        if (answer.empty() || answer.back().second < M){
            cout << "0\n";
        }
        else{
            cout << count << '\n';
            for (auto a : answer){
                cout << a.first << " " << a.second << '\n';
            }
        }
    }
}