#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int i;

    for (i = 0; i < arr1.size(); i++)
    {
        int uni = arr1[i] | arr2[i];    // or ���
        int remain;                     // ������ (2������ ��ȯ)
        string temp = "";

        // 2������ ��ȯ�۾� (1�� #, �ƴϸ� ����)
        while (uni > 0)
        {
            if (uni % 2 == 1)
                temp += '#';
            else
                temp += ' ';
            uni /= 2;
        }

        // ���̰� ���ڶ� ��� (���� ������ ���� ���� �߰�)
        if (temp.size() < n)
        {
            while (temp.size() != n) {
                temp += ' ';
            }
        }

        reverse(temp.begin(), temp.end());      // ������ ��ȯ�� �������� �Ǿ��־����Ƿ� reverse
        answer.push_back(temp);
    }
    return answer;
}