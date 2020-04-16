#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int MAX = 1001;

vector<int> graph[MAX];
bool visited[MAX];
int n, m, v;

/* // 재귀함수로 구현
void dfs(int v) {
    cout << "Visit:" << v << " ";
    visited[v] = true;

    for (int i=0; i<graph[v].size(); i++) {
        int x = graph[v][i];
        if (!visited[x]) {
            dfs(x);
        }
    }
}
*/

// 스택으로 구현
stack<int> s;
void dfs(int v) {
    int x = v;
    s.push(x);
    visited[x] = true;
    cout << "Visit:" << v << " ";
    while (!s.empty()) {
        x = s.top();
        for (int i=0; i<graph[v].size(); i++) {
            if (!visited[i]) {
                x = i;
                s.push(x);
                visited[x] = true;
                cout << "Visit:" << x << " ";
                break;
            } else if (i == graph[v].size() -1) {
                // 연결된 정점이 없거나 정점 중 방문할 정점이 없는 경우
                s.pop();
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

    // 하나의 정점에서 다음을 탐색할 때 node값에 순차적으로 접근하기 위해 sort
    for (int i=1; i<=n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout << endl;

    return 0;
}