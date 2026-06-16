# Hướng Dẫn Cấu Hình Và Chạy C++ Qua WSL

Tài liệu này hướng dẫn cách cài đặt extension và cấu hình settings trên VS Code / Antigravity IDE để bạn có thể biên dịch và chạy file C++ thông qua môi trường **WSL (Ubuntu)** chỉ bằng một click chuột (nút Play), giúp bỏ qua lỗi bảo mật chặn file `.exe` của hệ thống.

---

## 🛠️ Hướng dẫn thiết lập (Cài đặt & Cấu hình)

### Bước 1: Cài đặt Extension Code Runner
1. Nhấn tổ hợp phím **`Ctrl + Shift + X`** (hoặc click vào biểu tượng 4 ô vuông ở thanh công cụ bên trái) để mở kho ứng dụng Extensions.
2. Nhập vào thanh tìm kiếm từ khóa: `Code Runner` (của tác giả Jun Han).
3. Nhấp chọn nút **`Install`** để cài đặt.

---

### Bước 2: Cấu hình Settings của IDE để chạy qua WSL
Để nút Play tự động gọi trình biên dịch của WSL Linux thay vì Windows, bạn cần chỉnh sửa file cài đặt `settings.json`:

1. Nhấn tổ hợp phím **`Ctrl + Shift + P`** để mở thanh lệnh (Command Palette).
2. Gõ lệnh: `Preferences: Open User Settings (JSON)` và nhấn **Enter**.
3. Thêm cấu hình sau vào trong cặp dấu ngoặc nhọn `{ ... }` của file (phân tách với các dòng trước đó bằng dấu phẩy `,`):

```json
  "code-runner.executorMap": {
    "cpp": "wsl g++ -O2 $fileName -o $fileNameWithoutExt && wsl ./$fileNameWithoutExt"
  },
  "code-runner.runInTerminal": true
```

4. Nhấn **`Ctrl + S`** để lưu lại file cài đặt.

---

## 🚀 Cách chạy chương trình

Sau khi cài đặt xong, bạn có thể chạy bất kỳ file C++ nào (`.cpp`) theo các bước sau:

1. Mở file mã nguồn C++ (Ví dụ: `sap_xep_mang.cpp`).
2. Nhấp vào nút **`Play`** (biểu tượng hình tam giác ở góc trên bên phải màn hình) hoặc bấm tổ hợp phím tắt **`Ctrl + Alt + N`**.
3. **Nhập dữ liệu:** Click chuột vào khung Terminal xuất hiện ở phía dưới màn hình và nhập dữ liệu bình thường.

### Ví dụ nhập/xuất:
* **Nhập (Input):**
  ```text
  5
  144 23 656 -34 8
  ```
* **Kết quả (Output):**
  ```text
  -34 8 23 144 656
  ```

---

## 📂 Danh sách các file trong thư mục
* **`sap_xep_mang.cpp`**: Sắp xếp mảng sử dụng thư viện tối ưu `std::sort` ($O(N \log N)$).
* **`sap_xep_chon.cpp`**: Sắp xếp mảng sử dụng giải thuật Sắp xếp chọn thủ công ($O(N^2)$).
* **`sap_xep_noi_bot.cpp`**: Sắp xếp mảng sử dụng giải thuật Sắp xếp nổi bọt - Bubble Sort ($O(N^2)$).
* **`sap_xep_chen.cpp`**: Sắp xếp mảng sử dụng giải thuật Sắp xếp chèn - Insertion Sort ($O(N^2)$).
* **`sap_xep_nhanh.cpp`**: Sắp xếp mảng sử dụng giải thuật Sắp xếp nhanh - Quick Sort ($O(N \log N)$).
* **`tim_kiem_nhi_phan.cpp`**: Tìm kiếm nhị phân (Binary Search) trên mảng đã sắp xếp ($O(\log N)$).
* **`dem_phan_tu.cpp`**: Tìm kiếm số lần xuất hiện của số X trong mảng đã sắp xếp sử dụng Binary Search ($O(\log N)$).


