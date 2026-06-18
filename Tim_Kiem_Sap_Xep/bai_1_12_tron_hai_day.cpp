#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    // Sử dụng kỹ thuật 2 con trỏ để trộn 2 dãy đã sắp xếp với độ phức tạp O(n + m)
    vector<long long> c;
    c.reserve(n + m);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            c.push_back(a[i]);
            i++;
        } else {
            c.push_back(b[j]);
            j++;
        }
    }
    // Đưa các phần tử còn dư của dãy a (nếu có) vào c
    while (i < n) {
        c.push_back(a[i]);
        i++;
    }
    // Đưa các phần tử còn dư của dãy b (nếu có) vào c
    while (j < m) {
        c.push_back(b[j]);
        j++;
    }

    // In kết quả
    for (int k = 0; k < c.size(); k++) {
        cout << c[k] << " ";
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
