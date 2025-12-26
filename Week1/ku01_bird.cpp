#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    int n, count = 0;
    cin >> n;
    vector<int> tree(n);

    for (int i = 0; i < n; i++){
        cin >> tree[i];
    }

    for(int i = 0; i < n; i++){
        if (i == 0){
            if (tree[i] > tree[i + 1]){
                count += 1;
            }
        }
        else if (i == n - 1){
            if (tree[i] > tree[i - 1]){
                count += 1;
            }
        }
        else {
            if (tree[i] > tree[i - 1] && tree[i] > tree[i + 1]){
                count += 1;
            }
        }
    }

    cout << count;
}