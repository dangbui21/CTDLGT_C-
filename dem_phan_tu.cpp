#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Tìm vị trí xuất hiện đầu tiên của X bằng tìm kiếm nhị phân
int findFirst(const vector<int>& a, int x) {
    int low = 0;
    int high = a.size() - 1;
    int res = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == x) {
            res = mid;
            high = mid - 1; // Thu hẹp phạm vi sang bên trái để tìm vị trí xuất hiện sớm hơn
        } else if (a[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

// Tìm vị trí xuất hiện cuối cùng của X bằng tìm kiếm nhị phân
int findLast(const vector<int>& a, int x) {
    int low = 0;
    int high = a.size() - 1;
    int res = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == x) {
            res = mid;
            low = mid + 1; // Thu hẹp phạm vi sang bên phải để tìm vị trí xuất hiện muộn hơn
        } else if (a[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

void solve() {
    int n, x;
    if (cin >> n >> x) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int firstIdx = findFirst(a, x);
        if (firstIdx == -1) {
            cout << -1 << "\n";
        } else {
            int lastIdx = findLast(a, x);
            cout << (lastIdx - firstIdx + 1) << "\n";
        }
    }
}

int main() {
    // Tối ưu hóa tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
