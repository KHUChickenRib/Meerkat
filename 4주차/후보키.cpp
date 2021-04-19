#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

// 이진수 문자열 변환
string getbinary(int num, int size) {
    string result;
    int i;
    int index = size - 1;

    // 길이에 맞춰서 0으로 초기화
    for (i = 0; i < size; i++)
        result += '0';

    // 진법 변환 (1인 부분만 변환)
    while (num > 0) {
        if (num % 2 == 1)
            result[index] = '1';
        index--;
        num /= 2;
    }

    return result;
}

bool check(string str, vector<vector<string>> relation) {
    set<string> count;      // 유일성 만족 확인 집합 (중복 허용 x)
    vector<int> index;      // 활성 bit 저장 vector
    string temp = "";
    int i, j;

    // 1인 부분의 인덱스 저장 (속성 위치)
    for (i = 0; i < str.length(); i++) {
        if (str[i] == '1')
            index.push_back(i);
    }

    // 활성 bit에 해당되는 컬럼을 조합하여 집합에 insert
    // ex) 이름: meerkat, 과목: Database -> meerkatDatabase로 각 컬럼의 문자열을 합쳐서 유일성 체크
    for (i = 0; i < relation.size(); i++) {
        for (j = 0; j < index.size(); j++)
            temp += relation[i][index[j]];
        count.insert(temp);
        temp.clear();
    }

    // row 갯수와 집합 원소 수 동일 (유일성 만족)
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

    // 문자열 변환 후 유일성 만족 check
    for (i = 0; i < pow(2, relation[0].size()) - 1; i++) {
        binary = getbinary(i + 1, relation[0].size());

        if (check(binary, relation))
            candidate.push_back(i + 1);
    }

    // 최소성을 만족하지 않는 슈퍼키 제거 (and 연산 이용)
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