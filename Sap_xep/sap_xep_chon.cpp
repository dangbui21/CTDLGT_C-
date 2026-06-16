#include <iostream>
#include <vector>

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

        // Thuật toán sắp xếp chọn (Selection Sort) - Độ phức tạp O(N^2)
        for (int i = 0; i < n - 1; ++i) {
            int min_idx = i;
            for (int j = i + 1; j < n; ++j) {
                if (a[j] < a[min_idx]) {
                    min_idx = j;
                }
            }
            // Đổi chỗ phần tử nhỏ nhất tìm được với phần tử hiện tại
            swap(a[i], a[min_idx]);
        }

        // In ra mảng đã sắp xếp
        for (int i = 0; i < n; ++i) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
