// K번째 수

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i=0; i<commands.size(); i++) {
        vector<int> sol(array.begin() + commands[i][0]-1, array.begin() + commands[i][1]);
        sort(sol.begin(), sol.end());
        answer.push_back(sol[commands[i][2] -1]);
    }
    return answer;
}

void print(vector<int> array, vector<vector<int>> commands, vector<int> answer) {
    vector<int> t = solution(array, commands);
    if (t == answer)
        cout << "Correct!" << endl;
    else
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print({1, 5, 2, 6, 3, 7, 4}, {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}}, {5, 6, 3});
    return 0;
}