#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<int> v = food_times; // ���ĵ� food_times

    long long time = 0;         // �ð� ����
    int index = 0;
    int pre = 0;                // ���� �ε��� value ����
    int size = v.size();
    int i;

    long long remain, cnt;      // remain: k�� �ʰ��� ��� ������, cnt: remain�� �� ����

    sort(v.begin(), v.end());   // ����

    // v[index+1]-v[index] * size��ŭ �ð��� ���� [���� �ؼ� ����]
    while (1) {
        if (index == v.size())
            return -1;
        time += (long long)(v[index] - pre) * (long long)size;

        // �ð��� �Ѿ�� ��� (������ ��� �� �ݺ��� ����)
        if (time > k) {
            time -= (long long)(v[index] - pre) * (long long)size;
            remain = (k - time) % (long long)size;
            break;
        }

        pre = v[index];
        size--;
        index++;
    }

    // ����� �������� cnt�� ���Ͽ� ã��
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