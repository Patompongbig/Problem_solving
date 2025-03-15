#include <iostream>
#include <list>
using namespace std;

int main(){
    int n = 1;
    list<int> deck;

    while (true){
        cin >> n;
        if (n == 0){
            break;
        }

        for (int i = 1; i <= n; i++){
            deck.push_back(i);
        }

        cout << "Discarded cards: ";
        while (deck.size() > 1){
            if (deck.size() == 2){
                cout << deck.front();
                deck.pop_front();
            }
            else{
                cout << deck.front() << ", ";
                deck.pop_front();
                deck.push_back(deck.front());
                deck.pop_front();
            }
        }

        cout << '\n' << "Remaining card: " << deck.front() << '\n';

        deck.clear();
    }

}