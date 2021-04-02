#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = ""; // ���� ��Ʈ�� ����
    string entry = "01";  // ���� ���� ��Ʈ�� ����
    string temp = ""; // ���� ���� �ӽ� ����

    char alpha[6] = { 'A', 'B', 'C', 'D', 'E', 'F' }; // 10�̻� �ڸ��� ó��

    int num = 2;    // ���� ����
    int i;          // �ݺ��� ����

    // ���� �ڸ��� ��Ʈ�� ����� (t*m�� ��ŭ)
    while (entry.size() < t * m) {
        int tnum = num;

        // ���� ��ȯ
        while (tnum > 0) {
            // 10�̻� digit ó��
            if (tnum % n >= 10)
                temp += alpha[tnum % n - 10];
            else
                temp += to_string(tnum % n);
            tnum /= n;
        }
        reverse(temp.begin(), temp.end());  // ���� ��ȯ �� �Ųٷ� ���������Ƿ� reverse
        entry += temp;                      // ���� ��Ʈ�� �߰�

        temp.clear();                       // ���� ��ȯ �ӽú��� �ʱ�ȭ
        num++;
    }

    // ��Ʈ�� ���� ����
    if (entry.size() > t * m) {
        while (entry.size() != t * m) {
            entry.erase(entry.end()-1);
        }
    }

    // �� ������ �´� ��Ʈ�� ã��
    for (i = 0; i < t * m; i++)
    {
        if (i % m == p-1) {
            answer += entry[i];
        }
    }
    
    return answer;
}