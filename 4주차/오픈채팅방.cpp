#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

// ���� �������� split
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
    vector<string> result;      // �ӽ� �α� (id + ���Խ��ϴ�)
    map<string, string> client; // id, �г��� ����
    int i;
   
    // result�� �ӽ÷α� ����
    for (i = 0; i < record.size(); i++) {
        vector<string> temp = split(record[i]);

        // Enter (ID, �г��� map�� ���� �� ���ŵ� ����)
        if (temp[0] == "Enter") {
            result.push_back(temp[1] + " ���Խ��ϴ�.");
            client[temp[1]] = temp[2];
        }
        // Leave
        else if (temp[0] == "Leave")
            result.push_back(temp[1] + " �������ϴ�.");
        // Change
        else
            client[temp[1]] = temp[2];
        temp.clear();
    }

    // �ӽ÷α׸� �̿��Ͽ� answer�� ����
    for (i = 0; i < result.size(); i++) {
        vector<string> temp = split(result[i]);

        answer.push_back(client[temp[0]] + "���� " + temp[1]);
    }

    return answer;
}