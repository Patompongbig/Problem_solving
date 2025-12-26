#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> lace(n);

    for (int i = 0; i < n; i++){
        lace[i] = {i + 1};
    }

    for (int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        for(int j = 0; j < n - i; j++){
            
        }
    }

}