#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = ""; // 정답 엔트리 저장
    string entry = "01";  // 말할 숫자 엔트리 저장
    string temp = ""; // 현재 숫자 임시 저장

    char alpha[6] = { 'A', 'B', 'C', 'D', 'E', 'F' }; // 10이상 자리수 처리

    int num = 2;    // 현재 숫자
    int i;          // 반복문 변수

    // 숫자 자리수 엔트리 만들기 (t*m개 만큼)
    while (entry.size() < t * m) {
        int tnum = num;

        // 진법 변환
        while (tnum > 0) {
            // 10이상 digit 처리
            if (tnum % n >= 10)
                temp += alpha[tnum % n - 10];
            else
                temp += to_string(tnum % n);
            tnum /= n;
        }
        reverse(temp.begin(), temp.end());  // 진수 변환 시 거꾸로 시작했으므로 reverse
        entry += temp;                      // 정답 엔트리 추가

        temp.clear();                       // 진법 변환 임시변수 초기화
        num++;
    }

    // 엔트리 길이 조정
    if (entry.size() > t * m) {
        while (entry.size() != t * m) {
            entry.erase(entry.end()-1);
        }
    }

    // 내 순서에 맞는 엔트리 찾기
    for (i = 0; i < t * m; i++)
    {
        if (i % m == p-1) {
            answer += entry[i];
        }
    }
    
    return answer;
}