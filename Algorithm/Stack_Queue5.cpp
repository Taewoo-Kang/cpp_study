// 쇠막대기

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<int> st;
    for (int i=0; i<arrangement.size(); i++) {
        if (arrangement[i] == '(') {
            st.push(1);
        } else {
            st.pop();
            if (arrangement[i-1] == '(') {
                answer += st.size();
            } else {
                answer++;
            }
        }
    }
    return answer;
}

void print(string arrangement, int answer) {
    int t = solution(arrangement);
    if (t == answer)        
        cout << "Correct!" << endl;
    else        
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print("()(((()())(())()))(())", 17);
    return 0;
}