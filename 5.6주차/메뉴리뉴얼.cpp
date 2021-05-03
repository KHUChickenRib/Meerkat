#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;

// 글자수에 맞게 정렬 (글자수 같으면 큰값이 앞에)
bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.first.length() == b.first.length()) return a.second > b.second;
    return a.first.length() < b.first.length();
}

// 이진수 변환
string getbinary(int num, int size) {
    string result;
    int i;
    int index = size - 1;

    for (i = 0; i < size; i++)
        result += '0';

    while (num > 0) {
        if (num % 2 == 1)
            result[index] = '1';
        index--;
        num /= 2;
    }

    return result;
}

// 조합 구하기
string getCombination(string order, string binary) {
    string result;
    vector<int> index;
    int i;

    for (i = 0; i < binary.length(); i++) {
        if (binary[i] == '1')
            index.push_back(i);
    }

    for (i = 0; i < index.size(); i++) {
        result += order[index[i]];
    }

    return result;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> m;
    set<string> s;
    string temp;
    string com;
    int i, j;

    // 문자열 내부 정렬 (알파벳 오름차순)
    for (i = 0; i < orders.size(); i++)
        sort(orders[i].begin(), orders[i].end());

    // 해당되는 모든 조합 계산 후 map에 저장
    for (i = 0; i < orders.size(); i++) {
        for (j = 3; j < pow(2, orders[i].length()); j++) {
            temp = getbinary(j, orders[i].length());

            com = getCombination(orders[i], temp);

            if (com.length() == 1)
                continue;
            else {
                s.insert(com);
            }
        }

        set<string>::iterator it;
        for (it = s.begin(); it != s.end(); it++) {
            if (m[*it] >= 1)
                m[*it]++;
            else
                m[*it] = 1;
        }
        s.clear();
    }

    // map에 저장된 내용 저장 (정렬된 것은 vector에)
    vector<pair<string, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);

    // 코스의 값은 조합의 길이와 매칭
    for (i = 0; i < course.size(); i++) {
        int tmp = 1;
        for (auto num : vec) {
            // 주문 횟수 1은 제외
            if (num.second == 1)
                continue;
            // 단품 갯수 중 가장 많이 주문된 것을 저장 (같은 것이 여러개 들어갈 수 있음)
            if (num.first.length() == course[i]) {
                if (tmp < num.second) {
                    answer.push_back(num.first);
                    tmp = num.second;
                }
                else if (tmp == num.second) {
                    answer.push_back(num.first);
                }
            }
        }
    }

    // 오름차순으로 다시 정렬
    sort(answer.begin(), answer.end());

    return answer;
}