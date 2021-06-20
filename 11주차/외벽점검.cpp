#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(int n, vector<int> weak, vector<int> permut) {
    int i, j, k;
    int loc;
    vector<int> temp;

    // ���� ���� check
    for (i = 0; i < weak.size(); i++) {
        temp = weak;
        for (j = 0; j < permut.size(); j++) {
            loc = temp[0] + permut[j];

            while (1) {
                if (temp.size() == 0)
                    return true;
                if (temp[0] > loc)
                    break;
                temp.erase(temp.begin());
            }
        }
        // �������� ����� ���� ���� ���� �� �ڷ� ���� (n��ŭ ���ϱ�)
        weak.push_back(weak[0] + n);
        weak.erase(weak.begin());
    }

    return false;
}

int combi(int i, int n, vector<int> weak, vector<int> dist) {
    vector<int> combi;
    vector<vector<int>> permut;
    int k;
    int cnt = 0;

    // ���� �� �ִ� ���� �ֱ�
    while (i > 0) {
        if (i % 2 == 1)
            combi.push_back(dist[cnt]);
        i /= 2;
        cnt++;
    }

    sort(combi.begin(), combi.end());

    // ���� ����� (1���� ���� ��� ����x)
    if (combi.size() != 1) {
        vector<int> temp;
        do {
            for (k = 0; k < combi.size(); k++)
                temp.push_back(combi[k]);
            permut.push_back(temp);
            temp.clear();
        } while (next_permutation(combi.begin(), combi.end()));
    }
    else
        permut.push_back(combi);

    // ���� ���� �� �ϳ��� �����ϴ� ��� size ��ȯ
    for (k = 0; k < permut.size(); k++) {
        if (check(n, weak, permut[k]))
            return permut[k].size();
    }

    return -1;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 9;
    int temp;
    int i;

    for (i = 1; i < pow(2, dist.size()); i++) {
        // �����ϴ� ���� �ִ� ��� answer ���� (��, �ּ� ���ǿ� �°�)
        if (combi(i, n, weak, dist) != -1) {
            temp = combi(i, n, weak, dist);

            if (temp < answer)
                answer = temp;
        }
    }
    // ã���� ���� ���
    if (answer == 9)
        answer = -1;

    return answer;
}