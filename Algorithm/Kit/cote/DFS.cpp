// 네트워크

#include <iostream>
#include <vector>

using namespace std;

void dfs(int n, vector<vector<int>> computers, int v, vector<bool>& visited) {
    visited[v] = true;
    for (int i=0; i<n; i++) {
        if (!visited[i] && computers[v][i] == 1) {
            dfs(n, computers, i, visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            answer++;
            dfs(n, computers, i, visited);
        }
    }
    return answer;
}

void print(int n, vector<vector<int>> computers, int answer) {
    int t = solution(n, computers);
    if (t == answer)
        cout << "Correct!" << endl;
    else
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print(3, {{1,1,0},{1,1,0},{0,0,1}}, 2);
    return 0;
}