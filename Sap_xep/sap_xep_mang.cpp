#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Tối ưu hóa tốc độ nhập/xuất trong C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Sắp xếp mảng theo thứ tự tăng dần
        sort(a.begin(), a.end());

        // In ra mảng đã sắp xếp
        for (int i = 0; i < n; ++i) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
