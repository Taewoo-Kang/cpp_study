// 단어 변환

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(string begin, string target, vector<string> words, vector<bool>& useCheck, int cnt=0) {
    for (int i=0; i<words.size(); i++) {
       // 풀이 추가 필요 
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> useCheck(words.size(), false);
    dfs(begin, target, words, useCheck);
    if (answer == 100)
        return 0;
    return answer;
}

void print(string begin, string target, vector<string> words, int answer) {
    int t = solution(begin, target, words);
    if (t == answer)
        cout << "Correct!" << endl;
    else
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}, 4);
    return 0;
}