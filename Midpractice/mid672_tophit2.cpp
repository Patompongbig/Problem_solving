
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
    int L, N, K;
    cin >> L >> N >> K;
    vector<int> book(L);
    set<int> aut;
    vector<pair<int, int>> deg(L);

    for (int i = 0; i < L; i++){
        int tmp;
        int a;
        cin >> a;
        book[i] = a;
        deg[i].first = i + 1;
    }

    for (int i = 0; i < N; i++){
        int vote;
        cin >> vote;
        vote--;
        deg[vote].second++;
    }

    sort(deg.begin(), deg.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    });

    auto x = deg.begin();
    for (int i = 0; i < K;){
        int book_num = x -> first;
        if (aut.find(book[book_num - 1]) == aut.end()){
            aut.insert(book[book_num - 1]);
            cout << book_num << '\n';
            x++;
            i++;
        }
        else{
            x++;
        }
    }
}


#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
    int L, N, K;
    cin >> L >> N >> K;
    vector<int> book(L);
    set<int> aut;
    vector<pair<int, int>> deg(L);

    for (int i = 0; i < L; i++){
        int tmp;
        int a;
        cin >> a;
        book[i] = a;
        tmp = i + 1;
        deg[i].first = tmp;
    }

    for (int i = 0; i < N; i++){
        int vote;
        cin >> vote;
        vote--;
        deg[vote].second++;
    }

    sort(deg.begin(), deg.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second){
            return a.first < b.second;
        }
        return a.second > b.second;
    });

    for (auto x : deg){
        cout << x.first << '/' << x.second << " ";
    }
    
    cout << '\n';

    auto x = deg.begin();
    for (int i = 0; i < K;){
        int book_num = x -> first;
        if (aut.find(book[book_num - 1]) == aut.end()){
            aut.insert(book[book_num - 1]);
            cout << book_num << '\n';
            x++;
            i++;
        }
        else{
            x++;
        }
    }
    cout << '\n';
    for(auto x : aut){
        cout << x << " ";
    }

}