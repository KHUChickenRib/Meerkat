#include <string>
#include <boost/algorithm/string.hpp>

using namespace std;

void trans(string& a) {
    boost::to_lower(a);
}

string solution(string new_id) {
    string answer = "";
    int i;

    trans(new_id);

    for (i = 0; new_id[i] != '\0'; i++) {
        if (new_id[i] == '.')
            continue;
        else if (new_id[i] == '-')
            continue;
        else if (new_id[i] == '_')
            continue;
        else if (isalpha(new_id[i]))
            continue;
        else if (isdigit(new_id[i]))
            continue;
        new_id.erase(new_id.begin() + i);
        i--;
    }

    for (i = 0; new_id[i] != '\0'; i++) {
        if (new_id[i] == '.' && new_id[i + 1] == '.') {
            new_id.erase(new_id.begin() + i);
            i--;
        }
    }

    for (i = 0; new_id[i] != '\0'; i++) {
        if ((i == 0 && new_id[i] == '.') || (i == new_id.length() - 1 && new_id[i] == '.')) {
            new_id.erase(new_id.begin() + i);
            i--;
        }
    }

    if (new_id.length() == 0)
        new_id += 'a';

    if (new_id.length() >= 16)
        new_id = new_id.substr(0, 15);
    if (new_id[new_id.length() - 1] == '.')
        new_id.erase(new_id.end() - 1);

    if (new_id.length() <= 2) {
        char temp = new_id[new_id.length() - 1];
        while (new_id.length() != 3)
            new_id += temp;
    }
    answer = new_id;

    return answer;
}