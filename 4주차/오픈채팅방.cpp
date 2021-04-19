#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

// 공백 기준으로 split
vector<string> split(string info) {
    vector<string> result;
    istringstream ss(info);
    string buffer;

    while (getline(ss, buffer, ' '))
        result.push_back(buffer);

    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> result;      // 임시 로그 (id + 들어왔습니다)
    map<string, string> client; // id, 닉네임 매핑
    int i;
   
    // result에 임시로그 저장
    for (i = 0; i < record.size(); i++) {
        vector<string> temp = split(record[i]);

        // Enter (ID, 닉네임 map에 저장 및 갱신도 실행)
        if (temp[0] == "Enter") {
            result.push_back(temp[1] + " 들어왔습니다.");
            client[temp[1]] = temp[2];
        }
        // Leave
        else if (temp[0] == "Leave")
            result.push_back(temp[1] + " 나갔습니다.");
        // Change
        else
            client[temp[1]] = temp[2];
        temp.clear();
    }

    // 임시로그를 이용하여 answer에 저장
    for (i = 0; i < result.size(); i++) {
        vector<string> temp = split(result[i]);

        answer.push_back(client[temp[0]] + "님이 " + temp[1]);
    }

    return answer;
}