#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// �ùٸ� ��ȣ ���ڿ� üũ
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

// ��ȣ ���� ������ (4-4)
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

    // �� ���ڿ��� ��� (1�ܰ�)
    if (p.length() == 0)
        return p;

    // u�� v �и� ���� (2�ܰ�)
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

    // u�� �ùٸ� ��ȣ ���ڿ� (3�ܰ�)
    if (check(u)) {
        return u + convert(v);
    }
    // u�� �ùٸ��� ���� ��ȣ ���ڿ� (4�ܰ�)
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

    // �ùٸ� ��ȣ ���ڿ� �켱 check
    if (check(p))
        return p;
    else
        answer = convert(p);

    return answer;
}