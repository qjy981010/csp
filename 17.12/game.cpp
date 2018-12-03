#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, count, num = 0, idx = 0;
    vector<int> v;
    cin >> n >> k;
    count = 0;
    for (int i = 0; i < n; ++i) {
        v.push_back(1);
    }
    num = 0;
    while (count != n-1) {
        if (v[idx] == 1) {
            ++num;
            if (num%10 == k || num%k == 0) {
                v[idx] = 0;
                ++count;
            }
        }
        idx = (idx + 1) % n;
    }
    for (int i = 0; i < n; ++i) {
        if (v[i] == 1) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}