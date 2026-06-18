# BÀI GIẢNG: TÌM KIẾM, SẮP XẾP VÀ CÁC THUẬT TOÁN SINH

**Mục tiêu bài giảng:**
- Nắm vững bản chất cốt lõi của các thuật toán nền tảng.
- Hình thành tư duy giải quyết vấn đề (Problem-solving mindset).
- Áp dụng vào giải các bài tập thi đạt chuẩn 6+ điểm.

---

## 1. THUẬT TOÁN TÌM KIẾM (SEARCHING)

### 1.1. Lý thuyết cô đọng
*   **Tìm kiếm tuần tự (Sequential Search):** 
    *   *Bản chất:* Duyệt lần lượt từng phần tử từ đầu đến cuối mảng để kiểm tra.
    *   *Độ phức tạp:* $O(N)$. Dùng cho mảng dữ liệu chưa được sắp xếp.
*   **Tìm kiếm nhị phân (Binary Search):**
    *   *Bản chất:* Chia để trị. Liên tục chia đôi mảng tìm kiếm và so sánh với phần tử ở giữa (mid).
    *   *Độ phức tạp:* $O(\log N)$. **Bắt buộc mảng phải được sắp xếp từ trước.**

### 1.2. Tư duy giải bài
> [!TIP]
> *   Khi bài toán yêu cầu tìm kiếm trên một mảng kích thước lớn ($N > 10^5$) và mảng có tính thứ tự (tăng hoặc giảm dần), hãy nghĩ ngay đến **Tìm kiếm nhị phân**. 
> *   Từ khóa nhận diện: "Tìm kiếm", "mảng đã sắp xếp", "thời gian $O(\log N)$".
> *   Chìa khóa: Xác định đúng biến `left`, `right` và điều kiện thu hẹp không gian tìm kiếm (`left = mid + 1` hay `right = mid - 1`).

### 1.3. Trích giải bài tập: BÀI 7 - TÌM KIẾM (Chương 3)
**Đề bài:** Cho mảng $A[]$ gồm $n$ phần tử đã được sắp xếp. Hãy đưa ra `1` nếu $X$ có mặt trong mảng $A[]$, ngược lại đưa ra `-1`.

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        
        // Thuật toán Tìm kiếm nhị phân viết trực tiếp trong main
        int left = 0, right = n - 1;
        int ans = -1; // Mặc định là không tìm thấy
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == x) {
                ans = 1; // Đã tìm thấy
                break;
            }
            if (A[mid] < x) left = mid + 1;  // X nằm ở nửa phải
            else right = mid - 1;            // X nằm ở nửa trái
        }
        cout << ans << endl;
    }
    return 0;
}
```

---

## 2. THUẬT TOÁN SẮP XẾP (SORTING)

### 2.1. Lý thuyết cô đọng
*   **Nhóm thuật toán đơn giản ($O(N^2)$):** Sắp xếp đổi chỗ trực tiếp, Chọn (Selection), Chèn (Insertion), Nổi bọt (Bubble). Đặc điểm chung là dùng 2 vòng lặp lồng nhau. Thích hợp cho mảng nhỏ.
*   **Nhóm thuật toán nâng cao ($O(N \log N)$):** Quick Sort, Merge Sort. Dùng tư duy chia để trị, đệ quy. Thích hợp cho mảng lớn. Merge Sort ổn định (stable), Quick Sort nhanh trong thực tế nhưng trường hợp xấu nhất có thể rơi vào $O(N^2)$.

### 2.2. Tư duy giải bài
> [!TIP]
> *   Nếu đề bài chỉ đơn thuần yêu cầu sắp xếp để tìm kết quả nhanh chóng, hãy ưu tiên sử dụng thư viện sẵn có của C++ là hàm `std::sort()`. Nó được tối ưu cực kỳ tốt.
> *   Nếu đề bài yêu cầu **"in ra các bước thực hiện"** (như Bài 1.1, 1.2), bạn bắt buộc phải code thủ công theo đúng mô tả thuật toán (ví dụ: Selection Sort phải ghi nhận index nhỏ nhất rồi mới đổi chỗ).

### 2.3. Trích giải bài tập: BÀI 6 - QUICK SORT (Chương 3)
**Đề bài:** Sắp xếp mảng $A[]$ bằng thuật toán Quick Sort. 

```cpp
#include <iostream>
#include <vector>

using namespace std;

// Khai báo mảng toàn cục để tránh việc truyền mảng qua hàm gây khó hiểu
int A[100005]; 

// Quick Sort bắt buộc dùng đệ quy nên ta tách ra một hàm riêng nhưng không dùng tham chiếu
void quickSort(int low, int high) {
    if (low >= high) return;
    
    // Gộp bước phân hoạch (Partition) vào luôn trong hàm này
    int pivot = A[high]; // Chọn chốt là phần tử cuối
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]); // Đưa các phần tử nhỏ hơn chốt về bên trái
        }
    }
    swap(A[i + 1], A[high]);
    int pi = i + 1; // Vị trí chốt sau khi phân hoạch
    
    quickSort(low, pi - 1);  // Trị nửa trái
    quickSort(pi + 1, high); // Trị nửa phải
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> A[i];
        
        quickSort(0, n - 1); // Gọi đệ quy
        
        for (int i = 0; i < n; i++) cout << A[i] << " ";
        cout << endl;
    }
    return 0;
}
```

---

## 3. THUẬT TOÁN SINH (GENERATIVE ALGORITHM)

### 3.1. Lý thuyết cô đọng
Thuật toán sinh dùng để giải các bài toán liệt kê (tổ hợp, chỉnh hợp, hoán vị, nhị phân).
*   **Hai điều kiện cốt lõi:**
    1.  Xác định được thứ tự trên tập các cấu hình (biết cấu hình đầu và cuối).
    2.  Có quy tắc để sinh ra cấu hình kế tiếp từ cấu hình hiện tại.
*   **Mô hình lặp:**
    1.  Khởi tạo cấu hình đầu.
    2.  `while(chưa phải cấu hình cuối)` -> `In ra` -> `Sinh cấu hình tiếp theo`.

### 3.2. Tư duy giải bài
> [!IMPORTANT]
> **Quy tắc sinh kế tiếp chung:** Duyệt từ **phải sang trái** tìm phần tử đầu tiên *chưa đạt max*. Tăng phần tử đó lên mức tiếp theo, sau đó điều chỉnh phần còn lại ở phía sau về mức *nhỏ nhất* có thể.
> *   *Nhị phân:* Tìm bit `0` đầu tiên từ phải sang trái. Đổi thành `1`, các bit sau đổi thành `0`. Cấu hình cuối là toàn bit `1`.
> *   *Hoán vị:* Tìm phần tử $A[i] < A[i+1]$ từ phải sang. Tìm phần tử nhỏ nhất lớn hơn $A[i]$ ở phía sau để đổi chỗ. Lật ngược đoạn phía sau. Cấu hình cuối là mảng giảm dần. (Trong C++ có hàm `next_permutation` giải quyết triệt để vấn đề này).

### 3.3. Trích giải bài tập: LIỆT KÊ XÂU NHỊ PHÂN
**Đề bài:** Liệt kê các xâu nhị phân có độ dài N.

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Nhap N: "; cin >> n;
    
    vector<int> A(n, 0); // Khởi tạo cấu hình đầu tiên: toàn số 0
    bool OK = true;
    
    while (OK) {
        // In cấu hình hiện tại trực tiếp trong main
        for (int i = 0; i < n; i++) cout << A[i]; 
        cout << endl;
        
        // Sinh cấu hình kế tiếp
        int i = n - 1;
        while (i >= 0 && A[i] == 1) { // Duyệt từ phải qua trái, tìm số 0 đầu tiên
            A[i] = 0; // Chuyển các số 1 thành 0
            i--;
        }
        if (i >= 0) A[i] = 1; // Đổi số 0 tìm được thành 1
        else OK = false;      // Nếu i < 0 nghĩa là đã đến cấu hình cuối (toàn 1)
    }
    return 0;
}
```

### 3.4. Trích giải bài tập: BÀI 3 - HOÁN VỊ KẾ TIẾP (Chương 2)
**Đề bài:** Cho số tự nhiên N và một hoán vị X[]. Hãy đưa ra hoán vị tiếp theo.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        // Sử dụng sức mạnh của thư viện chuẩn C++ cho thao tác sinh hoán vị kế tiếp
        if (next_permutation(a.begin(), a.end())) {
            for (int i = 0; i < n; i++) cout << a[i] << " ";
            cout << endl;
        } else {
            // Nếu hoán vị đã là cuối cùng (ví dụ: 5 4 3 2 1), in ra hoán vị đầu tiên
            for (int i = 1; i <= n; i++) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
```
