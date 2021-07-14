#include <string>
#include <vector>

using namespace std;

// 문자열을 초단위로 변환
int convertSecond(string time) {
    int result = 0;
    
    result += stoi(time.substr(0,2)) * 3600;
    result += stoi(time.substr(3,2)) * 60;
    result += stoi(time.substr(6,2));
    
    return result;
}

// 초단위를 문자열로 변환
string convertTime(int second) {
    string result = "";
    
    string Second = to_string(second%60);
    second /= 60;
    
    string Minute = to_string(second%60);
    second /= 60;
    
    string Hour = to_string(second);
    
    if (Hour.length() == 1)
        result += "0" + Hour + ":";
    else
        result += Hour + ":";
    
    if (Minute.length() == 1)
        result += "0" + Minute + ":";
    else
        result += Minute + ":";
    
    if (Second.length() == 1)
        result += "0" + Second;
    else
        result += Second;
    
    return result;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    vector<int> count(360000);  // 시청자 수 저장 vector
    int startSecond, endSecond, second, i, j;
    int playSecond, advSecond;  // 재생시간, 광고시간 (초 단위)
    string startTime, endTime;  // 로그 시작시간, 종료시간 임시 저장
    
    long long cnt = 0;      // 시청자 수
    long long max = 0;      // 가장 많은 시청자 수
    
    // 광고시간과 동일한 경우
    if (play_time == adv_time)
        return "00:00:00";
    
    // 광고시간, 재생시간 각각 변환
    playSecond = convertSecond(play_time);
    advSecond = convertSecond(adv_time);
    
    // 광고 시작시간과 종료시간 변환 후 vector에 count
    for (i = 0; i < logs.size(); i++) {
        startTime = logs[i].substr(0,8);
        endTime = logs[i].substr(9);
        
        startSecond = convertSecond(startTime);
        endSecond = convertSecond(endTime);
        
        for (j = startSecond; j < endSecond; j++)
            count[j]++;
    }
    
    // 0초에서 광고시간 시청자 수 count
    for (i = 0; i < advSecond; i++)
        cnt += count[i];
    max = cnt;
    second = 0;

    // 다음 한칸씩 이동하면서 count 개선
    for (i = advSecond; i < playSecond; i++) {
        cnt -= count[i - advSecond];
        cnt += count[i];
        
        if (cnt > max) {
            second = i - advSecond + 1;
            cnt = max;
        }
    }
    
    answer = convertTime(second);
    return answer;
}