// 디스크 컨트롤러

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    sort(jobs.begin(), jobs.end());
    int idx = 0;
    int time = 0;
    int n = jobs.size();
    while (idx < n || !pq.empty()) {
        while (idx < n && jobs[idx][0] <= time) {
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
        }

        if (!pq.empty()) {
            time += pq.top().first;
            answer += time - pq.top().second;
            pq.pop();
        } else {
            time = jobs[idx][0];
        }
    }
    answer /= jobs.size();
    return answer;
}

void print(vector<vector<int>> jobs, int answer) {
    int t = solution(jobs);
    if (t == answer)
        cout << "Correct!" << endl;
    else
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print({{0,3}, {1,9}, {2,6}}, 9);
    return 0;
}