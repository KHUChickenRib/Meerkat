#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// , 기준으로 문자열 split
vector<string> split(string info) {
    vector<string> result;
    istringstream ss(info);
    string buffer;

    while (getline(ss, buffer, ','))
        result.push_back(buffer);

    return result;
}

// 재생시간 계산
int r_time(string a, string b) {
    int time1, time2;

    time1 = 60 * atoi(&a[0]) + atoi(&a[3]);
    time2 = 60 * atoi(&b[0]) + atoi(&b[3]);

    return time2 - time1;
}

// #이 포함되어 있는 부분을 소문자로 변환
string convert(string a) {
    string result;
    int i;

    for (i = 0; i < a.length(); i++) {
        if (a[i] == 'B' || a[i] == 'E')
            result += a[i];
        else {
            if (a[i + 1] == '#') {
                result += (a[i] - 32);
                i++;
            }
            else
                result += a[i];
        }
    }
    return result;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    string sound;               // 재생시간동안 들은 멜로디
    string con1, con2;          // # 포함 조정 변수
    vector<string> info;        // 음악 정보
    int l_time;                 // 재생시간
    int pl_time = -1;           // 재생시간 비교
    int i, j;

    con1 = convert(m);
    for (i = 0; i < musicinfos.size(); i++) {
        info = split(musicinfos[i]);
        l_time = r_time(info[0], info[1]);
        con2 = convert(info[3]);

        // 재생시간 동안 들은 멜로디
        for (j = 0; j < (l_time / con2.length()); j++)
            sound += con2;
        sound += con2.substr(0, l_time % con2.length());    // 중간에 끊은 경우 나머지 계산

        // 멜로디 일치 여부 확인
        if (sound.find(con1) != -1 && pl_time < l_time) {
            answer = info[2];
            pl_time = l_time;
        }
        sound.clear();
    }

    if (answer.length() == 0)
        return "(None)";

    return answer;
}