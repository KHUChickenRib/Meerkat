#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// �°����� timetable�� ��ȯ (�д����� ����)
vector<int> convert(vector<string> timetable) {
    vector<int> timeTable;
    int i;

    for (i = 0; i < timetable.size(); i++) {
        int num = stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3,2));
        timeTable.push_back(num);
    }

    return timeTable;
}

// ���� ����ð� ��� (�д����� ����)
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
    sort(convert_timetable.begin(), convert_timetable.end());       // �°� ž�½ð� ����

    bus_timetable = getBusTime(n, t);

    // ���� ž�½ð��� ���鼭 Ż �ð��� ����
    for (i = 0; i < bus_timetable.size(); i++) {
        int cnt = 0;

        // �ش� �ð��� �¿�� �ִ� �°� Ȯ�� (m��Ÿ�� break)
        for (j = 0; j < convert_timetable.size(); j++) {
            if (bus_timetable[i] >= convert_timetable[j])
                cnt++;
            max = convert_timetable[j];
            if (cnt == m)
                break;
        }

        // ���� ž�� ���
        if (i == bus_timetable.size() - 1) {
            // �°��� ���� ��� ������ ������� 1�� ����
            if (cnt == m)
                boardTime = max - 1;
            // ���� ��쿡�� ���� �ð��� ���缭
            else
                boardTime = bus_timetable[i];
        }
        // ����X
        else {
            for (j = 0; j < cnt; j++)
                convert_timetable.erase(convert_timetable.begin());
        }
    }

    // ������� ���ڿ��� ��ȯ
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