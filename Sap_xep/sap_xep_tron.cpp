#include <iostream>
#include <vector>

using namespace std;

// Hàm trộn hai phân đoạn đã sắp xếp arr[l..m] và arr[m+1..r]
void merge(vector<int> &arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Tạo các mảng tạm
    vector<int> L(n1), R(n2);

    // Sao chép dữ liệu sang các mảng tạm L[] và R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Trộn hai mảng tạm vào lại mảng arr[l..r]
    int i = 0; // Chỉ số ban đầu của mảng con thứ nhất
    int j = 0; // Chỉ số ban đầu của mảng con thứ hai
    int k = l; // Chỉ số ban đầu của mảng được trộn

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L[] nếu có
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R[] nếu có
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // In ra quá trình trộn để người dùng dễ theo dõi
    cout << "Tron doan [" << l << ".." << m << "] va [" << m + 1 << ".." << r << "]: ";
    for (int idx = 0; idx < arr.size(); idx++) {
        if (idx >= l && idx <= r) {
            cout << "[" << arr[idx] << "] "; // Đánh dấu đoạn vừa được trộn
        } else {
            cout << arr[idx] << " ";
        }
    }
    cout << endl;
}

// Hàm chia để trị Merge Sort
void mergeSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        // Tìm điểm chính giữa để chia đôi mảng
        int m = l + (r - l) / 2;

        // Đệ quy sắp xếp nửa thứ nhất và nửa thứ hai
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Trộn hai nửa đã sắp xếp
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Mang ban dau: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\nQua trinh sap xep:\n";
    
    mergeSort(arr, 0, n - 1);
    
    cout << "\nMang sau khi sap xep (Merge Sort): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
