#include <iostream>
#include <vector>

using namespace std;

int n, cnt;
vector<bool> col, d1, d2; // d1: đường chéo chính (i-j), d2: đường chéo phụ (i+j)

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (!col[j] && !d1[i - j + n] && !d2[i + j - 1]) {
            col[j] = d1[i - j + n] = d2[i + j - 1] = true;
            if (i == n) {
                cnt++;
            } else {
                Try(i + 1);
            }
            col[j] = d1[i - j + n] = d2[i + j - 1] = false;
        }
    }
}

void solve() {
    cin >> n;
    cnt = 0;
    col.assign(n + 1, false);
    d1.assign(2 * n + 1, false);
    d2.assign(2 * n + 1, false);
    Try(1);
    cout << cnt << endl;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}
