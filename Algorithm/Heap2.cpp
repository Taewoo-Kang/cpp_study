// 라면공장

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int> pq;
    int idx = 0;
    for (int day=0; day<k; day++) {
        if (dates.size()>idx && dates[idx] <= day) {
            pq.push(supplies[idx]);
            idx++;
        }
        if (!stock) {
            stock += pq.top();
            pq.pop();
            answer++;
        }
        stock--;
    }
    return answer;
}

void print(int stock, vector<int> dates, vector<int> supplies, int k, int answer) {
    int t = solution(stock, dates, supplies, k);
    if (t == answer)
        cout << "Correct!" << endl;
    else
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print(4, {4,10,15}, {20,5,10}, 30, 2);
    return 0;
}