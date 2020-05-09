// 주식가격

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int price;
    for (int i=0; i<prices.size(); i++) {
        price = 0;
        for (int j=i+1; j<prices.size(); j++) {
            if (prices[i] <= prices[j]) {
                price++;
            }
            else {
                price++;
                break;
            }
        }
        answer.push_back(price);
    }
    return answer;
}

void print(vector<int> prices, vector<int> answer) {
    vector<int> t = solution(prices);
    if (t == answer)
        cout << "Correct!" << endl;
    else
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print({1,2,3,2,3}, {4,3,1,1,0});
    return 0;
}