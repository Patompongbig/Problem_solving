#include <iostream>
#include <list>
using namespace std;

const int MAX_N = 100010;
list<int> trains[MAX_N];

int main(){
    int num, m, n;
    char letter;

    cin >> num;

    for (int i = 0; i < num; i++){
        cin >> letter >> m >> n;

        if (letter == 'N'){
            trains[n].push_back(m);
        }

        else if (letter == 'M'){
            trains[n].splice(trains[n].end(), trains[m]);
        }
    }

    for (int i = 0; i < MAX_N; i++){
        if (!trains[i].empty()) {
            for (int value : trains[i]){
                cout << value << '\n';
            }
        }
    }
}