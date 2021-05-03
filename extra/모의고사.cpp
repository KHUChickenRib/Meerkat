#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> stu1 = { 1,2,3,4,5 };
    vector<int> stu2 = { 2,1,2,3,2,4,2,5 };
    vector<int> stu3 = { 3,3,1,1,2,2,4,4,5,5 };
    vector<int> cnt = { 0,0,0 };
    int i;

    for (i = 0; i < answers.size(); i++) {
        if (answers[i] == stu1[i % stu1.size()])
            cnt[0]++;
        if (answers[i] == stu2[i % stu2.size()])
            cnt[1]++;
        if (answers[i] == stu3[i % stu3.size()])
            cnt[2]++;
    }

    if (cnt[0] == cnt[1]) {
        if (cnt[0] < cnt[2])
            answer.push_back(3);
        else if (cnt[0] == cnt[2]) {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
        else {
            answer.push_back(1);
            answer.push_back(2);
        }
    }
    else if (cnt[0] > cnt[1]) {
        if (cnt[0] < cnt[2])
            answer.push_back(3);
        else if (cnt[0] == cnt[2]) {
            answer.push_back(1);
            answer.push_back(3);
        }
        else
            answer.push_back(1);
    }
    else if (cnt[0] < cnt[1]) {
        if (cnt[1] < cnt[2])
            answer.push_back(3);
        else if (cnt[1] == cnt[2]) {
            answer.push_back(2);
            answer.push_back(3);
        }
        else
            answer.push_back(2);
    }

    return answer;
}