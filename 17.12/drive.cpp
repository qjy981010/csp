#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Path {
    int target;
    int islane;
    int length;
    Path(int ab, int t, int c): target(ab), islane(t), length(c){}
};

struct Point {
    int flag = 0;
    int pre_lane = 0;
    int dist = 1000000;
};

int n;
int m;
vector<Path> v[500];
Point points[500];

void dj() {
    int source = 0;
    while (1) {
        int i;
        points[source].flag = 1;
        for (i = 0; i < v[source].size(); ++i) {
            if (points[v[source][i].target].flag == 1) continue;
            if (v[source][i].islane == 1) {
                int new_dist = points[source].dist + pow(v[source][i].length + points[source].pre_lane, 2) - pow(points[source].pre_lane, 2);
                if (new_dist < points[v[source][i].target].dist) {
                    points[v[source][i].target].dist = new_dist;
                    points[v[source][i].target].pre_lane = v[source][i].length + points[source].pre_lane;
                }
            }
            else {
                int new_dist = points[source].dist + v[source][i].length;
                if (new_dist <= points[v[source][i].target].dist) {
                    points[v[source][i].target].dist = new_dist;
                    points[v[source][i].target].pre_lane = 0;
                }
            }
        }
        source = 0;
        int min_dist = 1000001;
        for (i = 0; i < n; ++i) {
            if (points[i].flag == 1) continue;
            else if (min_dist > points[i].dist) {
                source = i;
                min_dist = points[i].dist;
            }
        }
        if (source == 0) break;
    }
}

int main() {
    cin >> n >> m;
    int t, a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> t >> a >> b >> c;
        v[a-1].push_back(Path(b-1, t, c));
        v[b-1].push_back(Path(a-1, t, c));
    }
    points[0].dist = 0;
    dj();
    cout << points[n-1].dist << endl;
    return 0;
}