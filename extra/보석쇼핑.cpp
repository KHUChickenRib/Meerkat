#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> s;
    map<string, int> m;
    int left = 0;
    int right = 0;
    int i;

    for (i = 0; i < gems.size(); i++)
        s.insert(gems[i]);

    m[gems[0]] = 1;

    while (1) {
        if (left == gems.size())
            break;

        if (m.size() < s.size()) {
            right++;

            if (right == gems.size())
                break;

            if (m[gems[right]] != 0)
                m[gems[right]]++;
            else {
                m[gems[right]] = 1;
            }
        }
        else if (m.size() == s.size()) {
            if (answer.size() == 2) {
                if ((answer[1] - answer[0]) > (right - left)) {
                    answer[0] = left + 1;
                    answer[1] = right + 1;
                }
            }
            else {
                answer.push_back(left + 1);
                answer.push_back(right + 1);
            }
            if (m[gems[left]] == 1)
                m.erase(gems[left]);
            else {
                m[gems[left]]--;
            }
            left++;
        }
    }

    return answer;
}