#include <iostream>
#include <string>
using namespace std;

int main() {
    string code;
    cin >> code;
    int x = 0, y = 0;

    for (int i = 0; i < code.size(); i++){
        if (code[i] == 'N'){
            y += 1;
        }
        if (code[i] == 'E'){
            x += 1;
        }
        if (code[i] == 'S'){
            y -= 1;
        }
        if (code[i] == 'W'){
            x -= 1;
        }
        if (code[i] == 'Z'){
            y = 0;
            x = 0;
        }
    }
    cout << x << ' ' << y;

    return 0;
}