// 여행경로

#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> answerlist;

void dfs(vector<vector<string>> tickets, vector<pair<int,int>> useCheck, string from, int count) {

}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<pair<int,int>> useCheck(tickets.size(), {0,-1});
    
    return answer;
}

void print(vector<vector<string>> tickets, vector<string> answer) {
    vector<string> t = solution(tickets);
    if (t == answer)
        cout << "Correct" << endl;
    else
        cout << "Wrong Answer" << endl;
    answerlist.clear();
}
 
int main() {
    print({ {"ICN","JFK"}, {"HND", "IAD"}, {"JFK", "HND"} }, { "ICN", "JFK", "HND", "IAD" });
    //print({ {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"} }, { "ICN", "ATL", "ICN", "SFO", "ATL", "SFO" });
    return 0;
}