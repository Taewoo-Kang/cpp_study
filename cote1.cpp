#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[2] > b[2];
}

int solution(vector<vector<int>> part_times) {
    int answer = 0;
    sort(part_times.begin(), part_times.end());
    int max_day = part_times.back()[1];
    sort(part_times.begin(), part_times.end(), cmp);
    int prev_day = 0;
    for (int day=1; day<=max_day; day++) {
        for (int idx=0; idx<part_times.size(); idx++) {
            if (prev_day <= part_times[idx][0]){// && part_times[idx][0] <= day) {
                answer += part_times[idx][2];
                prev_day = part_times[idx][1];
                day = part_times[idx][1];
                part_times.erase(part_times.begin()+idx);
                break;
            }
        }        
    }
    return answer;
}

void print(vector<vector<int>> part_times, int answer) {
    int t = solution(part_times);
    if (t == answer)
        cout << "Correct" << endl;
    else
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print({{3,6,3},{2,4,2},{10,12,8},{11,15,5},{1,8,10},{12,13,1}}, 19);
    //print({{1,2,1},{1,2,2},{2,3,1},{3,4,1},{1,4,2}}, 4);
    return 0;
}