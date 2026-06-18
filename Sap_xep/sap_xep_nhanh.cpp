#include <iostream>
#include <vector>

using namespace std;

// Hàm hoán vị
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Phân hoạch mảng
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // Chọn phần tử cuối làm pivot
    int i = (low - 1); // Chỉ số của phần tử nhỏ hơn

    for (int j = low; j <= high - 1; j++) {
        // Nếu phần tử hiện tại nhỏ hơn pivot
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quick Sort
void quickSort(vector<int> &arr, int low, int high) { 
    if (low < high) {
        int pi = partition(arr, low, high);

        // In ra trạng thái mảng sau bước phân hoạch
        cout << "Pivot = " << arr[pi] << " (doan [" << low << ", " << high << "]): ";
        for (int i = 0; i < arr.size(); i++) {
            if (i == pi) {
                cout << "[" << arr[i] << "] "; // Đánh dấu phần tử chốt đã về đúng vị trí
            } else {
                cout << arr[i] << " ";
            }
        }
        cout << endl;

        // Đệ quy sắp xếp các mảng con
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
     cout << "Nhap so luong phan tu: ";
    cin >> n;
    
    vector<int> arr(n);
    // cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    quickSort(arr, 0, n - 1);
    
    // cout << "Mang sau khi sap xep (Quick Sort): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
