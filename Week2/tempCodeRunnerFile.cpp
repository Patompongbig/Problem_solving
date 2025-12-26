#include <iostreaM>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n, input;
    cin >> n;

    set<int> answer;

    for(int i = 0; i < n; i++){
        cin >> input;
        if (i != 0){
            for (auto x : answer){
                answer.insert(x + input);
            }
        }
        answer.insert(input);
    }
    cout << answer.size();
}