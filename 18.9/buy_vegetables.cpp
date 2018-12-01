#include<vector>
#include<iostream>
#include <utility>

using namespace std;

int main() {
    int n;
    int tmp1, tmp2;
    cin >> n;
    vector<pair<int,int>> w;
    vector<pair<int,int>> h;
    for (int i = 0; i < n; ++i) {
        cin >> tmp1 >> tmp2;
        h.push_back(pair<int,int>(tmp1, tmp2));
    }
    for (int i = 0; i < n; ++i) {
        cin >> tmp1 >> tmp2;
        w.push_back(pair<int,int>(tmp1, tmp2));
    }

    int i=0, j=0, result=0;
    while (i<n && j<n) {
        if (h[i].first > w[j].first) {
            if (h[i].first >= w[j].second) ++j;
            else if (h[i].second > w[j].second) {result+=(w[j].second-h[i].first); ++j;}
            else if (h[i].second < w[j].second) {result+=(h[i].second-h[i].first); ++i;}
            else {result+=(h[i].second-h[i].first); ++i; ++j;}
        } else {
            if (w[j].first >= h[i].second) ++i;
            else if (w[j].second > h[i].second) {result+=(h[i].second-w[j].first); ++i;}
            else if (w[j].second < h[i].second) {result+=(w[j].second-w[j].first); ++j;}
            else {result+=(w[j].second-w[j].first); ++i; ++j;}
        }
    }
    cout << result << endl;
    return 0;
}