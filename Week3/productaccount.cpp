#include <iostream>
#include <map>

using namespace std;

int main(){
    int n, com, id, num;
    map<int,int> x;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> com;
        if (com == 1){
            cin >> id >> num;

            x[id] += num;
        }

        else if (com == 2){
            cin >> id;

            cout << x[id] << '\n';
        }

        else if (com == 3){
            cin >> id >> num;

            if (x.find(id) == x.end() || x[id] == 0){
                cout << 0 << '\n';
            }
            else{
                if (x[id] < num){
                    cout << x[id] << '\n';
                    x[id] = 0;
                }
                else {
                    x[id] -= num;
                    cout << num << '\n';
                }
            }
        }
    }
}