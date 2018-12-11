#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> keys;
vector<bool> is_here;
vector<vector<int>> timetable;

bool time_compare(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) {
        if (a[2] == b[2]) {
            return a[1] < b[1];
        }
        else {
            return a[2] > b[2];
        }
    }
    else {
        return a[0] < b[0];
    }
}

int main() {
    cin >> N >> K;
    int w, s, c;
    for (int i = 0; i < N; ++i) {
        keys.push_back(i+1);
        is_here.push_back(true);
    }
    for (int i = 0; i < K; ++i) {
        cin >> w >> s >> c;
        timetable.push_back(vector<int>({s, w, 0}));
        timetable.push_back(vector<int>({s+c, w, 1}));
    }
    sort(timetable.begin(), timetable.end(), time_compare);
    for (int i = 0; i < timetable.size(); ++i) {
        if (timetable[i][2] == 0) {
            for (int j = 0; j < N; ++j) {
                if (keys[j] == timetable[i][1]) {
                    is_here[j] = false;
                    keys[j] = 0;
                    break;
                }
            }
        }
        else {
            for (int j = 0; j < N; ++j) {
                if (is_here[j] == false) {
                    is_here[j] = true;
                    keys[j] = timetable[i][1];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << keys[i] << " ";
    }
    cout << endl;
    return 0;
}