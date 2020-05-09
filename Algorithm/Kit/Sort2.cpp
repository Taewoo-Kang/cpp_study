// 가장 큰 수

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    for (int num : numbers) {
        temp.push_back(to_string(num));
    }
    sort(temp.begin(), temp.end(), cmp);
    if (temp[0] == "0") 
        return "0";
    for (string t : temp) {
        answer += t;
    }

    return answer;
}

void print(vector<int> numbers, string answer) {
    string t = solution(numbers);
    if (t == answer)
        cout << "Correct!" << endl;
    else
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print({3,30,34,5,9}, "9534330");
    return 0;
}