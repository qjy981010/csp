#include <iostream>
#include <vector>
#include <set>

using namespace std;

long n;
long m;
vector<vector<vector<long>>> v;
vector<long> pre_narrow;
vector<long> dist;

int main() {
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        v.push_back(vector<vector<long>>());
    }
    long t, a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> t >> a >> b >> c;
        v[a].push_back(vector<long>({b, t, c}));
        v[b].push_back(vector<long>({b, t, c}));
    }
    return 0;
}