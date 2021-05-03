#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    int i;

    for (i = 0; i < participant.size(); i++) {
        if (m[participant[i]] != 0)
            m[participant[i]]++;
        else
            m[participant[i]] = 1;
    }

    for (i = 0; i < completion.size(); i++)
        m[completion[i]]--;

    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second == 1) {
            answer = it->first;
            break;
        }
    }

    return answer;
}