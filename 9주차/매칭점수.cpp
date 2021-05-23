#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// �ҹ��� ��ȯ
void trans(string& a) {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
}

// ���ĺ� �̿��� ���� ����
bool change(char c) {
    return c == '\'' || !isalpha(c);
}

// url ã�� (�����Ͽ���)
string getUrl(string page) {
    string url = "";

    string content = "<meta property=\"og:url\" content=\"https://";
    int contentIndex = page.find(content);
    int startContent = contentIndex + content.length();
    int endContent = page.substr(startContent).find("\"/>");
    url = page.substr(startContent, endContent);

    return url;
}

// �ܾ� ���� ����
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

// �ܺ� ��ũ ���ϱ� (�����Ͽ���)
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
    vector<string> urls;                    // url ����
    vector<int> baseScores;                 // �⺻���� ����
    vector<vector<string>> externalLinks;   // url�� �ɸ� ��ũ ����
    vector<double> externalScores;          // �ܺθ�ũ ���� ����
    vector<double> scores;                  // �� ���� ����

    int answer = 0;
    int i, j, k;

    // url ���� �� �ܾ� ��, �ܺ� ��ũ��, �ܺ� ��ũ ���� ���ϱ�
    for (i = 0; i < pages.size(); i++) {
        urls.push_back(getUrl(pages[i]));
        baseScores.push_back(getBaseScore(word, pages[i]));
        externalLinks.push_back(getExternalLink(pages[i]));

        if (externalLinks[i].size() != 0)
            externalScores.push_back((double)baseScores[i] / externalLinks[i].size());
        else
            externalScores.push_back(0.0);
    }

    // ��ũ ���� ���� (�ش� url�� �ٸ� ���������� ������ �߰�)
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

    // �� ���� ��
    double temp = scores[0];
    for (i = 1; i < scores.size(); i++) {
        if (temp < scores[i]) {
            answer = i;
            temp = scores[i];
        }
    }
    return answer;
}