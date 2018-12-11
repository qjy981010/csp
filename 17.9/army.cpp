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
    Node(){}
};
vector<Node> graph;

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
    int count, size_before;
    while (true) {
        count = 0;
        for (int i = 0; i != N; ++i) {
            size_before = graph[i].forward.size() + graph[i].backward.size();
            for (auto iter = graph[i].forward.begin(); iter != graph[i].forward.end(); ++iter) {
                graph[i].forward.insert(graph[*iter].forward.begin(), graph[*iter].forward.end());
            }
            for (auto iter = graph[i].backward.begin(); iter != graph[i].backward.end(); ++iter) {
                graph[i].backward.insert(graph[*iter].backward.begin(), graph[*iter].backward.end());
            }
            count += graph[i].forward.size() + graph[i].backward.size() - size_before;
        }
        if (count == 0) break;
    }
    count = 0;
    for (int i = 0; i != N; ++i) {
        graph[i].forward.insert(graph[i].backward.begin(), graph[i].backward.end());
        graph[i].forward.insert(i);
        if (graph[i].forward.size() == N) ++count;
    }
    cout << count << endl;
    return 0;
}