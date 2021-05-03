#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

// 공백 기준으로 split
vector<string> split(string info) {
    vector<string> result;
    istringstream ss(info);
    string buffer;

    while (getline(ss, buffer, ' '))
        // query split시 and 제외
        if (buffer != "and")
            result.push_back(buffer);

    return result;
}

// 나올수 있는 모든 경우의 수 만들기
string makeKey(vector<string> v, int num) {
    string result;
    int index = 0;

    while (index < 4) {
        if (num % 2 == 1)
            result += v[index];
        else
            result += '-';
        index++;
        num /= 2;
    }

    return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<string> split_query;     // query split
    vector<string> split_info;      // info split
    map<string, vector<int>> m;     // 나오는 모든 경우 저장 map

    string key;                     // info에서 나오는 모든 경우 저장
    string convert_query;           // and 지운 convert_query
    int value;                      // 점수 저장
    int i, j;

    // info에서 나오는 모든 경우 map에 저장
    for (i = 0; i < info.size(); i++) {
        split_info = split(info[i]);

        value = stoi(split_info[4]);

        for (j = 0; j < 16; j++) {
            key = makeKey(split_info, j);
            m[key].push_back(value);
        }
    }

    // map에 value 정렬
    for (auto it = m.begin(); it != m.end(); it++)
        sort(it->second.begin(), it->second.end());

    // query 해당하는 갯수 찾기 (query를 변환 후 이를 map의 key로 접근)
    for (i = 0; i < query.size(); i++) {
        split_query = split(query[i]);

        for (j = 0; j < 4; j++)
            convert_query += split_query[j];

        value = stoi(split_query[4]);

        if (m[convert_query].size() != 0)
            answer.push_back(m[convert_query].end() - lower_bound(m[convert_query].begin(), m[convert_query].end(), value));
        else
            answer.push_back(0);

        convert_query.clear();
    }
    return answer;
}