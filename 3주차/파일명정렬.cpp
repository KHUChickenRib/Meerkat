#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;

// 대문자 변환
void trans(string& str) {
    boost::to_upper(str);
}

// HEAD 끝나는 지점 찾기
int find_head_end(string str) {
    int i;

    for (i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            return i;
        }
    }
}

// NUMBER 끝나는 지점 찾기
int find_number_end(int index, string str) {
    int i;

    for (i = index; i < index + 5; i++) {
        if (!isdigit(str[i]))
            return i;
    }
}

// 두 문자열 비교
bool compare(string str1, string str2) {
    string temp1, temp2;    // HEAD, NUMBER 임시 저장
    int number1, number2;   // NUMBER 부분 저장
    int index1, index2;     // HEAD 끝지점 저장 변수

    // HEAD 끝지점 찾기
    index1 = find_head_end(str1);
    index2 = find_head_end(str2);

    // HEAD 추출
    temp1 = str1.substr(0, index1);
    temp2 = str2.substr(0, index2);

    // 대문자 변환
    trans(temp1);
    trans(temp2);

    // HEAD 비교
    if (temp1 > temp2)
        return true;
    else if (temp1 < temp2)
        return false;

    // NUMBER 추출 및 변환
    temp1 = str1.substr(index1, find_number_end(index1, str1) - index1);
    temp2 = str2.substr(index2, find_number_end(index2, str2) - index2);

    number1 = stoi(temp1);
    number2 = stoi(temp2);

    // NUMBER 비교
    if (number1 > number2)
        return true;
    else
        return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    int i, j;

    // answer setting
    for (i = 0; i < files.size(); i++)
        answer.push_back(files[i]);

    // 비교하여 정렬 (버블소트 사용)
    for (i = 0; i < answer.size(); i++) {
        for (j = 0; j < answer.size() - 1; j++) {
            if (compare(answer[j], answer[j + 1]))
                swap(answer[j], answer[j + 1]);
        }
    }
    return answer;
}