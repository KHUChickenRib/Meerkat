#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int, double>& a, const pair<int, double>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int* count = new int[N + 1];    // 각 단계별 통과 인원
    double* rate = new double[N];   // 각 단계별 실패율
    multimap<int, double> m;
    int temp = stages.size();
    int i;

    // 변수 초기화
    for (i = 0; i < N + 1; i++)
        count[i] = 0;
    for (i = 0; i < N; i++)
        rate[i] = 0.0;

    // 통과인원 계산
    for (i = 0; i < stages.size(); i++)
        count[stages[i] - 1]++;

    // 실패율 계산 (실패한 사람 / 남은 사람)
    for (i = 0; i < N; i++) {
        // 도달 유저 없는 경우
        if (temp == 0)
            rate[i] = 0.0;
        else {
            rate[i] = count[i] / (double)temp;
            temp -= count[i];
        }
    }

    // multimap에 매핑
    for (i = 0; i < N; i++)
        m.insert(pair<int, double>(i+1, rate[i]));

    // 정렬 (참고: key가 같으면 value의 오름차순으로 정렬)
    vector<pair<int, double>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);
    
    // 정렬된 키값을 answer에 push
    for (auto num : vec)
        answer.push_back(num.first);

    return answer;
}