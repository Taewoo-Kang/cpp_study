// 네트워크

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(int n, vector<vector<int>> computers, int v, vector<bool>& visit) {
    visit[v] = true;
    for (int i=0; i<n; i++) {
        if (!visit[i] && computers[v][i]) {
            dfs(n, computers, i, visit);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visit(n, false);

    for (int i=0; i<n; i++) {
        if (!visit[i]) {
            answer++;
            dfs(n, computers, i, visit);
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