#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> length;


int main(){
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++){
        int value;
        cin >> value;
        length.push_back(value);

        if (i > 0){
            for (int j = 0; j < length.size() - 1; j++){
                length[j] += value;
            }
        }
    }

    for (int i = 0; i < q; i++){
        int value;
        cin >> value;
        if(find(length.begin(), length.end(), value) != length.end()){
            cout << 'Y';
        }
        else{
            cout << 'N';
        }
    }
}