// 완주하지 못한 선수

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> hashTable;
    for (string p_person : participant) {
        if (hashTable.find(p_person) == hashTable.end()) // 없을때
            hashTable.insert(make_pair(p_person, 1));
        else
            hashTable[p_person]++;        
    }
    
    for (string c_person : completion) {
        hashTable[c_person]--;
    }

    for (auto hash : hashTable) {
        if (hash.second > 0) {
            answer = hash.first;
            break;
        }
    }

    return answer;
}

void print(vector<string> participant, vector<string> completion, string answer) {
    string t = solution(participant, completion);
    if (t == answer)        
        cout << "Correct!" << endl;
    else        
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}, "mislav");
    return 0;
}