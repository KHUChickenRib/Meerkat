#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> v;
    vector<int> temp;
    string num;
    int i, j, k;

    for (i = 1; i < s.length() - 1; i++) {
        if (s[i] == '{')
            temp.clear();
        else if (isdigit(s[i]) != 0) {
            while (isdigit(s[i]) != 0) {
                num += s[i];
                i++;
            }
            temp.push_back(stoi(num));
            num.clear();

            if (s[i] == '}')
                v.push_back(temp);
        }
        else if (s[i] == '}')
            v.push_back(temp);
    }

    sort(v.begin(), v.end(), cmp);

    for (i = 0; i < v.size(); i++) {
        for (j = 0; j < v[i].size(); j++) {
            for (k = 0; k < answer.size(); k++) {
                if (answer[k] == v[i][j])
                    break;
            }
            if (k == answer.size()) {
                answer.push_back(v[i][j]);
                break;
            }
        }
    }

    return answer;
}

int main() {
    vector<int> answer;
    string input;
    cin >> input;

    answer = solution(input);

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;

    return 0;
}