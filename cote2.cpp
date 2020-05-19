#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int total_sp, vector<vector<int>> skills) {
    vector<int> answer;
    int n = skills.size();
    vector<vector<int>> rel(n+2, vector<int>(n+2));
    vector<int> depth(n+2);
    vector<int> sort(n+2);
    vector<long> res(n+2);
    for (int i=1; i<=n+1; i++) {
        sort[i] = i;
        if (i == n+1)
            break;
        int p = skills[i-1][0];
        int q = skills[i-1][1];
        rel[p][q] = 1;
        depth[q] = depth[p] + 1;
    }
    for (int i=1; i<=n+1; i++) {
        for (int j=i; j<=n+1; j++) {
            if (depth[i] < depth[j]) {
                int temp = depth[i];
                depth[i] = depth[j];
                depth[j] = temp;
                int tempIdx = sort[i];
                sort[i] = sort[j];
                sort[j] = tempIdx;
            }
        }
    }

    int div = 0;
    for (int i=1; i<=n+1; i++) {
        int sum = 0;
        for (int j=1; j<=n+1; j++) {
            sum += rel[sort[i]][j] == 1 ? res[j] : 0;
        }
        res[sort[i]] = sum != 0 ? res[sort[i]]=sum : 1;
        div += res[sort[i]];
    }
    for (int i=1; i<=n+1; i++) {
        res[i] = res[i] * total_sp / div;
        answer.push_back(res[i]);
    }

    return answer;
}

void print(int total_sp, vector<vector<int>> skills, vector<int> answer) {
    vector<int> t = solution(total_sp, skills);
    if (t == answer)
        cout << "Correct" << endl;
    else
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print(121, {{1,2},{1,3},{3,6},{3,4},{3,5}}, {44,11,33,11,11,11});
    return 0;
}