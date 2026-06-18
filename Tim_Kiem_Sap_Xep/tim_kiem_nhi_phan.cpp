#include <iostream>
#include <vector>

using namespace std;

// Hàm tìm kiếm nhị phân (Binary Search) - Độ phức tạp O(log N)
int binarySearch(const vector<int>& a, int x) {
    int low = 0;
    int high = a.size() - 1;

    while (low <= high) {
        // Tính phần tử ở giữa (sử dụng biểu thức này để tránh tràn số khi low và high lớn)
        int mid = low + (high - low) / 2;

        if (a[mid] == x) {
            return 1; // Tìm thấy X
        } else if (a[mid] < x) {
            low = mid + 1; // X lớn hơn A[mid] -> tìm ở nửa bên phải
        } else {
            high = mid - 1; // X nhỏ hơn A[mid] -> tìm ở nửa bên trái
        }
    }
    return -1; // Không tìm thấy X trong mảng
}

int main() {
    // Tối ưu hóa tốc độ nhập xuất (Fast I/O)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    if (cin >> n >> x) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << binarySearch(a, x) << "\n";
    }

    return 0;
}
