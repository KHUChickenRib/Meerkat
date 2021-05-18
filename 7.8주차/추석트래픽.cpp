#include <string>
#include <vector>
#include <sstream>

using namespace std;

// 공백 기준 split
vector<string> split(string info) {
    vector<string> result;
    istringstream ss(info);
    string buffer;

    while (getline(ss, buffer, ' '))
        result.push_back(buffer);

    return result;
}

// 시간 계산
int getTime(string a) {
    int time = 0;

    time += stod(a.substr(0, 2)) * 3600000;
    time += stod(a.substr(3, 2)) * 60000;
    time += stod(a.substr(6, 6)) * 1000;

    return time;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<vector<int>> times;          // 시작시간, 종료시간 저장
    vector<string> info;                // split된 로그 정보
    int startTime, terminateTime;
    int i, j, cnt;

    // 시작시간, 종료시간 저장 반복문
    for (i = 0; i < lines.size(); i++) {
        info = split(lines[i]);

        terminateTime = getTime(info[1]);

        int index = info[2].find('s');
        startTime = terminateTime - ((stod(info[2].substr(0, index))) * 1000) + 1;

        times.push_back({ startTime, terminateTime });
    }

    // 로그 비교 (끝시간+1초 > 시작시간)
    for (i = 0; i < times.size(); i++) {
        cnt = 0;
        for (j = i; j < times.size(); j++) {
            if (times[i][1] + 1000 > times[j][0])
                cnt++;
        }

        if (cnt > answer)
            answer = cnt;
    }

    return answer;
}