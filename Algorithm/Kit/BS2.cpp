// 입국심사

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0, minTime = 1, maxTime, avgTime, human = 0;
    maxTime = *max_element(times.begin(), times.end()) * (long long)n;
    while (minTime <= maxTime) {
        avgTime = (maxTime + minTime) / 2;
        for (auto t : times) {
            human += avgTime / t;
        }
        if (n <= human) {
            answer = avgTime;
            maxTime = avgTime - 1;
        }
        else {
            minTime = avgTime + 1;
        }
        human = 0;
    }
    return answer;
}

void print(int n, vector<int> times, long long answer) {
    long long t = solution(n, times);
    if (t == answer)
        cout << "Correct!" << endl;
    else
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print(6, {7,10}, 28);
    return 0;
}