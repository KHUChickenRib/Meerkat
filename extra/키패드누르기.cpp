#include <string>
#include <vector>

using namespace std;

int dist(int num1, int num2) {
    int result = 0;

    if (num1 == 0)
        num1 = 11;
    if (num2 == 0)
        num2 = 11;

    if (num1 % 3 == 1) {
        num1++;
        result++;
    }
    else if (num1 % 3 == 0) {
        num1--;
        result++;
    }

    result += abs((num1 - num2) / 3);
    return result;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int i;
    int left = 10;
    int right = 12;
    int left_dist, right_dist;

    for (i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            left = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            right = numbers[i];
        }
        else {
            left_dist = dist(left, numbers[i]);
            right_dist = dist(right, numbers[i]);

            if (left_dist < right_dist) {
                answer += "L";
                left = numbers[i];
            }
            else if (left_dist > right_dist) {
                answer += "R";
                right = numbers[i];
            }
            else {
                if (hand == "right") {
                    answer += "R";
                    right = numbers[i];
                }
                else {
                    answer += "L";
                    left = numbers[i];
                }
            }
        }
    }

    return answer;
}