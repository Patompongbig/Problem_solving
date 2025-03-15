#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> patience;
    int count = 0;

    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        for (int j = 0; j < input; j++){
            int x, y;
            cin >> x >> y;
            patience.push_back({x, y + 1});
            count += x;
        }
        for (auto x = patience.begin(); x != patience.end();){
            x -> second--;
            if(x -> second == 0){
                count -= x -> first;
                patience.erase(x);
            }
            else{
                x++;
            }
        }
        cout << count << '\n';
    }
}