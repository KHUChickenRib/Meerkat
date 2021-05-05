#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<int> v = food_times; // 정렬된 food_times

    long long time = 0;         // 시간 저장
    int index = 0;
    int pre = 0;                // 이전 인덱스 value 저장
    int size = v.size();
    int i;

    long long remain, cnt;      // remain: k가 초과할 경우 나머지, cnt: remain과 비교 변수

    sort(v.begin(), v.end());   // 정렬

    // v[index+1]-v[index] * size만큼 시간을 더함 [문제 해설 참조]
    while (1) {
        if (index == v.size())
            return -1;
        time += (long long)(v[index] - pre) * (long long)size;

        // 시간이 넘어가는 경우 (나머지 계산 후 반복문 종료)
        if (time > k) {
            time -= (long long)(v[index] - pre) * (long long)size;
            remain = (k - time) % (long long)size;
            break;
        }

        pre = v[index];
        size--;
        index++;
    }

    // 계산한 나머지와 cnt를 비교하여 찾기
    cnt = 0;
    for (i = 0; i < food_times.size(); i++) {
        if (food_times[i] >= v[index]) {
            if (remain == cnt)
                break;
            else
                cnt++;
        }
    }
    answer = i + 1;

    return answer;
}