#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> num;
    int m, number;
    char k;
    cin >> m;
    auto pos = num.begin();

    for (int i = 0; i < m; i++){
        pos = num.begin();
        cin >> k >> number;
        if (k == 'I'){
            num.push_front(number);
        }
        else{
            if (number <= num.size()){
                advance(pos, number - 1);
                num.erase(pos);
            }
            else{
                continue;
            }
        }
    }

    for (int value : num){
        cout << value << endl;
    }
    return 0;
}