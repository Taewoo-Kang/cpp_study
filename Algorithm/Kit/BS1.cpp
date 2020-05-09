// 예산

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int max = 100000, min = 1, avg;
    while (min <= max) {
        bool check = true;
        long long sum = 0;
        avg = (max + min) / 2;
        for (int a: budgets) {
            if (a > avg) {
                sum += avg;
                check = false;
            } else {
                sum += a;
            }
        }
        if (sum > M) {
            max = avg - 1;
        } else {
            if (check) {
                return *max_element(budgets.begin(), budgets.end());
            }
            min = avg + 1;
            answer = avg;
        }
    }
    return answer;
}

void print(vector<int> budgets, int M, int answer) {
    int t = solution(budgets, M);
    if (t == answer)
        cout << "Correct!" << endl;
    else
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print({120, 110, 140, 150}, 485, 127);
    return 0;
}