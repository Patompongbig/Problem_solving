#include <iostream>

using namespace std;

int main(){
    int n, max, tmp = 0, tmp1;
    cin >> n;
    for (int i = 0; i < n; i++){
        int number;
        cin >> number;

        if (i == 0){
            max = number; 
        }
        if (i > 0){
            int tmp1 = max;
            if (tmp + number > max){
                max = tmp + number;
                tmp = tmp1;
            }
            else{
                tmp = max;
            }
        }
    }
    cout << max;
}