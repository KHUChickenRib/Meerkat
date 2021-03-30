#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int i;

    for (i = 0; i < arr1.size(); i++)
    {
        int uni = arr1[i] | arr2[i];    // or 계산
        int remain;                     // 나머지 (2진수로 전환)
        string temp = "";

        // 2진수로 변환작업 (1은 #, 아니면 공백)
        while (uni > 0)
        {
            if (uni % 2 == 1)
                temp += '#';
            else
                temp += ' ';
            uni /= 2;
        }

        // 길이가 모자란 경우 (길이 맞을때 까지 공백 추가)
        if (temp.size() < n)
        {
            while (temp.size() != n) {
                temp += ' ';
            }
        }

        reverse(temp.begin(), temp.end());      // 이진수 변환시 역순으로 되어있었으므로 reverse
        answer.push_back(temp);
    }
    return answer;
}