#include <string>
#include <vector>

using namespace std;

// 오른쪽으로 90도 회전
void rotate(vector<vector<int>>& key) {
    int i, j;
    vector<vector<int>> temp(key.size(), vector<int>(key.size()));

    for (i = 0; i < key.size(); i++)
        for (j = 0; j < key[i].size(); j++)
            temp[i][j] = key[key.size() - j - 1][i];

    key = temp;
}

// 열 수 있는 체크 (90도씩 모두 회전)
bool check(vector<vector<int>> board, vector<vector<int>> key, int a, int b) {
    int i, j;
    int cnt = 0;
    int temp = 0;

    // key, lock size
    int m = key.size();
    int n = board.size() - (m - 1) * 2;

    // 오른쪽으로 90도씩 돌려서 맞는지 체크
    while (cnt < 4) {
        temp = 0;
        // key를 확장시킨 board에 맞춰보기
        for (i = a; i < a + m; i++) {
            for (j = b; j < b + m; j++)
                board[i][j] += key[i - a][j - b];
        }

        // lock이 모두 맞아들어가는지 체크
        for (i = m - 1; i < m + n - 1; i++) {
            for (j = m - 1; j < m + n - 1; j++) {
                if (board[i][j] == 1)
                    temp++;
            }
        }

        // 모두 맞는 경우
        if (temp == n * n)
            return true;

        // 안 맞는 경우 board 원래상태로 복구
        for (i = a; i < a + m; i++) {
            for (j = b; j < b + m; j++)
                board[i][j] -= key[i - a][j - b];
        }

        rotate(key);
        cnt++;
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    int M = key.size();
    int N = lock.size();
    int i, j;

    // board를 확장 (최대 2*(m-1)+n개)
    vector<vector<int>> board((M-1)*2+N, vector<int>((M-1)*2+N));

    // lock에 해당되는 지점 board에 채우기
    for (i = M - 1; i < M + N - 1; i++) {
        for (j = M - 1; j < M + N - 1; j++)
            board[i][j] = lock[i-M+1][j-M+1];
    }

    // 확장시킨 board부터 key를 맞춰보기 (true면 바로 return)
    for (i = 0; i < board.size() - M + 1; i++) {
        for (j = 0; j < board.size() - M + 1; j++) {
            if (check(board, key, i, j)) {
                answer = true;
                return answer;
            }
        }
    }

    return answer;
}