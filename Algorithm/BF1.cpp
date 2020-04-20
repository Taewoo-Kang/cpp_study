// 모의고사

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> supo{{1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5}};
    vector<int> count = {0,0,0};
    for (int i=0; i<answers.size(); i++) {
        if (answers[i] == supo[0][i % supo[0].size()])  count[0]++;
        if (answers[i] == supo[1][i % supo[1].size()])  count[1]++;
        if (answers[i] == supo[2][i % supo[2].size()])  count[2]++;
    }
    int max = *max_element(count.begin(), count.end());
    for (int i=0; i<3; i++) {
        if (max == count[i]) {
            answer.push_back(i+1);
        }
    }
    return answer;
}

void print(vector<int> answers, vector<int> answer) {
    vector<int> t = solution(answers);
    if (t == answer)
        cout << "Correct!" << endl;
    else
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print({1,3,2,4,2}, {1,2,3});
    return 0;
}