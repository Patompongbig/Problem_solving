#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        string field;
        cin >> n >> field;
        
        int count = 0;
        int current = 0;
        while (current < n) {
            if (field[current] == '.') {
                count++;
                current += 3;
            } else {
                current++;
            }
        }
        cout << "Case " << i << ": " << count << endl;
    }
}