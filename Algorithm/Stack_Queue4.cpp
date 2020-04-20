// 프린터

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;

    int size = priorities.size();
    for (int i=0; i<size; i++) {
        q.push(make_pair(i,priorities[i]));
        pq.push(priorities[i]);
    }

    while (!q.empty()) {
        int i = q.front().first;
        int p = q.front().second;
        q.pop();
        if (p == pq.top()) {
            pq.pop();
            answer +=1;
            if (i == location) {
                break;
            }
        } else {
            q.push(make_pair(i,p));
        }
    }
    return answer;
}

void print(vector<int> priorities, int location, int answer) {
    int t = solution(priorities, location);
    if (t == answer)        
        cout << "Correct!" << endl;
    else        
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print({2,1,3,2}, 2, 1);
    return 0;
}