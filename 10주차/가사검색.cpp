#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ?�� a�Ǵ� z�� ġȯ
string replaceAll(const string& str, const string& pattern, const string& replace)
{
    string result = str;
    string::size_type pos = 0;
    string::size_type offset = 0;
    while ((pos = result.find(pattern, offset)) != string::npos)
    {
        result.replace(result.begin() + pos, result.begin() + pos + pattern.size(), replace);
        offset = pos + replace.size();
    }
    return result;
}

// ���� �ľ� (upper_bound, lower_bound)
int getcount(vector<string>& words, string min, string max) {
    int loc1 = lower_bound(words.begin(), words.end(), min) - words.begin();
    int loc2 = upper_bound(words.begin(), words.end(), max) - words.begin();

    return loc2 - loc1;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    int i;
    int length;

    string min, max;
    vector<vector<string>> forwardwords(10001);         // ������ �ܾ�
    vector<vector<string>> backwardwords(10001);        // ������ �ܾ� (?�� �տ� ������ ���)

    // ������, ������ �ܾ� ���� (�������� �ٸ� index)
    for (i = 0; i < words.size(); i++) {
        length = words[i].length();
        forwardwords[length].push_back(words[i]);
        reverse(words[i].begin(), words[i].end());
        backwardwords[length].push_back(words[i]);
    }

    // ������, ������ ����
    for (i = 0; i < forwardwords.size(); i++) {
        if (forwardwords[i].size() != 0) {
            sort(forwardwords[i].begin(), forwardwords[i].end());
            sort(backwardwords[i].begin(), backwardwords[i].end());
        }
    }

    // ���� �ľ�
    for (i = 0; i < queries.size(); i++) {
        length = queries[i].length();
        // ������ �ܾ�
        if (queries[i][0] != '?') {
            min = replaceAll(queries[i], "?", "a");
            max = replaceAll(queries[i], "?", "z");
            answer.push_back(getcount(forwardwords[length], min, max));
        }
        else {
            reverse(queries[i].begin(), queries[i].end());
            min = replaceAll(queries[i], "?", "a");
            max = replaceAll(queries[i], "?", "z");
            answer.push_back(getcount(backwardwords[length], min, max));
        }
    }

    return answer;
}