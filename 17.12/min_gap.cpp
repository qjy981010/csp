#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, tmp, min_gap, gap;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    min_gap = v[1] - v[0];
    for (int i = 2; i < n; ++i) {
        gap = v[i]-v[i-1];
        min_gap = min_gap > gap ? gap : min_gap;
    }
    cout << min_gap << endl;
    return 0;
}