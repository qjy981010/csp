#include<vector>
#include<iostream>

using namespace std;

int n;
vector<int> v, result;

bool process(int k) {
    if (k > 1 && k < n) {
        result[k] = v[k-1]*3 - result[k-1] - result[k-2];
        if (result[k] < 1) result[k] = 1;
        while (true) {
            if ((result[k] + result[k-1] + result[k-2])/3 > v[k-1]) return false;

            if (process(k+1)) return true;
            else ++result[k];
        }
        return true;
    }
    else if (k == 0) {
        result[k] = 1;
        while (!process(k+1)) {
            ++result[k];
        }
        return true;
    }
    else if (k == 1) {
        result[k] = v[k-1]*2 - result[k-1];
        if (result[k] < 1) result[k] = 1;
        while (true) {
            if ((result[k] + result[k-1])/2 > v[k-1]) return false;

            if (process(k+1)) return true;
            else ++result[k];
        }
        return true;
    }
    else {
        if ((result[k-2] + result[k-1])/2 == v[k-1]) return true;
        else return false;
    }
}

int main() {
    cin >> n;
    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        v.push_back(tmp);
        result.push_back(0);
    }
    if (n == 1) {
        cout << v[0] << endl;
        return 0;
    }
    process(0);
    for (int i = 0; i < n; ++i) {
        cout << result[i];
        if (i < n-1) cout << " ";
    }
    cout << endl;
    return 0;
}