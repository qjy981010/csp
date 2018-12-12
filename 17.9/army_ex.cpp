#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

int N, M;
int result;

struct Node {
    unordered_set<int> forward;
    int flag=-1;
    Node(){}
};
vector<Node> graph;
int v[1005][1005] = {{0}};

void go(int root, int flag) {
    if (graph[root].flag == flag) {
        return ;
    }
    else {
        graph[root].flag = flag;
        v[root][flag] = 1;
        v[flag][root] = 1;
        for (auto iter = graph[root].forward.begin(); iter != graph[root].forward.end(); ++iter) {
            go(*iter, flag);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i != N; ++i) {
        graph.push_back(Node());
    }
    int source, target;
    for (int i = 0; i != M; ++i) {
        cin >> source >> target;
        graph[source-1].forward.insert(target-1);
    }
    int j, result=0;
    for (int i = 0; i != N; ++i) {
        go(i, i);
    }
    for (int i = 0; i != N; ++i) {
        for (j = 0; j != N; ++j) {
            if (v[i][j] != 1) break;
        }
        if (j == N) ++result;
    }
    cout << result << endl;
    return 0;
}