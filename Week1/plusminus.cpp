#include<iostream>

using namespace std;

int main(){
    int n, answer, value;
    char com;
    cin >> n;
    n = n + n - 1;

    for(int i = 0; i < n; i++){
        if (i == 0){
            cin >> answer;
            continue;
        }
        if (i % 2 == 0){
            if (com == '+'){
                cin >> value;
                answer += value;
            }
            else{
                cin >> value;
                answer -= value;
            }
        }
        else{
            cin >> com;
        }
    }
    cout << answer;
}