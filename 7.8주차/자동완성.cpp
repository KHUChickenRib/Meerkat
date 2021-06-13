#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 문자 2개 비교
int compare(string a, string b) {
    int i;

    // substr로 비교하여 갯수 return
    for (i = 1; i < b.length() + 1; i++) {
        if (i == b.length())
            return i;
        if (a.substr(0,i) != b.substr(0,i))
            return i;
    }
}

// 문자 3개 비교
int compare(string a, string b, string c) {
    int i;

    // substr로 비교하여 갯수 return
    for (i = 1; i < b.length() + 1; i++) {
        if (i == b.length())
            return i;
        if (b.substr(0,i) != a.substr(0,i) && b.substr(0,i) != c.substr(0,i))
            return i;
    }
}

int solution(vector<string> words) {
    int answer = 0;
    int i;

    int num1, num2;

    sort(words.begin(), words.end());

    for (i = 0; i < words.size(); i++) {
        // 맨 앞
        if (i == 0) {
            num1 = compare(words[i + 1], words[i]);
            answer += num1;
        }
        // 맨 뒤
        else if (i == words.size() - 1) {
            num1 = compare(words[i - 1], words[i]);
            answer += num1;
        }
        // 나머지
        else {
            num2 = compare(words[i - 1], words[i], words[i + 1]);
            answer += num2;
        }
    }

    return answer;
}