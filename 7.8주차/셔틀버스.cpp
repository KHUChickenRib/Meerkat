#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 승객들의 timetable을 변환 (분단위로 통일)
vector<int> convert(vector<string> timetable) {
    vector<int> timeTable;
    int i;

    for (i = 0; i < timetable.size(); i++) {
        int num = stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3,2));
        timeTable.push_back(num);
    }

    return timeTable;
}

// 버스 운행시간 계산 (분단위로 통일)
vector<int> getBusTime(int n, int t) {
    vector<int> busTime;
    int num = 540;

    for (int i = 0; i < n; i++)
        busTime.push_back(num + i * t);
    return busTime;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> convert_timetable;
    vector<int> bus_timetable;
    int boardTime;
    int max;
    int i, j;

    convert_timetable = convert(timetable);
    sort(convert_timetable.begin(), convert_timetable.end());       // 승객 탑승시간 정렬

    bus_timetable = getBusTime(n, t);

    // 버스 탑승시간을 돌면서 탈 시간을 정함
    for (i = 0; i < bus_timetable.size(); i++) {
        int cnt = 0;

        // 해당 시간에 태울수 있는 승객 확인 (m명타면 break)
        for (j = 0; j < convert_timetable.size(); j++) {
            if (bus_timetable[i] >= convert_timetable[j])
                cnt++;
            max = convert_timetable[j];
            if (cnt == m)
                break;
        }

        // 막차 탑승 계산
        if (i == bus_timetable.size() - 1) {
            // 승객이 꽉찬 경우 마지막 사람보다 1분 빨리
            if (cnt == m)
                boardTime = max - 1;
            // 남은 경우에는 막차 시간에 맞춰서
            else
                boardTime = bus_timetable[i];
        }
        // 막차X
        else {
            for (j = 0; j < cnt; j++)
                convert_timetable.erase(convert_timetable.begin());
        }
    }

    // 결과값을 문자열로 변환
    if (boardTime / 60 < 10)
        answer += '0' + to_string(boardTime / 60);
    else
        answer += to_string(boardTime / 60);

    if (boardTime%60 < 10)
        answer += ":0" + to_string(boardTime % 60);
    else
        answer += ":" + to_string(boardTime % 60);
    return answer;
}