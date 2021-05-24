#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// 소문자 변환
void trans(string& a) {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
}

// 알파벳 이외의 문자 변경
bool change(char c) {
    return c == '\'' || !isalpha(c);
}

// url 찾기 (참고하였음)
string getUrl(string page) {
    string url = "";

    string content = "<meta property=\"og:url\" content=\"https://";
    int contentIndex = page.find(content);
    int startContent = contentIndex + content.length();
    int endContent = page.substr(startContent).find("\"/>");
    url = page.substr(startContent, endContent);

    return url;
}

// 단어 갯수 세기
int getBaseScore(string word, string page) {
    int score = 0;

    trans(word);
    trans(page);

    replace_if(page.begin(), page.end(), change, ' ');

    istringstream ss(page);
    string buffer;

    while (getline(ss, buffer, ' ')) {
        if (buffer == word)
            score++;
    }

    return score;
}

// 외부 링크 구하기 (참고하였음)
vector<string> getExternalLink(string page) {
    vector<string> result;

    string href = "<a href=\"https://";
    int startHref = page.find(href);

    while (startHref != -1)
    {
        int hrefStart = startHref + href.size();
        int hrefEnd = page.substr(hrefStart).find("\">");
        result.push_back(page.substr(hrefStart, hrefEnd));
        startHref = page.find(href, hrefStart + hrefEnd);
    }

    return result;
}

int solution(string word, vector<string> pages) {
    vector<string> urls;                    // url 저장
    vector<int> baseScores;                 // 기본점수 저장
    vector<vector<string>> externalLinks;   // url에 걸린 링크 저장
    vector<double> externalScores;          // 외부링크 점수 저장
    vector<double> scores;                  // 총 점수 저장

    int answer = 0;
    int i, j, k;

    // url 조사 및 단어 수, 외부 링크수, 외부 링크 점수 구하기
    for (i = 0; i < pages.size(); i++) {
        urls.push_back(getUrl(pages[i]));
        baseScores.push_back(getBaseScore(word, pages[i]));
        externalLinks.push_back(getExternalLink(pages[i]));

        if (externalLinks[i].size() != 0)
            externalScores.push_back((double)baseScores[i] / externalLinks[i].size());
        else
            externalScores.push_back(0.0);
    }

    // 링크 점수 조사 (해당 url이 다른 웹페이지에 있으면 추가)
    for (i = 0; i < urls.size(); i++) {
        double score = baseScores[i];
        for (j = 0; j < externalLinks.size(); j++) {
            for (k = 0; k < externalLinks[j].size(); k++) {
                if (urls[i] == externalLinks[j][k]) {
                    score += externalScores[j];
                    break;
                }
            }
        }
        scores.push_back(score);
    }

    // 총 점수 비교
    double temp = scores[0];
    for (i = 1; i < scores.size(); i++) {
        if (temp < scores[i]) {
            answer = i;
            temp = scores[i];
        }
    }
    return answer;
}