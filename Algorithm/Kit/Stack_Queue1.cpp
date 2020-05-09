// 탑

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> st;
    bool check = true;
    for (int i=heights.size(); i>=0; i--) {
        for (int j=i-1; j>=0; j--) {
            if (heights.at(j) > heights.at(i)) {
                st.push(i+1); // 탑 번호는 1부터 시작함
                check = false;
                break;
            }
        }
        if (check) {
            st.push(0); // 더 큰 탑이 없으면 0
        }
    }
    
    while (!st.empty()) {
        answer.push_back(st.top());
        st.pop();
    }
    return answer;
}

void print(vector<int> heights, vector<int> answer) {
    vector<int> t = solution(heights);
    if (t == answer)        
        cout << "Correct!" << endl;
    else        
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print({1,5,3,6,7,6,5}, {0,0,2,0,0,5,6});
    return 0;
}
