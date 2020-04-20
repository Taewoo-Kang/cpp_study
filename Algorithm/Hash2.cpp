// 전화번호 목록

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (int i=0; i<phone_book.size(); i++) {
        if (phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size())) {
            answer = false;
            break;
        }
    }
    return answer;
}

void print(vector<string> phone_book, bool answer) {
    bool t = solution(phone_book);
    if (t == answer)        
        cout << "Correct!" << endl;
    else        
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print({"119", "9761241", "1191251"}, false);
    return 0;
}