#include<vector>
#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tmp;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0)
            cout << (v[i]+v[i+1])/2 << " ";
        else if (i == n-1)
            cout << (v[i-1]+v[i])/2 << " ";
        else
            cout << (v[i-1]+v[i]+v[i+1])/3 << " ";
    }
    cout << endl;
    return 0;
}