#include <iostream>
#include <vector>

using namespace std;

// Hàm hoán vị
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Sắp xếp nổi bọt
void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Nếu không có phần tử nào được hoán đổi, mảng đã được sắp xếp
        if (!swapped)
            break;
    }
}

int main() {
    int n;
    // cout << "Nhap so luong phan tu: ";
    cin >> n;
    
    vector<int> arr(n);
    // cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    bubbleSort(arr);
    
    // cout << "Mang sau khi sap xep (Bubble Sort): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
