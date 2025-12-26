#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, p;
    cin >> n;
    vector<int> value(n + 1);
    vector<int> select(n + 1, 0); 
    
    value[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        cin >> value[i];
    }

    for (int i = 3; i < n + 1; i++) {
        select[i] = max(max(value[i] + select[i - 3], select[i - 1]), select[i - 2]);
    }

   cout << select[select.size()-1];

    return 0;
}