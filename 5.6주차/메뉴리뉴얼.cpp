#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;

// ���ڼ��� �°� ���� (���ڼ� ������ ū���� �տ�)
bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.first.length() == b.first.length()) return a.second > b.second;
    return a.first.length() < b.first.length();
}

// ������ ��ȯ
string getbinary(int num, int size) {
    string result;
    int i;
    int index = size - 1;

    for (i = 0; i < size; i++)
        result += '0';

    while (num > 0) {
        if (num % 2 == 1)
            result[index] = '1';
        index--;
        num /= 2;
    }

    return result;
}

// ���� ���ϱ�
string getCombination(string order, string binary) {
    string result;
    vector<int> index;
    int i;

    for (i = 0; i < binary.length(); i++) {
        if (binary[i] == '1')
            index.push_back(i);
    }

    for (i = 0; i < index.size(); i++) {
        result += order[index[i]];
    }

    return result;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> m;
    set<string> s;
    string temp;
    string com;
    int i, j;

    // ���ڿ� ���� ���� (���ĺ� ��������)
    for (i = 0; i < orders.size(); i++)
        sort(orders[i].begin(), orders[i].end());

    // �ش�Ǵ� ��� ���� ��� �� map�� ����
    for (i = 0; i < orders.size(); i++) {
        for (j = 3; j < pow(2, orders[i].length()); j++) {
            temp = getbinary(j, orders[i].length());

            com = getCombination(orders[i], temp);

            if (com.length() == 1)
                continue;
            else {
                s.insert(com);
            }
        }

        set<string>::iterator it;
        for (it = s.begin(); it != s.end(); it++) {
            if (m[*it] >= 1)
                m[*it]++;
            else
                m[*it] = 1;
        }
        s.clear();
    }

    // map�� ����� ���� ���� (���ĵ� ���� vector��)
    vector<pair<string, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);

    // �ڽ��� ���� ������ ���̿� ��Ī
    for (i = 0; i < course.size(); i++) {
        int tmp = 1;
        for (auto num : vec) {
            // �ֹ� Ƚ�� 1�� ����
            if (num.second == 1)
                continue;
            // ��ǰ ���� �� ���� ���� �ֹ��� ���� ���� (���� ���� ������ �� �� ����)
            if (num.first.length() == course[i]) {
                if (tmp < num.second) {
                    answer.push_back(num.first);
                    tmp = num.second;
                }
                else if (tmp == num.second) {
                    answer.push_back(num.first);
                }
            }
        }
    }

    // ������������ �ٽ� ����
    sort(answer.begin(), answer.end());

    return answer;
}