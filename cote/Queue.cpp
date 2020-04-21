// 다리를 지나는 트럭

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    for (int i=0; i<truck_weights.size(); i++) {
        q.push(truck_weights[i]);
    }
    
    int time = 1;
    int onBridge = 0;
    vector<pair<int,int>> onTruck;
    while (1) {
        if (!q.empty() && onBridge + q.front() <= weight) {
            onBridge += q.front();
            onTruck.push_back({q.front(), 0});
            q.pop();
        }
        for (int i=0; i<onTruck.size(); i++) {
            onTruck[i].second++;
        }
        time++;
        if (onTruck[0].second == bridge_length) {
            onBridge -= onTruck[0].first;
            onTruck.erase(onTruck.begin());
        }
        if (q.empty() && onTruck.empty()) {
            answer = time;
            break;
        }
    }
    return answer;
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