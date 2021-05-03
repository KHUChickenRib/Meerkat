#include <string>
#include <vector>

using namespace std;

// slicing ���� ���� ���ϱ� (�ִ� n/2 ����)
vector<int> makeSliceEntry(int num) {
    vector<int> result;
    int i;

    for (i = 1; i <= (num / 2); i++)
        result.push_back(i);

    return result;
}

// ���ڿ� ���� ���ϱ�
int getLength(int num, string s) {
    int result = 0;
    vector<string> slice;       // �ڸ� ���ڿ����� ����
    int index = 0;              // �ε��� �ӽ� ����
    string temp;                // �ڸ� ���ڿ�
    int cnt, i;                 // cnt: �ݺ� ����

    // ���ڿ� �߶� slice vector�� ����
    while (1) {
        if (index + num > s.length()) {
            if (s.substr(index, s.length() - index).length() == 0)
                break;
            temp = s.substr(index, s.length() - index);
            slice.push_back(temp);
            break;
        }
        else {
            temp = s.substr(index, num);
            slice.push_back(temp);
            index += num;
        }
    }

    // �ݺ� ���� üũ (1�� ���ڿ� �״��, 2�� �̻��� ����(�ڸ���) + ���ڿ�)
    for (i = 0; i < slice.size(); i++) {
        cnt = 1;
        while (1) {
            if (i == slice.size() - 1 || slice[i] != slice[i + 1])
                break;
            if (slice[i] == slice[i + 1])
                cnt++;
            i++;
        }

        // 1�� �ݺ�
        if (cnt == 1)
            result += slice[i].length();
        // 2�� �̻� �ݺ�
        else
            result += to_string(cnt).length() + slice[i].length();
    }
    return result;
}

int solution(string s) {
    int answer = s.length();
    vector<int> v;
    int temp;
    int i;

    v = makeSliceEntry(answer);     // slice ����

    // slice ������ ���� ���� �� ��
    for (i = 0; i < v.size(); i++) {
        temp = getLength(v[i], s);

        if (temp < answer)
            answer = temp;
    }
    return answer;
}