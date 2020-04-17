// 베스트앨범
// https://programmers.co.kr/learn/courses/30/lessons/42579

#include <iostream>
#include <string>
#include <vector>
#include <map> // map은 균형이진트리이므로 오름차순 정렬!
#include <set>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genres_cnt;
    vector<pair<string, int>> v; // sort를 위해 map 복사용

    for (int i=0; i<genres.size(); i++) { // 장르별 재생횟수 카운트
        genres_cnt[genres[i]] += plays[i];
    }
    
    map<string, int>::iterator iter = genres_cnt.begin();
    for (iter = genres_cnt.begin(); iter != genres_cnt.end(); ++iter) {
        v.push_back(make_pair(iter->first, iter->second));
    }

    sort(v.begin(), v.end(), cmp); // 재생횟수 기준으로 sort
    for (int i=0; i<v.size(); i++) { // 장르별 많이 재생된 두 곡 찾기
        int f=0; int s=0; int fn=0; int sn=0;
        for (int j=0; j<genres.size(); j++) {
            if (genres[j] == v[i].first) {
                if (plays[j] > f) {
                    s = f;
                    sn = fn;
                    f = plays[j];
                    fn = j;
                }
                else if (plays[j] > s) {
                    s = plays[j];
                    sn = j;
                }
            }
        }
        answer.push_back(fn);
        if (s>0) // 장르에 2개 이상의 곡이 있을 경우에만 앨범에 넣기
            answer.push_back(sn);
    }

    return answer;
} 

void print(vector<string> genres, vector<int> plays, vector<int> answer) {
    vector<int> t = solution(genres, plays);
    if (t == answer)        
        cout << "Correct!" << endl;
    else        
        cout << "Wrong Answer" << endl;
}
 
int main() {
    print({"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500}, {4, 1, 3, 0});
    return 0;
}