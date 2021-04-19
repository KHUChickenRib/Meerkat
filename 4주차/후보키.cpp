#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

// ������ ���ڿ� ��ȯ
string getbinary(int num, int size) {
    string result;
    int i;
    int index = size - 1;

    // ���̿� ���缭 0���� �ʱ�ȭ
    for (i = 0; i < size; i++)
        result += '0';

    // ���� ��ȯ (1�� �κи� ��ȯ)
    while (num > 0) {
        if (num % 2 == 1)
            result[index] = '1';
        index--;
        num /= 2;
    }

    return result;
}

bool check(string str, vector<vector<string>> relation) {
    set<string> count;      // ���ϼ� ���� Ȯ�� ���� (�ߺ� ��� x)
    vector<int> index;      // Ȱ�� bit ���� vector
    string temp = "";
    int i, j;

    // 1�� �κ��� �ε��� ���� (�Ӽ� ��ġ)
    for (i = 0; i < str.length(); i++) {
        if (str[i] == '1')
            index.push_back(i);
    }

    // Ȱ�� bit�� �ش�Ǵ� �÷��� �����Ͽ� ���տ� insert
    // ex) �̸�: meerkat, ����: Database -> meerkatDatabase�� �� �÷��� ���ڿ��� ���ļ� ���ϼ� üũ
    for (i = 0; i < relation.size(); i++) {
        for (j = 0; j < index.size(); j++)
            temp += relation[i][index[j]];
        count.insert(temp);
        temp.clear();
    }

    // row ������ ���� ���� �� ���� (���ϼ� ����)
    if (count.size() == relation.size())
        return true;
    return false;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<int> candidate;
    string binary;
    int num1, num2;
    int i, j;

    // ���ڿ� ��ȯ �� ���ϼ� ���� check
    for (i = 0; i < pow(2, relation[0].size()) - 1; i++) {
        binary = getbinary(i + 1, relation[0].size());

        if (check(binary, relation))
            candidate.push_back(i + 1);
    }

    // �ּҼ��� �������� �ʴ� ����Ű ���� (and ���� �̿�)
    for (i = candidate.size() - 1; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            if ((candidate[i] & candidate[j]) == candidate[j]) {
                candidate.erase(candidate.begin() + i);
                break;
            }
        }
    }
    answer = candidate.size();
    return answer;
}