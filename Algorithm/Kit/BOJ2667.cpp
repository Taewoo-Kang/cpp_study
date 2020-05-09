// 백준 2667번 문제: 단지번호붙이기
// 출처: twpower.github.io/151-bfs-dfs-basic-problem

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 25;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int group_id;
int groups[MAX_SIZE * MAX_SIZE];

int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

// DFS-recursion
void dfs_recursion(int x, int y) {
    visited[x][y] = true;
    groups[group_id]++;

    // 해당 위치 주변을 확인
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (0 <= nx && nx < n && 0 <= ny && ny <n) {
            if (map[nx][ny] == 1 && visited[nx][ny] == false) {
                dfs_recursion(nx, ny);
            }
        }
    }
}

// DFS-stack
void dfs_stack(int x, int y) {
    stack<pair<int, int>> s;
    s.push(make_pair(x, y));

    visited[x][y] = true;
    groups[group_id]++;

    while (!s.empty()) {
        x = s.top().first;
        y = s.top().second;
        s.pop();

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ( 0<= nx && nx < n && 0 <= ny && ny < n) {
                if (map[nx][ny] ==1 && visited[nx][ny] == false) {
                    visited[nx][ny] == true;
                    groups[group_id]++;

                    s.push(make_pair(x,y)); // push하는 경우이기 때문에 현재 위치도 넣어준다
                    s.push(make_pair(nx, ny));
                }
            }
        }
    }
}

// BFS
void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));

    visited[x][y] = true;
    groups[group_id]++;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (map[nx][ny] == 1 && visited[nx][ny] == false) {
                    visited[nx][ny] = true;
                    groups[group_id]++;
                    
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int num; 
            cin >> num;
            map[i][j] = num;
        }
    }

}