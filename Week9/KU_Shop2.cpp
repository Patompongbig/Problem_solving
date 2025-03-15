#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,p ;
    cin >> n;
    vector<int> price(n);

    for(int i = 0; i<n; i++){
        cin >> price[i];
    }

    vector<int> dp(n);
    dp[0] = price[0];
    dp[1] = max(price[0],price[1]);

    for(int i = 2; i<n; i++){ 
        dp[i] = max(dp[i - 1], dp[i - 2] + price[i]);
    }
    
    cout << dp[n-1] << endl;
    return 0;
}