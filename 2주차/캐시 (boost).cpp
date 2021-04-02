#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;

void trans(string& a, string& b) {
    boost::to_upper(a);
    boost::to_upper(b);
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int i, j;
    bool check = false;
    bool stop = false;
    vector<string> cache;

    if (cacheSize == 0)
        return 5 * cities.size();

    for (i = 0; i < cacheSize; i++) {
        for (j = 0; j < i; j++) {
            trans(cities[i], cities[j]);
            if (cities[i] == cities[j]) {
                stop = true;
                break;
            }
        }
        if (stop)
            break;
        cache.push_back(cities[i]);
        answer += 5;
    }

    for (i = cache.size(); i < cities.size(); i++) {

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