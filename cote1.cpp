#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> part_times) {
    int answer = 0;
    sort(part_times.begin(), part_times.end());
    int max_day = part_times.back()[1];
    vector<int> d(max_day+1);
    for (int end=1; end<=max_day; end++) {
        for (int day=1; day<=end-1; day++) {
            for (int idx=0; idx<part_times.size(); idx++) {
                if (day <= part_times[idx][0] && part_times[idx][1] <= end) {
                    d[end] = d[end]>d[day]+part_times[idx][2] ? d[end] : d[day]+part_times[idx][2];
                }
            }
        }
    }
    answer = d[max_day];
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
    print({{1,2,1},{1,2,2},{2,3,1},{3,4,1},{1,4,2}}, 4);
    print({{1,2,8},{2,3,2},{3,4,1},{4,5,2},{5,6,10},{6,7,1},{7,8,2},{8,9,2},
        {9,10,6},{10,11,4},{11,12,1},{12,13,1},{13,14,1},{14,15,6},{15,16,10}}, 57);
    return 0;
}