#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string convert_ternary(int n) {
    string result = "";

    while (n > 0) {
        result += to_string(n%3);

        n /= 3;
    }
    return result;
}

int solution(int n) {
    int answer = 0;
    string ternary = convert_ternary(n);

    for (int i = 0; i < ternary.length(); i++)
        answer += (ternary[i] - '0') * pow(3, ternary.length() - (i + 1));

    return answer;
}