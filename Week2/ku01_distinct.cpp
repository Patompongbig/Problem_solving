#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n, input;
    cin >> n;

    set<int> answer;
    vector<int> num(n);

    for(int i = 0; i < n; i++){
        cin >> num[i];
        answer.insert(num[i]);
    }

    for(int i = 0; i < n; i++){
        int value = num[i];
        for(int j = i + 1; j < n; j++){
            value += num[j];
            answer.insert(value);
        }
    }

    cout << answer.size();
}