#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int i = s.length() - 1;
    while (i >= 0 && s[i] == '0') {
        s[i] = '1';
        i--;
    }
    if (i >= 0) {
        s[i] = '0';
    }
    cout << s << endl;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}
