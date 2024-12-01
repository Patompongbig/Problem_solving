#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> num;
    int n, m, count = 0;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> m;
        num.push_back(m);
    }
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (num[i] < num[j]){
                count += 1;
            }
            else{
                continue;
            }
        }
    }
    cout << count;
    return 0;
}