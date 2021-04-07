#include <string>
#include <vector>
#include <cctype>
#include <boost/algorithm/string.hpp>

using namespace std;

// ��� �빮�ڷ� ��ȯ (���߿��� �ٷ�� ���ϰ� �ϱ� ����)
void trans(string& str) {
    boost::to_upper(str);
}

vector<string> makeset(string str) {
    int i;
    vector<string> result;
    trans(str); // �빮�� ��ȯ

    // 2���� �߶� ���ĺ����� Ȯ��
    for (i = 0; i < str.length() - 1; i++) {
        if (isalpha(str[i]) != 0 && isalpha(str[i + 1]) != 0)
            result.push_back(str.substr(i, 2));
    }
    return result;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> set1, set2;      // ���ڿ� slicing set
    vector<string> temp1, temp2;    // �ӽ� ���� (������, ������)
    int i, j;                       // �ݺ��� ����

    // ���ڿ� 2�� ���� �����
    set1 = makeset(str1);
    set2 = makeset(str2);

    // �������� ��� (�� ���� ���)
    if (set1.size() == 0 && set2.size() == 0)
        return 65536;

    for (i = 0; i < set2.size(); i++) {
        for (j = 0; j < set1.size(); j++) {
            if (set2[i] == set1[j])
                break;
        }
        // ������ ���̽�
        if (j == set1.size()) {
            temp1.push_back(set2[i]);
            set2.erase(set2.begin() + i);
            i--;
        }
        // ������ ���̽�
        else {
            temp2.push_back(set2[i]);
            set2.erase(set2.begin() + i);
            temp2.push_back(set1[j]);
            set1.erase(set1.begin() + j);
            i--;
        }
    }

    // ������ ó��
    for (i = 0; i < temp1.size(); i++)
        set1.push_back(temp1[i]);
    // ������ ó��
    for (i = 0; i < temp2.size(); i += 2) {
        set1.push_back(temp2[i]);
        set2.push_back(temp2[i]);
    }

    answer = (int)((double)set2.size() / set1.size() * 65536);
    return answer;
}