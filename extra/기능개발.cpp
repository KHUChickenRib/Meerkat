#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    int day, cnt;
    int i;

    for (i = 0; i < progresses.size(); i++) {
        day = (100 - progresses[i]) / speeds[i];

        if ((100 - progresses[i]) % speeds[i] != 0)
            day++;
        days.push_back(day);
    }

    cnt = 1;
    for (i = 0; i < days.size() - 1; i++) {
        if (days[i] < days[i + 1]) {
            answer.push_back(cnt);
            cnt = 1;
        }
        else if (days[i] == days[i + 1])
            cnt++;
        else {
            days[i + 1] = days[i];
            cnt++;
        }
    }
    answer.push_back(cnt);

    return answer;
}