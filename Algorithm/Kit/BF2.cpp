// 소수 찾기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

bool isPrime(int number) { // 에라토스테네스의 체
    if (number == 1)
        return false;
    if (number == 2)
        return true;
    int sqrtNum = sqrt(number);
    for (int i=2; i<=sqrtNum; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}

bool cmp(char a, char b) {
    return a > b;
}

int solution(string numbers) {
    int answer = 0;
    string temp = numbers;
    sort(temp.begin(), temp.end(), cmp);
    
    vector<bool> prime(stoi(temp) + 1);
    prime[0] = false;
    for (long long i=1; i<prime.size(); i++) {
        prime[i] = isPrime(i);
    }

    string s, sub;
    s = numbers;
    sort(s.begin(), s.end());
    set<int> primes; // 소수를 담을 집합 (중복x)
    int l = s.size();
    do {
        for (int i=1; i<=l; i++) {
            sub = s.substr(0,i);
            if (prime[stoi(sub)]) {
                primes.insert(stoi(sub));
            }
        }
    } while (next_permutation(s.begin(), s.end())); // iterator 바꾸기

    answer = primes.size();
    return answer;
}

void print(string numbers, int answer) {
    int t = solution(numbers);
    if (t == answer)
        cout << "Correct!" << endl;
    else
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print("17", 3);
    return 0;
}