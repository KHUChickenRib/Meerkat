#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

long long getResult(vector<long long> n, vector<string> o, string p) {
    long long result = 0;
    int i, j;

    for (i = 0; i < p.length(); i++) {
        for (j = 0; j < o.size(); j++) {
            if (o[j][0] == p[i]) {
                if (p[i] == '*') {
                    n[j] *= n[j + 1];
                }
                else if (p[i] == '-') {
                    n[j] -= n[j + 1];
                }
                else {
                    n[j] += n[j + 1];
                }
                n.erase(n.begin() + (j + 1));
                o.erase(o.begin() + j);
                j--;
            }
        }
    }
    result = n[0];

    return result;
}

long long solution(string expression) {
    long long answer = 0;
    long long tmp;                  // 값 비교 변수
    vector<long long> numbers;      // 피연산자
    vector<string> operations;      // 연산자
    vector<string> permutation;     // 나오는 모든 순열
    vector<string> v;               // 집합 -> 벡터 변환
    set<string> s;                  // 연산자 갯수 저장 임시 집합

    string temp1, temp2;
    int i;

    for (i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            while (isdigit(expression[i])) {
                temp1 += expression[i];
                i++;
            }
            numbers.push_back(stoll(temp1));

            if (expression[i] == '\0')
                break;
            temp1 = expression[i];
            operations.push_back(temp1);
            s.insert(temp1);
        }

        temp1.clear();
    }

    for (auto it = s.begin(); it != s.end(); it++)
        v.push_back(*it);

    do {
        for (int i = 0; i < v.size(); i++)
            temp2 += v[i];

        permutation.push_back(temp2);
        temp2.clear();
    } while (next_permutation(v.begin(), v.end()));

    for (i = 0; i < permutation.size(); i++) {
        tmp = abs(getResult(numbers, operations, permutation[i]));

        if (tmp > answer)
            answer = tmp;
    }

    return answer;
}