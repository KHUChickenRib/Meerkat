#include <string>
#include <vector>
#include <sstream>

using namespace std;

// query, info split
vector<string> split(string info) {
    vector<string> result;
    istringstream ss(info);
    string buffer;

    // and 제외 모든 문자열 추가
    while (getline(ss, buffer, ' ')) {
        if (buffer != "and")
            result.push_back(buffer);
    }

    return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<string> split_query;
    vector<string> split_info;
    int i, j;
    int cnt1, cnt2;

    for (i = 0; i < query.size(); i++) {
        cnt1 = 0;
        split_query = split(query[i]);      // query split

        // 각 info별로 query에 맞는지 확인
        for (j = 0; j < info.size(); j++) {
            cnt2 = 0;
            split_info = split(info[j]);

            if (split_query[0] == split_info[0] || split_query[0] == "-")
                cnt2++;
            if (split_query[1] == split_info[1] || split_query[1] == "-")
                cnt2++;
            if (split_query[2] == split_info[2] || split_query[2] == "-")
                cnt2++;
            if (split_query[3] == split_info[3] || split_query[3] == "-")
                cnt2++;
            if (stoi(split_query[4]) <= stoi(split_info[4]))
                cnt2++;

            // query에 맞는 경우
            if (cnt2 == 5)
                cnt1++;
        }
        answer.push_back(cnt1);
    }
    
    return answer;
}