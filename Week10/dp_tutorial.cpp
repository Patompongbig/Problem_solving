#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; 
    cin >> N;

    vector<int> X(N);
    vector<int> A(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    for (int i = 0; i < 4; i++) {
        A[i] = 0;
    }

    for (int i = 4; i < N; i++) {
        int max_val = X[i];
        
        for (int j = i - 4; j <= i; j++) {
            max_val = max(max_val, X[j]);
        }
        
        if (i >= 5) {
            A[i] = max(A[i - 1], A[i - 5] + max_val);
        } else {
            A[i] = max(A[i - 1], max_val);
        }
    }

    cout << A[N - 1] << endl;
    return 0;
}