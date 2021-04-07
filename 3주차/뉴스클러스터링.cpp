#include <string>
#include <vector>
#include <cctype>
#include <boost/algorithm/string.hpp>

using namespace std;

// 모두 대문자로 변환 (다중원소 다루기 편하게 하기 위함)
void trans(string& str) {
    boost::to_upper(str);
}

vector<string> makeset(string str) {
    int i;
    vector<string> result;
    trans(str); // 대문자 변환

    // 2개씩 잘라 알파벳인지 확인
    for (i = 0; i < str.length() - 1; i++) {
        if (isalpha(str[i]) != 0 && isalpha(str[i + 1]) != 0)
            result.push_back(str.substr(i, 2));
    }
    return result;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> set1, set2;      // 문자열 slicing set
    vector<string> temp1, temp2;    // 임시 저장 (교집합, 합집합)
    int i, j;                       // 반복문 변수

    // 문자열 2개 집합 만들기
    set1 = makeset(str1);
    set2 = makeset(str2);

    // 공집합인 경우 (두 집합 모두)
    if (set1.size() == 0 && set2.size() == 0)
        return 65536;

    for (i = 0; i < set2.size(); i++) {
        for (j = 0; j < set1.size(); j++) {
            if (set2[i] == set1[j])
                break;
        }
        // 합집합 케이스
        if (j == set1.size()) {
            temp1.push_back(set2[i]);
            set2.erase(set2.begin() + i);
            i--;
        }
        // 교집합 케이스
        else {
            temp2.push_back(set2[i]);
            set2.erase(set2.begin() + i);
            temp2.push_back(set1[j]);
            set1.erase(set1.begin() + j);
            i--;
        }
    }

    // 합집합 처리
    for (i = 0; i < temp1.size(); i++)
        set1.push_back(temp1[i]);
    // 교집합 처리
    for (i = 0; i < temp2.size(); i += 2) {
        set1.push_back(temp2[i]);
        set2.push_back(temp2[i]);
    }

    answer = (int)((double)set2.size() / set1.size() * 65536);
    return answer;
}