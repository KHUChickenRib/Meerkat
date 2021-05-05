#include <string>
#include <vector>

using namespace std;

bool check(int mid, vector<int> stones, int k) {
    int i;
    int cnt = 0;
    int max_cnt = 0;

    for (i = 0; i < stones.size(); i++) {
        if (mid >= stones[i]) {
            while (i < stones.size() && mid >= stones[i]) {
                cnt++;
                i++;
            }
            if (max_cnt < cnt)
                max_cnt = cnt;
            cnt = 0;
        }
    }

    if (max_cnt >= k)
        return true;
    else
        return false;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int min = 200000001;
    int max = 0;
    int mid;
    int i;

    for (i = 0; i < stones.size(); i++) {
        if (min > stones[i])
            min = stones[i];
        if (max < stones[i])
            max = stones[i];
    }

    while (min <= max) {
        mid = (min + max) / 2;
        if (check(mid, stones, k))
            max = mid - 1;
        else
            min = mid + 1;
    }
    answer = min;

    return answer;
}