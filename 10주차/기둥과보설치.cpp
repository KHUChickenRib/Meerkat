#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 정렬
bool cmp(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) {
        if (a[1] == b[1])
            return a[2] < b[2];
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

// 기둥 설치가능 여부
bool check_build_pillar(int a, int b, vector<vector<int>> answer) {
    int i;
    if (b == 0)
        return true;
    else {
        for (i = 0; i < answer.size(); i++) {
            // 보의 한쪽 끝 위
            if (answer[i][2] == 1 && answer[i][0] == a - 1 && answer[i][1] == b)
                return true;
            else if (answer[i][2] == 1 && answer[i][0] == a && answer[i][1] == b)
                return true;
            // 다른 기둥 위
            else if (answer[i][2] == 0 && answer[i][0] == a && answer[i][1] == b - 1)
                return true;
        }
    }
    return false;
}

// 보 설치가능 여부
bool check_build_paper(int a, int b, vector<vector<int>> answer) {
    int i;
    int cnt = 0;
    for (i = 0; i < answer.size(); i++) {
        // 한쪽 끝이 기둥 위
        if (answer[i][2] == 0 && answer[i][1] == b - 1 && answer[i][0] == a)
            return true;
        else if (answer[i][2] == 0 && answer[i][1] == b - 1 && answer[i][0] == a + 1)
            return true;

        // 양 옆 보가 존재
        if (answer[i][2] == 1 && answer[i][1] == b && answer[i][0] == a - 1)
            cnt++;
        else if (answer[i][2] == 1 && answer[i][1] == b && answer[i][0] == a + 1)
            cnt++;

        if (cnt == 2)
            return true;
    }
    return false;
}

// 삭제시 수행
void erase_element(int a, int b, int c, vector<vector<int>>& answer) {
    int i;

    for (i = 0; i < answer.size(); i++) {
        if (answer[i][0] == a && answer[i][1] == b && answer[i][2] == c) {
            swap(answer[i], answer[answer.size() - 1]);
            break;
        }
    }
    answer.pop_back();
}

// 지울 수 있는지 여부 확인 (남아있는 것들이 설치가 가능한지로 check)
bool check_eraseable(vector<vector<int>> answer) {
    int i;

    for (i = 0; i < answer.size(); i++) {
        if (answer[i][2] == 0) {
            if (!check_build_pillar(answer[i][0], answer[i][1], answer))
                return false;
        }
        else {
            if (!check_build_paper(answer[i][0], answer[i][1], answer))
                return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    int i, j;

    for (i = 0; i < build_frame.size(); i++) {
        // 설치
        if (build_frame[i][3] == 1) {
            // 기둥 설치
            if (build_frame[i][2] == 0) {
                if (check_build_pillar(build_frame[i][0], build_frame[i][1], answer))
                    answer.push_back({ build_frame[i][0], build_frame[i][1], build_frame[i][2] });
            }
            // 보 설치
            else {
                if (check_build_paper(build_frame[i][0], build_frame[i][1], answer))
                    answer.push_back({ build_frame[i][0], build_frame[i][1], build_frame[i][2] });
            }
        }
        // 삭제
        else {
            erase_element(build_frame[i][0], build_frame[i][1], build_frame[i][2], answer);

            // 삭제가 안되면 다시 설치
            if (!check_eraseable(answer)) {
                answer.push_back({ build_frame[i][0], build_frame[i][1], build_frame[i][2] });
            }
        }
    }

    sort(answer.begin(), answer.end(), cmp);

    return answer;
}