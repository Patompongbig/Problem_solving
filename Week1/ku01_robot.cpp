#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int h1, h2, b1, b2, x, y;
    cin >> h1 >> h2 >> b1 >> b2 >> x >> y;

    int min1 = min(h1, b1);
    int min2 = min(h2, b2);
    int max_total = 0;

    for (int i = 0; i <= min1; i++) {
        for (int j = 0; j <= min2; j++) {
            int same = i + j;
            int same2 = min(same, x);

            int rem_h1 = h1 - i;
            int rem_b1 = b1 - i;
            int rem_h2 = h2 - j;
            int rem_b2 = b2 - j;

            int d1 = min(rem_h1, rem_b2);
            int d2 = min(rem_h2, rem_b1);
            int diff_used = d1 + d2;
            int diff_sold = min(diff_used, y);

            int total = same + diff_sold;
            if (total > max_total) {
                max_total = total;
            }
        }
    }

    cout << max_total << endl;
}