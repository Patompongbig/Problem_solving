#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(){
    list<int> num;
    int m, number;
    string k;

    cin >> m;

    for (int i = 0; i < m; i++){
        cin >> k;
        if (k == "li"){
            cin >> number;
            num.push_front(number);
        }
        else if (k == "ri"){
            cin >> number;
            num.push_back(number);
        }
        else if (k == "lr"){
            int front = num.front();
            num.push_back(front);
            num.pop_front();
        }
        else if (k == "rr"){
            int end = num.back();
            num.push_front(end);
            num.pop_back();
        }
    }

    for (int value : num){
        cout << value << endl;
    }
    return 0;
}