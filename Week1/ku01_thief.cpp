#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> num = {1};
    int n, k, t;

    cin >> n >> k >> t;
    
    int gift = 1 + k;
    num.insert(gift);

    while (gift != 1){
        if (gift == t){
            break;
        }
        gift += k;
        if (gift > n){
            gift = gift % n;
        }
        num.insert(gift);
    }

    int count = num.size();
    cout << count;

    return 0;
}