#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int total_sp, vector<vector<int>> skills, int v, vector<bool>& visited) {
    visited[v] = true;
    for (int i=0; i<skills.size(); i++) {
    }
}

vector<int> solution(int total_sp, vector<vector<int>> skills) {
    vector<int> answer;
    vector<bool> visited(skills.size(), false);

    dfs(total_sp, skills, 0, visited);
    
    return answer;
}

void print(int total_sp, vector<vector<int>> skills, vector<int> answer) {
    vector<int> t = solution(total_sp, skills);
    if (t == answer)
        cout << "Correct" << endl;
    else
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print(121, {{1,2},{1,3},{3,6},{3,4},{3,5}}, {44,11,33,11,11,11});
    return 0;
}