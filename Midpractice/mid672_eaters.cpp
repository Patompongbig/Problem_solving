#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int L, N, G;

    cin >> L >> N >> G;

    int count = 0;
    for (int i = 0; i < L; i++){
        int tmp = G;
        vector<int> plate;
        for (int j = 0; j < N; j++){
            int w;
            cin >> w;
            plate.push_back(w);
        }
        sort(plate.begin(), plate.end());
        for (auto x = plate.begin(); x != plate.end(); x++){
            if (*x < tmp){
                tmp -= *x;
                count++;
            }
        }
    }

    cout << count;
}