#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1001;

vector<int> graph[MAX];
bool visited[MAX];
int n, m, v;

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";

        for (int i=0; i<graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y]) {
                visited[y] = true;
                q.push(y);
            }
        }
    }
}

int main(void) {
    cin >> n >> m >> v;
    for (int i=0; i<m; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        graph[num1].push_back(num2);
        graph[num2].push_back(num1);
    }

    for (int i=1; i<=n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(v);
    cout << endl;

    return 0;
}