#include <string>
#include <vector>

using namespace std;

// board 스캔
vector<vector<int>> scan_board(int m, int n, vector<string> board) {
    int i, j;
    vector<vector<int>> result(m, vector<int>(n, 0));

    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            // 알파벳 체크 (참고로 대문자는 1을 return)
            if (isalpha(board[i][j]) == 0)
                continue;
            // 4개 인접 블록 체크
            if (board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j]
                && board[i][j] == board[i + 1][j + 1]) {
                result[i][j] = 1;
                result[i + 1][j] = 1;
                result[i][j + 1] = 1;
                result[i + 1][j + 1] = 1;
            }
        }
    }
    return result;
}

// 지워야 하는 블록 카운팅
int count_board(int m, int n, vector<string> board) {
    int i, j;
    vector<vector<int>> cnt(m, vector<int>(n, 0));
    int result = 0;

    cnt = scan_board(m, n, board);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (cnt[i][j] == 1)
                result++;
        }
    }
    return result;
}

// board update
void update_board(int m, int n, vector<string>& board) {
    int i, j, k;
    vector<vector<int>> cnt(m, vector<int>(n, 0));

    // 1차적으로 먼저 스캔 선행
    cnt = scan_board(m, n, board);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (cnt[i][j] == 1) {
                // 맨 윗줄
                if (i == 0)
                    board[0][j] = -1;
                // 나머지는 위에서 내리기
                for (k = i; k > 0; k--) {
                    board[k][j] = board[k - 1][j];
                    board[k - 1][j] = ' ';
                }
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int temp;

    while (1) {
        temp = count_board(m, n, board);

        if (temp == 0)
            break;
        else
            update_board(m, n, board);

        answer += temp;
    }
    return answer;
}