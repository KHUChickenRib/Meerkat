#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;

void trans(string& a, string& b) {
    transform(a.cbegin(), a.cend(), a.begin(), toupper);
    transform(b.cbegin(), b.cend(), b.begin(), toupper);
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int i, j;
    bool check = false;
    vector<string> cache;

    if (cacheSize == 0)
        return 5 * cities.size();

    for (i = 0; i < cities.size(); i++) {
        for (j = 0; j < cache.size(); j++) {
            trans(cities[i], cache[j]);
            if (cities[i] == cache[j]) {
                check = true;
                break;
            }
        }

        if (check) {
            answer += 1;

            cache.push_back(cities[i]);
            cache.erase(cache.begin() + j);
        }
        else {
            answer += 5;

            if (cache.size() < cacheSize)
                cache.push_back(cities[i]);
            else {
                cache.push_back(cities[i]);
                cache.erase(cache.begin());
            }

        }
        check = false;
    }

    return answer;
}