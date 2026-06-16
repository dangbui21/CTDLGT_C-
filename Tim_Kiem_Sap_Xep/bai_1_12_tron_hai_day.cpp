#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    vector<long long> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c.push_back(a[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        c.push_back(b[i]);
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
