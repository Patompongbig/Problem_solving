#include <iostream>
#include <vector>

using namespace std;

int main(){
    int K, N;
    vector<pair<int, int>> contract;
    vector<pair<int, int>> weight;
    vector<int> arr;

    cin >> K >> N;
    for (int i = 0; i < K; i++){
        int c, p, w;
        cin >> c >> p >> w;
        contract.push_back({c, p});
        weight.push_back({w, 0});
    }

    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    for(auto t : contract){
        
    }
}