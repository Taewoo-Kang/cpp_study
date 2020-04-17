// 기능개발
// https://programmers.co.kr/learn/courses/30/lessons/42586

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for (int i=0; i<progresses.size(); i++) {
        int dayCount = 0;
        while (progresses[i] < 100) {
            progresses[i] += speeds[i];
            dayCount++;
        }
        q.push(dayCount); // 각 작업이 작업이 며칠 걸리는지
    }

    int cnt = 1;
    int curr = q.front();
    q.pop();
    while (!q.empty()) {
        if (q.front() <= curr) {
            q.pop();
            cnt++;
        } else {
            answer.push_back(cnt);
            cnt = 1;
            curr = q.front();
            q.pop();
        }
    }
    answer.push_back(cnt);

    return answer;
}

void print(vector<int> progresses, vector<int> speeds, vector<int> answer) {
    vector<int> t = solution(progresses, speeds);
    if (t == answer)        
        cout << "Correct!" << endl;
    else        
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print({93,30,55}, {1,30,5}, {2,1});
    return 0;
}