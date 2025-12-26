#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct State {
    int other;
    int length;
    State(int o = 0, int l = 0) : other(o), length(l) {}
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> cars(n);
        for (int i = 0; i < n; ++i) {
            cin >> cars[i];
        }

        map<int, State> front_map; // key: L (front), value: (R, length)
        map<int, State> end_map;   // key: R (end), value: (L, length)

        for (int x : cars) {
            int new_front_length = 1;
            int new_front_R = x;
            for (auto &entry : front_map) {
                int L = entry.first;
                State state = entry.second;
                if (L < x) {
                    if (state.length + 1 > new_front_length || (state.length + 1 == new_front_length && state.other < new_front_R)) {
                        new_front_length = state.length + 1;
                        new_front_R = state.other;
                    }
                }
            }

            int new_end_length = 1;
            int new_end_L = x;
            for (auto &entry : end_map) {
                int R = entry.first;
                State state = entry.second;
                if (R > x) {
                    if (state.length + 1 > new_end_length || (state.length + 1 == new_end_length && state.other > new_end_L)) {
                        new_end_length = state.length + 1;
                        new_end_L = state.other;
                    }
                }
            }

            // Update front_map for x as front
            if (front_map.find(x) == front_map.end() || new_front_length > front_map[x].length || (new_front_length == front_map[x].length && new_front_R < front_map[x].other)) {
                front_map[x] = State(new_front_R, new_front_length);
            }

            // Update end_map for x as end
            if (end_map.find(x) == end_map.end() || new_end_length > end_map[x].length || (new_end_length == end_map[x].length && new_end_L > end_map[x].other)) {
                end_map[x] = State(new_end_L, new_end_length);
            }
        }

        int max_len = 0;
        for (auto &entry : front_map) {
            max_len = max(max_len, entry.second.length);
        }
        for (auto &entry : end_map) {
            max_len = max(max_len, entry.second.length);
        }

        cout << max_len << endl;
    }

    return 0;
}