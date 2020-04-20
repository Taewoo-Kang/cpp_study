// 더 맵게

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    while (pq.size()>1 && pq.top()<K) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + second * 2);
        answer++;
    }
    if (pq.top() < K) {
        return -1;
    }
    return answer;
}

void print(vector<int> scoville, int K, int answer) {
    int t = solution(scoville, K);
    if (t == answer)        
        cout << "Correct!" << endl;
    else        
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print({1,2,3,9,10,12}, 7, 2);
    return 0;
}