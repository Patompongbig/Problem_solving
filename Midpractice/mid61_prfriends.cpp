#include <iostream>
#include <set>

using namespace std;

int main(){
    int l, r, p;
    cin >> l >> r;
    if (l == 1){
        l = 2;
    }

    set<int> prime;
    for (int i = l; i <= r; i++){
        p = 0;
        for (int j = 2; j * j <= i; ++j){
            if (i % j == 0){
                p = 1;
                break;
            }
        }
        if (p == 0){
            prime.insert(i);
        }
    }
    
    int count = 0;
    int tmp;
    for (auto itr = prime.begin(); itr != prime.end(); itr++){
        if (itr == prime.begin()){
            tmp = *itr;
            continue;
        }
        if (*itr - tmp == 2){
            count++;
        }
        tmp = *itr;
    }
    cout << count;
}