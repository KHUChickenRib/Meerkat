#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;

// �빮�� ��ȯ
void trans(string& str) {
    boost::to_upper(str);
}

// HEAD ������ ���� ã��
int find_head_end(string str) {
    int i;

    for (i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            return i;
        }
    }
}

// NUMBER ������ ���� ã��
int find_number_end(int index, string str) {
    int i;

    for (i = index; i < index + 5; i++) {
        if (!isdigit(str[i]))
            return i;
    }
}

// �� ���ڿ� ��
bool compare(string str1, string str2) {
    string temp1, temp2;    // HEAD, NUMBER �ӽ� ����
    int number1, number2;   // NUMBER �κ� ����
    int index1, index2;     // HEAD ������ ���� ����

    // HEAD ������ ã��
    index1 = find_head_end(str1);
    index2 = find_head_end(str2);

    // HEAD ����
    temp1 = str1.substr(0, index1);
    temp2 = str2.substr(0, index2);

    // �빮�� ��ȯ
    trans(temp1);
    trans(temp2);

    // HEAD ��
    if (temp1 > temp2)
        return true;
    else if (temp1 < temp2)
        return false;

    // NUMBER ���� �� ��ȯ
    temp1 = str1.substr(index1, find_number_end(index1, str1) - index1);
    temp2 = str2.substr(index2, find_number_end(index2, str2) - index2);

    number1 = stoi(temp1);
    number2 = stoi(temp2);

    // NUMBER ��
    if (number1 > number2)
        return true;
    else
        return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    int i, j;

    // answer setting
    for (i = 0; i < files.size(); i++)
        answer.push_back(files[i]);

    // ���Ͽ� ���� (�����Ʈ ���)
    for (i = 0; i < answer.size(); i++) {
        for (j = 0; j < answer.size() - 1; j++) {
            if (compare(answer[j], answer[j + 1]))
                swap(answer[j], answer[j + 1]);
        }
    }
    return answer;
}