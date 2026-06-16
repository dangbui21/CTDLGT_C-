#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& a, int x) {
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == x) return 1;
        if (a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << binarySearch(a, x) << endl;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}
