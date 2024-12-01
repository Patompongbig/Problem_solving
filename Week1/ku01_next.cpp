#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> number, list;
  int n, m;

  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> m;
    number.push_back(m);
    list.push_back(i + 1);
  }
  for(int value : number) {
    cout << value << " ";
  }
  for(int value : list) {
    cout << value << " ";
  }
  return 0;
}