#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1001;

vector<int> graph[MAX];
bool visited[MAX];
int n, m, v;

void dfs(int v) {
    cout << v << " ";
    visited[v] = true;

    for (int i=0; i<graph[v].size(); i++) {
        int x = graph[v][i];
        if (!visited[x]) {
            dfs(x);
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

    dfs(v);
    cout << endl;

    return 0;
}