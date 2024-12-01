#include <iostream>
#include <vector>
using namespace std;

vector<int> cal(const vector<int>& number, int n){
  vector<int> result;
  for (int i = 0; i < n; i++){
    if (i == 0){
      if (number[i] < n){
        result.push_back(0);
      }
      else{
        result.push_back(1);
      }
    }
    else{
      if (number[i] < number[i-1]){
        result.push_back(0);
      }
      else{
        result.push_back(1);
      }
    }
  }
  return result;
}

int main() {
  vector<int> number, result;
  int n, t, code;

  cin >> n >> t;
  for (int i = 0; i < n; i++){
    cin >> code;
    number.push_back(code);
  }
  if (t == 1){
    result = cal(number, n);
  }
  else{
    vector<int> Z;
    Z.push_back(number[0]);
    for (int i = 1; i < n; i++){
      if (number[i] > 2*Z[i-1]){
        Z.push_back(Z[i-1] + 1);
      }
      else{
        Z.push_back(Z[i-1] - 1);
      }
    }
    result = cal(Z, n);
  }
  
  for (int value : result){
    cout << value << "\n";
  }
  return 0;
}