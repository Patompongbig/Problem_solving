#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int w, h, m, n;
    cin >> w >> h >> m >> n;

    vector<int> x(m + 1);
    vector<int> y(n + 1);

    int input = 0;
    for (int i = 0; i < m; i++){
        cin >> x[i];
        x[i] -= input;
        input += x[i];
    }
    x[m] = w - input;
    input = 0;

    for (int i = 0; i < n; i++){
        cin >> y[i];
        y[i] -= input;
        input += y[i];
    }
    y[n] = h - input;

    sort(x.begin(), x.end(), greater<int>());
    sort(y.begin(), y.end(), greater<int>());

    if (x[0] * y[1] > x[1] * y[0]){
        cout << x[0] * y[0] << " " << x[0] * y[1];
    }
    else{
        cout << x[0] * y[0] << " " << x[1] * y[0];
    }
}