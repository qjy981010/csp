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
    unordered_set<int> backward;
    int flag=-1;
    int bflag=-1;
    Node(){}
};
vector<Node> graph;

void go(int root, int flag, int forward) {
    if (forward == 1) {
        if (graph[root].flag == flag) {
            return ;
        }
        else {
            graph[root].flag = flag;
            for (auto iter = graph[root].forward.begin(); iter != graph[root].forward.end(); ++iter) {
                go(*iter, flag, forward);
            }
        }
    }
    else {
        if (graph[root].bflag == flag) {
            return ;
        }
        else {
            graph[root].bflag = flag;
            for (auto iter = graph[root].backward.begin(); iter != graph[root].backward.end(); ++iter) {
                go(*iter, flag, forward);
            }
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
        graph[target-1].backward.insert(source-1);
    }
    int count, result=0;
    for (int i = 0; i != N; ++i) {
        go(i, i, 1);
        go(i, i, 0);
        count = 0;
        for (int j = 0; j != N; ++j) {
            if (graph[j].flag == i || graph[j].bflag == i) ++count;
        }
        if (count == N) ++result;
    }
    cout << result << endl;
    return 0;
}