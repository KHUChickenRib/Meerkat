#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string info) {
    vector<string> result;
    istringstream ss(info);
    string buffer;

    while (getline(ss, buffer, ','))
        result.push_back(buffer);

    return result;
}

int r_time(string a, string b) {
    int time1, time2;

    time1 = 60 * atoi(&a[0]) + atoi(&a[3]);
    time2 = 60 * atoi(&b[0]) + atoi(&b[3]);

    return time2 - time1;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    string sound;               // 재생시간동안 들은 멜로디
    vector<string> info;        // 음악 정보
    int l_time, m_time, cnt, i, j, loc;
    int pl_time = -1;           // 재생시간 비교


    for (i = 0; i < musicinfos.size(); i++) {
        info = split(musicinfos[i]);

        l_time = r_time(info[0], info[1]);

        cnt = count(info[3].begin(), info[3].end(), '#');
        m_time = info[3].length() - cnt;

        for (j = 0; j < (l_time / m_time) + 1; j++)
            sound += info[3];

        cnt *= j;

        // 멜로디 재생시간에 맞게 조정
        if (sound.size() - cnt > l_time) {
            while (sound.size() - cnt > l_time) {
                if (*(sound.end() - 1) == '#') {
                    sound.erase(sound.end() - 1);
                    sound.erase(sound.end() - 1);
                    cnt--;
                }
                else
                    sound.erase(sound.end() - 1);
            }
        }

        cnt = count(m.begin(), m.end(), '#');

        // 맞는 멜로디 추출 check
        if (l_time >= m.length() - cnt) {
            loc = sound.find(m, 0);

            while (loc != -1) {

                if (loc != -1 && sound[loc + m.length()] != '#' && pl_time < l_time) {
                    answer = info[2];
                    pl_time = l_time;
                    break;
                }

                loc = sound.find(m, loc + m.length());
            }
        }
        sound.clear();

    }

    if (answer.length() == 0)
        return "(None)";

    return answer;
}