#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

// ���� �������� split
vector<string> split(string info) {
    vector<string> result;
    istringstream ss(info);
    string buffer;

    while (getline(ss, buffer, ' '))
        // query split�� and ����
        if (buffer != "and")
            result.push_back(buffer);

    return result;
}

// ���ü� �ִ� ��� ����� �� �����
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
    map<string, vector<int>> m;     // ������ ��� ��� ���� map

    string key;                     // info���� ������ ��� ��� ����
    string convert_query;           // and ���� convert_query
    int value;                      // ���� ����
    int i, j;

    // info���� ������ ��� ��� map�� ����
    for (i = 0; i < info.size(); i++) {
        split_info = split(info[i]);

        value = stoi(split_info[4]);

        for (j = 0; j < 16; j++) {
            key = makeKey(split_info, j);
            m[key].push_back(value);
        }
    }

    // map�� value ����
    for (auto it = m.begin(); it != m.end(); it++)
        sort(it->second.begin(), it->second.end());

    // query �ش��ϴ� ���� ã�� (query�� ��ȯ �� �̸� map�� key�� ����)
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