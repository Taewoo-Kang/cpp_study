// 다리를 지나는 트럭

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    for (int i=0; i<truck_weights.size(); i++) {
        q.push(truck_weights[i]);
    }
    int t = 1;
    int sum = 0;
    vector<pair<int, int>> cand;
    while(1) {
        if(!q.empty() && sum + q.front() <= weight) {
            cand.push_back({q.front(), 0});
            sum += q.front();
            q.pop();
        }

        for (int i=0; i<cand.size(); i++) {
            cand[i].second++;
        }
        t++;

        if (cand[0].second == bridge_length) {
            sum -= cand[0].first;
            cand.erase(cand.begin());
        }
        if (q.empty() && cand.empty()) {
            break;
        }
    }
    return t;
}

void print(int bridge_length, int weight, vector<int> truck_weights, int answer) {
    int t = solution(bridge_length, weight, truck_weights);
    if (t == answer)        
        cout << "Correct!" << endl;
    else        
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print(2, 10, {7,4,5,6}, 8);
    return 0;
}
