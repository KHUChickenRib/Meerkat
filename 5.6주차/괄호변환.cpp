#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 올바른 괄호 문자열 체크
bool check(string p) {
    int i;
    int cnt = 0;

    for (i = 0; i < p.length(); i++) {
        if (p[i] == '(')
            cnt++;
        else
            cnt--;
        if (cnt < 0)
            return false;
    }
    return true;
}

// 괄호 방향 뒤집기 (4-4)
string reverseString(string u) {
    string result;
    int i;

    for (i = 0; i < u.length(); i++) {
        if (u[i] == '(')
            result += ')';
        else
            result += '(';
    }
    return result;
}

string convert(string p) {
    string result;
    string u, v;
    int i;
    int cnt = 0;

    // 빈 문자열인 경우 (1단계)
    if (p.length() == 0)
        return p;

    // u와 v 분리 과정 (2단계)
    for (i = 0; i < p.length(); i++) {
        if (p[i] == '(')
            cnt++;
        else
            cnt--;
        if (cnt == 0)
            break;
    }
    u = p.substr(0, i + 1);
    v = p.substr(i + 1);

    // u가 올바른 괄호 문자열 (3단계)
    if (check(u)) {
        return u + convert(v);
    }
    // u가 올바르지 않은 괄호 문자열 (4단계)
    else {
        result += '(';          // 4-1
        result += convert(v);   // 4-2
        result += ')';          // 4-3

        // 4-4
        u.erase(u.begin());
        u.erase(u.end() - 1);
        u = reverseString(u);
        result += u;
    }

    return result;
}

string solution(string p) {
    string answer = "";

    // 올바른 괄호 문자열 우선 check
    if (check(p))
        return p;
    else
        answer = convert(p);

    return answer;
}