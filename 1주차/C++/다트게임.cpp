#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score, i;
    int pre = 4001;     // ���� ���� ��� (*�� ���� �ʿ�)

    for (i = 0; i < dartResult.size(); i++)
    {
        // ������ ���
        if (isdigit(dartResult[i]) != 0)
        {
            // 10���� ���� ��� (�ڿ� �� �ʿ� X -> 10���� �ִ��̱� ����)
            if (isdigit(dartResult[i + 1]) != 0) {
                score = 10;
                i++;
            }
            else {
                score = atoi(&dartResult[i]);
            }
        }
        // ������ ���
        else {
            // ���� �� ó��
            if (dartResult[i] == 'S') {
                score = pow(score, 1);
            }
            else if (dartResult[i] == 'D') {
                score = pow(score, 2);
            }
            else if (dartResult[i] == 'T') {
                score = pow(score, 3);
            }
            // * �Ǵ� #
            else {
                // *�� ���
                if (dartResult[i] == '*') {
                    // �� ���� ���
                    if (pre == 4001)
                        score *= 2;
                    else {
                        score *= 2;
                        answer += pre;  // ������ pre�� �߰�(2���̱� ����)
                    }
                }
                // #�� ���
                else {
                    score = -score;
                }
            }
        }

        // �� �̻� ������ �ʿ���� ��� (�ش� ���̺��� ������ ���� ���)
        if (isdigit(dartResult[i + 1]) != 0 || i == dartResult.size() - 1)
        {
            answer += score;
            pre = score;    // ���� ���� ���� (*�� ���)
        }

    }

    return answer;
}