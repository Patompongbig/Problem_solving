#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> rail;
    int n, value;

    cin >> n;

    while (n != 0){
        for (int i = 0; i < n; i++){
            cin >> value;
            if (value == 0){
                cin >> n;
                break;
            }
            else{
                rail.push_back(value);
            }
        }

        
    }
}
