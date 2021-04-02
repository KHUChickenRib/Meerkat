#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score, i;
    int pre = 4001;     // 이전 점수 기록 (*을 위해 필요)

    for (i = 0; i < dartResult.size(); i++)
    {
        // 숫자인 경우
        if (isdigit(dartResult[i]) != 0)
        {
            // 10점이 나온 경우 (뒤에 볼 필요 X -> 10점이 최대이기 때문)
            if (isdigit(dartResult[i + 1]) != 0) {
                score = 10;
                i++;
            }
            else {
                score = atoi(&dartResult[i]);
            }
        }
        // 문자인 경우
        else {
            // 제곱 수 처리
            if (dartResult[i] == 'S') {
                score = pow(score, 1);
            }
            else if (dartResult[i] == 'D') {
                score = pow(score, 2);
            }
            else if (dartResult[i] == 'T') {
                score = pow(score, 3);
            }
            // * 또는 #
            else {
                // *인 경우
                if (dartResult[i] == '*') {
                    // 맨 앞인 경우
                    if (pre == 4001)
                        score *= 2;
                    else {
                        score *= 2;
                        answer += pre;  // 저장한 pre를 추가(2배이기 때문)
                    }
                }
                // #인 경우
                else {
                    score = -score;
                }
            }
        }

        // 더 이상 갱신이 필요없는 경우 (해당 레이블의 점수가 끝난 경우)
        if (isdigit(dartResult[i + 1]) != 0 || i == dartResult.size() - 1)
        {
            answer += score;
            pre = score;    // 이전 점수 저장 (*을 대비)
        }

    }

    return answer;
}