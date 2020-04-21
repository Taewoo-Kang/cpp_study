// 위장

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for (int i=0; i<clothes.size(); i++) {
        m[clothes[i][1]]++;
    }
    for (auto itr = m.begin(); itr != m.end(); itr++) {
        answer *= (itr->second) + 1;
    }
    return answer - 1;
}

void print(vector<vector<string>> clothes, int answer) {
    int t = solution(clothes);
    if (t == answer)
        cout << "Correct!" << endl;
    else
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print({{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}}, 5);
    return 0;
}