#include <iostream>

using namespace std;

const int MAX_N = 100010;

int n;
long long buffer[MAX_N];
long long a[MAX_N];
long long invcount = 0; // Using long long to prevent overflow

void read_input()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

// Merge function that counts inversions
void merge(long long arr[], int xl, int xr, int yl, int yr, long long buffer[])
{
    if (xl > xr && yl > yr) {
        return;
    }

    int i = xl, j = yl, k = 0;

    while (i <= xr && j <= yr) {
        if (arr[i] <= arr[j]) {
            buffer[k++] = arr[i++];
        } else {
            buffer[k++] = arr[j++];
            invcount += (xr - i + 1); // Count inversions
        }
    }

    while (i <= xr) {
        buffer[k++] = arr[i++];
    }

    while (j <= yr) {
        buffer[k++] = arr[j++];
    }

    // Copy merged result back to original array
    for (int m = 0; m < k; m++) {
        arr[xl + m] = buffer[m];
    }
}

// Modified merge sort to count inversions
void split_and_merge(long long arr[], int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    split_and_merge(arr, l, mid);
    split_and_merge(arr, mid + 1, r);

    merge(arr, l, mid, mid + 1, r, buffer);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    read_input();

    split_and_merge(a, 0, n - 1);

    cout << invcount << "\n";

    return 0;
}
