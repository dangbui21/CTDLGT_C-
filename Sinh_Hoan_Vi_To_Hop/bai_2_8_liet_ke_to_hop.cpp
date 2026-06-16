#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, k;
vector<int> x; // Mảng lưu các phần tử khác nhau sau khi đã sắp xếp
vector<int> c; // Mảng lưu tổ hợp hiện tại

void print() {
    for (int i = 1; i <= k; i++) {
        cout << x[c[i] - 1] << " ";
    }
    cout << endl;
}

void Try(int i) {
    for (int j = c[i - 1] + 1; j <= x.size() - k + i; j++) {
        c[i] = j;
        if (i == k) {
            print();
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    if (cin >> n >> k) {
        set<int> s;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            s.insert(val);
        }
        for (int val : s) {
            x.push_back(val);
        }
        c.resize(k + 1, 0);
        Try(1);
    }
    return 0;
}
