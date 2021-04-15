#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int, double>& a, const pair<int, double>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int* count = new int[N + 1];    // �� �ܰ躰 ��� �ο�
    double* rate = new double[N];   // �� �ܰ躰 ������
    multimap<int, double> m;
    int temp = stages.size();
    int i;

    // ���� �ʱ�ȭ
    for (i = 0; i < N + 1; i++)
        count[i] = 0;
    for (i = 0; i < N; i++)
        rate[i] = 0.0;

    // ����ο� ���
    for (i = 0; i < stages.size(); i++)
        count[stages[i] - 1]++;

    // ������ ��� (������ ��� / ���� ���)
    for (i = 0; i < N; i++) {
        // ���� ���� ���� ���
        if (temp == 0)
            rate[i] = 0.0;
        else {
            rate[i] = count[i] / (double)temp;
            temp -= count[i];
        }
    }

    // multimap�� ����
    for (i = 0; i < N; i++)
        m.insert(pair<int, double>(i+1, rate[i]));

    // ���� (����: key�� ������ value�� ������������ ����)
    vector<pair<int, double>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);
    
    // ���ĵ� Ű���� answer�� push
    for (auto num : vec)
        answer.push_back(num.first);

    return answer;
}