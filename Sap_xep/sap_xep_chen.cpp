#include <iostream>
#include <vector>

using namespace std;

// Sắp xếp chèn
void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Di chuyển các phần tử lớn hơn key về sau 1 vị trí
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    
    insertionSort(arr);
    
    // cout << "Mang sau khi sap xep (Insertion Sort): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
