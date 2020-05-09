// 타겟 넘버

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> numbers, int target, int& answer, int sum=0, int count=0) {
    if (count == numbers.size()) {
        if (sum == target) {
            answer++;
        }
        return;
    }
    dfs(numbers, target, answer, sum + numbers[count], count + 1);
    dfs(numbers, target, answer, sum - numbers[count], count + 1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, answer, 0, 0);
    return answer;
}

void print(vector<int> numbers, int target, int answer) {
    int t = solution(numbers, target);
    if (t == answer)
        cout << "Correct!" << endl;
    else
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print({1,1,1,1,1}, 3, 5);
    return 0;
}