#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> carrot(n);
    for(int i = 0; i < n; i++){
        cin >> carrot[i]; 
    }
    int count = 0;
    vector<int> dp(n);
    int max_v1 = carrot[0];
    int max_v2 = carrot[1];
    int highest = max(carrot[0],carrot[1]);
    dp[0] = carrot[0];
    dp[1] = max(carrot[0],carrot[1]);

    for(int i = 2; i < n; i++){
        if (count == k){
            break;
        }
        if (dp[i - 1] < dp[i - 2] + carrot[i]){
            
        }
        else if (dp[i - 1] < highest + carrot[i]){

        }
    }

}