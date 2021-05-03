#include <string>
#include <vector>

using namespace std;

// slicing 단위 갯수 구하기 (최대 n/2 길이)
vector<int> makeSliceEntry(int num) {
    vector<int> result;
    int i;

    for (i = 1; i <= (num / 2); i++)
        result.push_back(i);

    return result;
}

// 문자열 길이 구하기
int getLength(int num, string s) {
    int result = 0;
    vector<string> slice;       // 자른 문자열들을 저장
    int index = 0;              // 인덱스 임시 저장
    string temp;                // 자른 문자열
    int cnt, i;                 // cnt: 반복 갯수

    // 문자열 잘라서 slice vector에 저장
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

    // 반복 갯수 체크 (1은 문자열 그대로, 2개 이상은 갯수(자리수) + 문자열)
    for (i = 0; i < slice.size(); i++) {
        cnt = 1;
        while (1) {
            if (i == slice.size() - 1 || slice[i] != slice[i + 1])
                break;
            if (slice[i] == slice[i + 1])
                cnt++;
            i++;
        }

        // 1번 반복
        if (cnt == 1)
            result += slice[i].length();
        // 2번 이상 반복
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

    v = makeSliceEntry(answer);     // slice 단위

    // slice 단위별 길이 측정 후 비교
    for (i = 0; i < v.size(); i++) {
        temp = getLength(v[i], s);

        if (temp < answer)
            answer = temp;
    }
    return answer;
}