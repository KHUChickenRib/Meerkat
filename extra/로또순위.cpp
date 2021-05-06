#include <string>
#include <vector>

using namespace std;

int getrank(int num) {
    switch (num) {
    case 6:
        return 1;
    case 5:
        return 2;
    case 4:
        return 3;
    case 3:
        return 4;
    case 2:
        return 5;
    default:
        return 6;
    }
}


vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int i, j;
    int cnt1 = 0;
    int cnt2 = 0;

    for (i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0) {
            cnt2++;
            continue;
        }

        for (j = 0; j < win_nums.size(); j++) {
            if (lottos[i] == win_nums[j]) {
                cnt1++;
                break;
            }
        }
    }
    answer.push_back(getrank(cnt1 + cnt2));
    answer.push_back(getrank(cnt1));

    return answer;
}